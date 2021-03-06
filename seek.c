/****************************seek.c******************************************

						Will Childs-Klein

	The algorithm used in this problem involves recursively (in concept, 
	not implementation) breaking down the plane into families of 4 boxes with 
	no more than k points in a given box. In other words, if a given box has
	> k points within its borders (inclusive), we form 4 equally-sized sub-
	boxes within it and apply the same process. Doing this, we build a quad-
	tree with each node's child being one of its 4 sub-box children. We store
	this quad-tree as an array of structs. Each node has included in its 
	struct the index of both its parent and its children in the quad-tree array
	(child = -1 in case of leaf node, parent = root in case of root node).
	After building the tree, we traverse it starting at the root node, first 
	finding the leaf node that directly contains the point. We then "draw" a 
	circle with that circle's center being the current point, and its radius 
	being the destance between the current point and the furthest corner of the
	leaf node's parent box (in case of root, parent:=root). We then aggregate 
	all the sub_n points within the bounds of this circle and feed them into 
	seek_naive, which uses a linear scan of O(sub_n^2) complexity to find the 
	the current point's closest k neighbors. We repeat this process for all n 
	points.

	This algorithm should result in a massive speedup compared to the linear
	scan method, but my implementation fails to do so. I have been working I on
	resolving this issue for the last few days, have been unable to
	accurately find the source of this unintended latency, but I know that it
	is in the traversal of the tree (the building phase happens rather quickly).
	When it does finally finish though, the output is accurate.

****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <time.h>

#define INT_MAX (pow(2, 64))
#define REALLY_BIG_NUMBER (1000000)

typedef struct point {
	double x;
	double y;
	int index;
} Point;

typedef struct box {
	// index of this Box in quad tree.
	int index;

	// points of corners
	struct point ll_corner;
	struct point ur_corner;

	// start and end indices of box within permutation array.
	// [perm_start, perm_end) ie, start inclusive, end is index_of_last_elt+1.
	int perm_start;
	int perm_end;

	// indices of children and parent nodes in perm array...-1 if null.
	int c1, c2, c3, c4;
	int parent;

	// non-zero iff all work for this box is completed in construction of quadtree
	// checked after perm array sorted and children created.
	int check;
} Box;

void seek(double* a, int n, int k, int* iz);
int circle_box_intersect(Point p, double radius, Box b);
double gen_radius(Point p, Box *curr, Box **qtree);
double furthest_corner_distance(Point p, Box b);
void build_tree(Point* points, Box*** qtree, int* qtreeSize, int* perm, int n, int k);
void sort(int* perm, Point* points, int start, int end, int* indexes, Box c1, Box c2, Box c3, Box c4);
int point_in_box(Point p, Box b);
void printBox(Box *b);
void printIntArr(int n, int *arr);
void seek_naive2(double* a, int n, int k, int* iz);
void seek_naive(double* a, int n, int k, int* iz);
void insert(Point* arr, Point initial, Point test, int k);
void initPointArr(Point* arr, int k);
int pointEquals(Point p, Point q);
double distance(double x1, double y1, double x2, double y2);
double pointDistance(Point p, Point q);

void seek_helper(Point *a, int n, int start,  int end, const int k, int *iz, double *n_dist, int pos);
time_t tree_built;
int (*cmp)(const void *keyval, const void *datum);

void seek(double* a, int n, int k, int* iz){
	int i, j, h, *qtreeSize, *perm, currIndex, travIndex, *mapping, *sub_iz, sub_n, sub_k, sub_aIndex;
	double radius, *sub_a, tempx, tempy;
	Box **qtree, *curr, **trav;
	Point temp, *points, p, *restricted_points;

	// make points easier to work with.
	points = malloc(n * sizeof(Point));
	for(i = 0; i < 2*n; i+=2){
		temp.x = a[i];
		temp.y = a[i+1];
		temp.index = i/2;
		points[i/2] = temp;
	}

	// init permutation array
	perm = malloc(n * sizeof(int));
	for(i = 0; i < n; i++){
		perm[i] = i;
	}

	// build quad tree
	qtreeSize = malloc(sizeof(int));
	*qtreeSize = 100000;
	qtree = calloc(*qtreeSize, sizeof(Box*));
	build_tree(points, &qtree, qtreeSize, perm, n, k);

	// deeeleeetteee
	tree_built = clock();

	// traverse quad tree for each point.
	for(i = 0; i < n; i++){
		p = points[i];
		curr = qtree[0];
		currIndex = 0;
		// find smallest box (leaf) that holds point.
		while(1){
			if(curr->c1 < 0)
				break;
			else if(point_in_box(p, *(qtree[curr->c1])))
				currIndex = curr->c1;
			else if(point_in_box(p, *(qtree[curr->c2])))
				currIndex = curr->c2;
			else if(point_in_box(p, *(qtree[curr->c3])))
				currIndex = curr->c3;
			else if(point_in_box(p, *(qtree[curr->c4])))
				currIndex = curr->c4;
			curr = qtree[currIndex];
		}

		//generate circle radius, center is Point p.
		radius = gen_radius(p, curr, qtree);

		// init traversal array to all NULL ptrs
		trav = calloc(*qtreeSize, sizeof(Box*));
		travIndex = 1; // index of last element in trav + 1.
		trav[0] = qtree[0];

		// generate sparse arr with only ptrs to leaf's intsct w/ circle
		for(j = 0; j < travIndex; j++){
			if(trav[j]->c1 > -1){ // not a leaf
				trav[travIndex] = qtree[trav[j]->c1];
				trav[travIndex+1] = qtree[trav[j]->c2];
				trav[travIndex+2] = qtree[trav[j]->c3];
				trav[travIndex+3] = qtree[trav[j]->c4];
				travIndex += 4;
				trav[j] = NULL;
			}
			// if box and circle don't overlap, set current ptr to NULL
			else if(!circle_box_intersect(p, radius, *(trav[j]))){
				trav[j] = NULL;
			}
		}

		// compile points from pertinent leafs
		mapping = malloc(n * sizeof(int));
		sub_n = 0;
		sub_a = malloc(2*n * sizeof(double));
		sub_aIndex = 0;
		for(j = 0; j < travIndex; j++){
			if(trav[j]){
				for(h = trav[j]->perm_start; h < trav[j]->perm_end; h++){
					sub_a[sub_aIndex++] = (points[perm[h]]).x;
					sub_a[sub_aIndex++] = (points[perm[h]]).y;
					mapping[sub_n] = perm[h];
					sub_n++;
				}
			}
		}
		sub_iz = malloc(sub_n*k * sizeof(int));

		// printf("n = %d\n", sub_n);

		seek_naive(sub_a, sub_n, k, sub_iz);

		// put pertinent part of sub_iz into iz. for seek_naive
		for(j = 0; j < 2*sub_n; j+=2){
			if(sub_a[j] == p.x && sub_a[j+1] == p.y){ // got it.
				for(h = 0; h < k; h++){
					iz[i*k+h] = mapping[sub_iz[(j/2)*k+h]-1];
				}
				break;
			}
		}

		free(trav);
		free(sub_a);
		free(sub_iz);
		free(mapping);
	}

	// REMEMBER TO INCREMENT INDICES WHEN FINISHED DEVELOPING
	for(i = 0; i < k*n; i++){
		iz[i]++; 
	}

	for(i = 0; i < *qtreeSize; i++){
		if(qtree[i] != NULL)
			free(qtree[i]);
	}
	free(qtree);
	free(qtreeSize);
	free(perm);
	free(points);
}

int circle_box_intersect(Point p, double r, Box b){
	double ulDist, urDist, llDist, lrDist, maxDist;
	Point ul_corner, lr_corner;

	ul_corner.x = b.ll_corner.x;
	ul_corner.y = b.ur_corner.y;
	lr_corner.x = b.ur_corner.x;
	lr_corner.y = b.ll_corner.y;

	ulDist = pointDistance(p, ul_corner);
	urDist = pointDistance(p, b.ur_corner);
	llDist = pointDistance(p, b.ll_corner);
	lrDist = pointDistance(p, lr_corner);

	// case 1: >= 1 corner of b inside circle. 
	if(fmax(ulDist, fmax(urDist, fmax(llDist, lrDist))) <= r){
		return 1;
	}
	// case 2: no corners in circle, edge intersects w/ circle >= once
	else if(((ul_corner.x <= p.x && p.x <= b.ur_corner.x) && (fabs(ul_corner.y - p.y) <= r)) ||
		((b.ll_corner.x <= p.x && p.x <= lr_corner.x) && (fabs(b.ll_corner.y - p.y) <= r)) ||
		((ul_corner.y >= p.y && p.y >= b.ll_corner.y) && (fabs(ul_corner.x - p.x) <= r)) ||
		((b.ur_corner.y >= p.y && p.y >= lr_corner.y) && (fabs(b.ur_corner.x - p.x) <= r))){
		return 1;
	}
	// case 4: no cigar...not possible for circle in box.
	else{
		return 0;
	}
}

double gen_radius(Point p, Box *curr, Box **qtree){
	double ulDist, urDist, llDist, lrDist, maxDist;
	Point ul_corner, lr_corner;
	Box *b;

	b = qtree[curr->parent];

	ul_corner.x = b->ll_corner.x;
	ul_corner.y = b->ur_corner.y;
	lr_corner.x = b->ur_corner.x;
	lr_corner.y = b->ll_corner.y;

	ulDist = pointDistance(p, ul_corner);
	urDist = pointDistance(p, b->ur_corner);
	llDist = pointDistance(p, b->ll_corner);
	lrDist = pointDistance(p, lr_corner);

	return fmax(ulDist, fmax(urDist, fmax(llDist, lrDist)));
}

void build_tree(Point* points, Box*** qtree, int* qtreeSize, int* perm, int n, int k){
	int i, currIndex, maxIndex, minIndex, numPointsInBox, *indexes;
	Box *curr, *root, **temp;

	// init root node
	root = malloc(sizeof(Box));
	root->ur_corner.x = 1;
	root->ur_corner.y = 1;
	root->ll_corner.x = 0;
	root->ll_corner.y = 0;
	root->perm_start = 0;
	root->perm_end = n;
	root->parent = 0;
	root->check = 0;
	root->index = 0;
	(*qtree)[0] = root;

	currIndex = 0;
	maxIndex = 0;
	minIndex = 0; // keep at zero now, but find way to make dynamic to get speed-up.


	while(currIndex >= 0){
		if(maxIndex > (*qtreeSize)-10){ // make qtree bigger if need be.
			(*qtreeSize) *= 2;
			temp = calloc(*qtreeSize, sizeof(Box*));
			for(i = 0; i < maxIndex+4; i++){
				temp[i] = (*qtree)[i];
			}
			free(*qtree);
			*qtree = temp;
			//printf("realloc'd!!\n");
		}

		currIndex = -1;

		// look if there are any unchecked boxes.
		for(i = minIndex; i < maxIndex+1; i++){
			minIndex = i; 
			if((*qtree)[i]->check == 0){
				currIndex = i;
				curr = (*qtree)[i];
				break;
			}
		}
		
		// bust out the kidses
		if(curr->perm_end - curr->perm_start > k){
			Box *c1, *c2, *c3, *c4;
			c1 = malloc(sizeof(Box));
			c2 = malloc(sizeof(Box));
			c3 = malloc(sizeof(Box));
			c4 = malloc(sizeof(Box));
			c1->c1=c1->c2=c1->c3=c1->c4= -1;
			c2->c1=c2->c2=c2->c3=c2->c4= -1;
			c3->c1=c3->c2=c3->c3=c3->c4= -1;
			c4->c1=c4->c2=c4->c3=c4->c4= -1;

			// init check values
			c1->check = c2->check = c3->check = c4->check = 0;

			// assign parent val.
			c1->parent = c2->parent = c3->parent = c4->parent = currIndex;

		
			// determine boundaries of children
			c1->ll_corner.x = curr->ll_corner.x;
			c1->ll_corner.y = curr->ll_corner.y+((curr->ur_corner.y - curr->ll_corner.y)/2);
			c1->ur_corner.x = curr->ll_corner.x+((curr->ur_corner.x - curr->ll_corner.x)/2);
			c1->ur_corner.y = curr->ur_corner.y;

			c2->ll_corner.x = curr->ll_corner.x+((curr->ur_corner.x - curr->ll_corner.x)/2);
			c2->ll_corner.y = curr->ll_corner.y+((curr->ur_corner.y - curr->ll_corner.y)/2);
			c2->ur_corner.x = curr->ur_corner.x;
			c2->ur_corner.y = curr->ur_corner.y;

			c3->ll_corner.x = curr->ll_corner.x;
			c3->ll_corner.y = curr->ll_corner.y;
			c3->ur_corner.x = curr->ll_corner.x+((curr->ur_corner.x - curr->ll_corner.x)/2);
			c3->ur_corner.y = curr->ll_corner.y+((curr->ur_corner.y - curr->ll_corner.y)/2);

			c4->ll_corner.x = curr->ll_corner.x+((curr->ur_corner.x - curr->ll_corner.x)/2);
			c4->ll_corner.y = curr->ll_corner.y;
			c4->ur_corner.x = curr->ur_corner.x;
			c4->ur_corner.y = curr->ll_corner.y+((curr->ur_corner.y - curr->ll_corner.y)/2);

			indexes = calloc(5, sizeof(int));
			
			sort(perm, points, curr->perm_start, curr->perm_end, indexes, *c1, *c2, *c3, *c4);

			// assign children start and end indexes in perm array
			c1->perm_start = indexes[0];
			c1->perm_end = indexes[1];
			c2->perm_start = indexes[1];
			c2->perm_end = indexes[2];
			c3->perm_start = indexes[2];
			c3->perm_end = indexes[3];
			c4->perm_start = indexes[3];
			c4->perm_end = indexes[4];//curr->perm_end;

			//printf("%d %d\n", maxIndex, *qtreeSize);
			(*qtree)[maxIndex+1] = c1;
			(*qtree)[maxIndex+2] = c2;
			(*qtree)[maxIndex+3] = c3;
			(*qtree)[maxIndex+4] = c4;

			curr->c1 = c1->index = maxIndex+1;
			curr->c2 = c2->index = maxIndex+2;
			curr->c3 = c3->index = maxIndex+3;
			curr->c4 = c4->index = maxIndex+4;

			maxIndex += 4;

			free(indexes);
		}

		if(currIndex >= 0){ // box has been dealt with.
			curr->check = 1;
		}
	}

	return;
}

// indexes[0] is start of c1, indexes[1] start of c2, [2] start c3 etc
// points ll and ur gives dimensions of box to split into children and sort.
void sort(int* perm, Point* points, int start, int end, int* indexes, Box c1, Box c2, Box c3, Box c4){
	int *c1_arr, *c2_arr, *c3_arr, *c4_arr, c1ind, c2ind, c3ind, c4ind, i, indSum;
	c1ind = c2ind = c3ind = c4ind = 0;

	c1_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c2_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c3_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c4_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));

	for(i = start; i < end; i++){
		// need else if's otherwise pts included twice.
		if(point_in_box(points[perm[i]], c1)){
			c1_arr[c1ind++] = perm[i];
		}
		else if(point_in_box(points[perm[i]], c2)){
			c2_arr[c2ind++] = perm[i];
		}
		else if(point_in_box(points[perm[i]], c3)){
			c3_arr[c3ind++] = perm[i];
		}
		else if(point_in_box(points[perm[i]], c4)){
			c4_arr[c4ind++] = perm[i];
		}
		else{
			printf("WHOA THERE THE SORT FUNCTION FUCKED UP!\n");
			exit(1);
		}
	}

	indexes[0] = i = start;
	indSum = start;
	if(c1ind > 0){
		indSum += c1ind;
		for(; i < indSum; i++)
			perm[i] = c1_arr[i-start];
	}

	indexes[1] = i; 
	if(c2ind > 0){
		indSum += c2ind;
		for(; i < indSum; i++)
			perm[i] = c2_arr[i-c1ind-start];
	}

	indexes[2] = i;
	if(c3ind > 0){
		indSum += c3ind;
		for(; i < indSum; i++)
			perm[i] = c3_arr[i-c1ind-c2ind-start];
	}

	indexes[3] = i;
	if(c4ind > 0){
		indSum += c4ind;
		for(; i < indSum; i++)
			perm[i] = c4_arr[i-c1ind-c2ind-c3ind-start];
	}
	indexes[4] = i;

	free(c1_arr);
	free(c2_arr);
	free(c3_arr);
	free(c4_arr);

	return;
}

int point_in_box(Point p, Box b){ // includes points on borders
	return p.x >= b.ll_corner.x && p.y >= b.ll_corner.y &&
		p.x <= b.ur_corner.x && p.y <= b.ur_corner.y;
}


void printBox(Box *b){
	printf("ll_corner: [%f, %f]\n", b->ll_corner.x, b->ll_corner.y);
	printf("ur_corner: [%f, %f]\n", b->ur_corner.x, b->ur_corner.y);
	printf("perm_start: %d, perm_end: %d\n", b->perm_start, b->perm_end);
	printf("check: %d\n", b->check);
	printf("parent: %d\n", b->parent);
	printf("index: %d\n", b->index);
	printf("children: [%d, %d, %d, %d]\n", b->c1, b->c2, b->c3, b->c4);
}

void printIntArr(int n, int *arr){
	int i;
	printf("[");
	for(i = 0; i < n; i++){
		printf("%d,", arr[i]);
	}
	printf("]\n");
	return;
}

// Aayush's...
void seek_naive(double *a, int n, int k, int *iz) {

  Point *pt_arr = malloc(sizeof(Point)*n);
  int i, j, pe = 0;
  double n_dist[k];

  // build up the array of points
  for (i = 0; i < n; i++) {
      pt_arr[i].x = a[2*i];
      pt_arr[i].y = a[2*i+1];
      pt_arr[i].index = i;
  }
  for (i = 0; i < n; i++) { 
    //initialize neighbors and distances to -1.0
    memset(n_dist, 0.0, k*sizeof(double));

    pe += n; //points examined, just for debugging
    seek_helper(pt_arr, n, 0, n, k, iz, n_dist, i);

    //keep em ordered for testing
    qsort(&iz[k*i], k, sizeof(int), cmp);
  }
}

int (*cmp)(const void *keyval, const void *datum){
	if(*keyval < *datum)
		return -1;
	else if(*keyval > *datum)
		return 1;
	else
		return 0;
}

/*
 * a = array of neighbor points
 * n = number of points in the array
 * start = where to start looking
 * end = where to stop looking
 * k = neighbor size
 * iz = results
 * pos = which point to consider in a
 */
void seek_helper(Point *a, int n, int start,  int end, const int k, int *iz, double *n_dist, int pos) {

    int i,j,z, c_index = 0, id = 0, curr_id = 0;
    double x1=0,y1=0, x2=0, y2=0; 
    double dist = 0.0, cand_dist = 0.0;

    //current point
    x1 = a[pos].x, y1 = a[pos].y, curr_id = a[pos].index;
    //printf("point is (%f, %f)\n", x1, y1);

    //printf("currently examining %f, %f\n", x1, y1);

    for (j = start; j < end; j++) {
        //current neighbor
        x2 = a[j].x, y2=a[j].y, id = a[j].index;
        //this is us
        if (id == curr_id)
            continue;
     //   printf("current neighbor %f, %f, id:%d\n", x2, y2, id);

        //get the distance
        dist = distance(x1,y1,x2,y2);
      //  printf("distance %f\n", dist);

        //this is the index we want to swap with our curr_point
        c_index = -1;

        //loop through, find the furthest away point, replace w/ us
        for (z = 0; z < k; z++) {

            if (!n_dist[z]) { //nothing here, so update and leave 
                c_index = z; 
                break;
            }

            //we're closer than this guy 
            if (dist < n_dist[z]) {

                //AND this point is bigger than our prev point
                if (c_index == -1 || n_dist[c_index] < n_dist[z])
                    c_index = z;
                  //  printf("YUP, it's closer\n");
            }
        }

        if (c_index != -1) {
          iz[k*curr_id+c_index] = id;
          n_dist[c_index] = dist;
        }
    }
}

// call within seek function?
// void seek_naive(double* a, int n, int k, int* iz){
// 	int i, j;
// 	Point temp, *points, *closest, *ret, initial, test;
// 	ret = calloc(n*k, sizeof(Point));

// 	// put points into structure that's easier to work with.
// 	points = malloc(n * sizeof(Point));
// 	for(i = 0; i < 2*n; i+=2){
// 		temp.x = a[i];
// 		temp.y = a[i+1];
// 		temp.index = i/2;
// 		points[i/2] = temp;
// 	}

// 	// find closest points
// 	for(i = 0; i < n; i++){
// 		closest = malloc(k * sizeof(Point));
// 		initPointArr(closest, k);
// 		initial = points[i];
// 		for(j = 0; j < n; j++){
// 			test = points[j];
// 			if(!pointEquals(initial, test)){
// 				insert(closest, initial, test, k);
// 			}
// 		}
// 		// update ret.
// 		for(j = 0; j < k; j++)
// 			ret[i*k+j] = closest[j];
// 		free(closest);
// 	}

// 	// put points back into iz
// 	for(i = 0; i < k*n; i++){
// 		iz[i] = (ret[i]).index;
// 		iz[i]++; // increment because specs want index base 1. 
// 	}

// 	free(ret);
// 	free(points);
// 	return;	
// }

void seek_naive2(double* a, int n, int k, int* iz){
	int i, j;
	Point temp, *points, *closest, *ret, initial, test;
	ret = calloc(n*k, sizeof(Point));

	// put points into structure that's easier to work with.
	points = malloc(n * sizeof(Point));
	for(i = 0; i < 2*n; i+=2){
		temp.x = a[i];
		temp.y = a[i+1];
		temp.index = i/2;
		points[i/2] = temp;
	}

	// find closest points
	i = 0;
	//for(i = 0; i < n; i++){
		closest = malloc(k * sizeof(Point));
		initPointArr(closest, k);
		initial = points[i];
		for(j = 0; j < n; j++){
			test = points[j];
			if(!pointEquals(initial, test)){
				insert(closest, initial, test, k);
			}
		}
		// update ret.
		for(j = 0; j < k; j++)
			ret[i*k+j] = closest[j];
		free(closest);
	//}

	// put points back into iz
	for(i = 0; i < k; i++){
		iz[i] = (ret[i]).index;
		iz[i]++; // increment because specs want index base 1. 
	}

	free(ret);
	free(points);
	return;	
}

void insert(Point* arr, Point initial, Point test, int k){
	int i, lrgst_index;
	double lrgst_dist;
	Point curr;
	lrgst_index = -1;
	lrgst_dist = 0;
	for(i = 0; i < k; i++){
		curr = arr[i];
		// empty space? if so, immediately replace and return.
		if(curr.index < 0){
			arr[i] = test;
			return;
		}

		if(pointDistance(initial, curr) > lrgst_dist){
			lrgst_dist = pointDistance(initial, curr);
			lrgst_index = i;
		}
	}
	 
	if(pointDistance(initial, test) < lrgst_dist)
		arr[lrgst_index] = test;

	return;
}

void initPointArr(Point* arr, int k){
	Point p;
	p.x = 0;
	p.y = 0;
	p.index = -1;
	int i;
	for(i = 0; i < k; i++){
		arr[i] = p;
	}
	return;
}

int pointEquals(Point p, Point q){
	return p.x == q.x && p.y == q.y;
}


double pointDistance(Point p, Point q){
	return distance(p.x, p.y, q.x, q.y);
}

double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
	int n, k, *iz, i, j;
	double *a;

	time_t pre_seek, post_seek, pre_seek_naive, post_seek_naive;

	double small_a[24] = {.2, .2, .3, .3, .45, .45, .1, .1, .9, .9, .8, .8, .7, .3, .2, .6, .85, .85, .4, .4, .5, .5, 1, 1};
	// double a[40] = {.2, .3, .4, .5, .6, .7, .8, .9, .1, 1, 1, 1, .3, .6, .3, .7, .2, .8, .4, .9, .2, .3, .4, .5, .6, .7, .8, .9, .1, 1, 1, 1, .3, .6, .3, .7, .2, .8, .4, .9};
	n = 12;
	k = 3;
	iz = malloc(n*k * sizeof(int));

	for(i = 0; i < 2*n; i++){
		small_a[i] = ((double) rand() / (RAND_MAX));
	}
	
	seek(small_a, n, k, iz);

	for(i = 0; i < n; i++){
		printf("(%d)[%f, %f]: ", i+1, small_a[2*i], small_a[2*i+1]);
		for(j = 0; j < k; j++){
			printf("%d, ", iz[i*k+j]);
		}
		printf("\n");
	}printf("\n");

	seek_naive(small_a, n, k, iz);

	for(i = 0; i < n; i++){
		printf("(%d)[%f, %f]: ", i+1, small_a[2*i], small_a[2*i+1]);
		for(j = 0; j < k; j++){
			printf("%d, ", iz[i*k+j]);
		}
		printf("\n");
	}

	free(iz);

	for(n = 10; n <= 100000; n *= 10){
		a = malloc((2*n) * sizeof(double));
		k = 3;
		iz = malloc(n*k * sizeof(int));

		for(i = 0; i < 2*n; i++){
			a[i] = ((double) rand() / (RAND_MAX));
		}

		pre_seek = clock();
		seek(a, n, k, iz);
		post_seek = clock();

		pre_seek_naive = clock();
		seek_naive(a, n, k, iz);
		post_seek_naive = clock();

		printf("for n = %d\n", n);
		printf("seek: %f\n", difftime(post_seek, pre_seek)/1000000);
		printf("seek_naive: %f\n", difftime(post_seek_naive, pre_seek_naive)/1000000);
		printf("ratio seek/seek_naive = %f\n", difftime(post_seek, pre_seek) / difftime(post_seek_naive, pre_seek_naive));
		printf("tree built in %f seconds\n", difftime(tree_built, pre_seek)/1000000);
		printf("\n");

		free(iz);
		free(a);
	}

	return 0;
}