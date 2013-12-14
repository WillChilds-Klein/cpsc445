#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

 #define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))

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
void build_tree(Point* points, Box** qtree, int* qtreeSize, int* perm, int n, int k);
void sort(int* perm, Point* points, int start, int end, int* indexes, Box c1, Box c2, Box c3, Box c4);
int point_in_box(Point p, Box b);
void printBox(Box *b);
void printIntArr(int n, int *arr);
void seek_naive(double* a, int n, int k, int* iz);
void insert(Point* arr, Point initial, Point test, int k);
void initPointArr(Point* arr, int k);
int pointEquals(Point p, Point q);
double distance(double x1, double y1, double x2, double y2);
double pointDistance(Point p, Point q);

int main(){
	int n, k, *iz, i, j;

	n = 12;
	k = 3;
	iz = malloc(n*k * sizeof(int));

	double a[24] = {.2, .2, .3, .3, .45, .45, .1, .1, .9, .9, .8, .8, .7, .3, .2, .6, .85, .85, .4, .4, .5, .5, 1, 1};

	seek(a, n, k, iz);

	for(i = 0; i < n; i++){
		printf("(%d)[%f, %f]: ", i+1, a[2*i], a[2*i+1]);
		for(j = 0; j < k; j++){
			printf("%d, ", iz[i*k+j]);
		}
		printf("\n");
	}
	printf("\n");


	iz = malloc(n*k * sizeof(int));
	seek_naive(a, n, k, iz);

	for(i = 0; i < n; i++){
		printf("(%d)[%f, %f]: ", i+1, a[2*i], a[2*i+1]);
		for(j = 0; j < k; j++){
			printf("%d, ", iz[i*k+j]);
		}
		printf("\n");
	}

	free(iz);
	return 0;
}

void seek(double* a, int n, int k, int* iz){
	int i, j, h, *qtreeSize, *perm, currIndex, travIndex, *mapping, *sub_iz, sub_n, sub_k, sub_aIndex;
	double radius, *sub_a;
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
	*qtreeSize = 5000;
	qtree = calloc(*qtreeSize, sizeof(Box*));
	build_tree(points, qtree, qtreeSize, perm, n, k);

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
		printf("point %d [%f, %f] is in box at index %d of qtree\n", i, p.x, p.y, currIndex);

		//generate circle radius, center is Point p.
		radius = gen_radius(p, curr, qtree);
		printf("radius: %f\n", radius);

		// init traversal array to all NULL ptrs
		trav = calloc(*qtreeSize, sizeof(Box*));
		travIndex = 1; // index of last element in trav + 1.
		trav[0] = qtree[0];

		// generate sparse arr with only ptrs to leaf's intsct w/ circle
		for(j = 0; j < travIndex; j++){
			//printf("build trav iter: %d\n", j);
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
		printf("travIndex: %d, trav: [", travIndex);
		for(j = 0; j < travIndex; j++){
			if(trav[j])
				printf("%d,", trav[j]->index);
		}printf("]\n");

		// compile points from pertinent leafs
		mapping = malloc(n * sizeof(int));
		sub_n = 0;
		sub_a = malloc(2*n * sizeof(double));
		sub_aIndex = 0;
		for(j = 0; j < travIndex; j++){
			if(trav[j]){
				for(h = trav[j]->perm_start; h < trav[j]->perm_end; h++){
					sub_a[sub_aIndex++] = points[perm[h]].x;
					sub_a[sub_aIndex++] = points[perm[h]].y;
					mapping[sub_n] = perm[h];
					sub_n++;
				}
			}
		}
		sub_iz = malloc(sub_n*k * sizeof(int));
		printf("sub_n: %d, sub_a: [", sub_n);
		for(j = 0; j < 2*sub_n; j++){
			printf("%f,", sub_a[j]);
		}printf("]\n");
		// call seek_naive
		seek_naive(sub_a, sub_n, k, sub_iz);

		printf("sub_n: %d, sub_iz: [", sub_n);
		for(j = 0; j < k*sub_n; j++){
			printf("%d,", sub_iz[j]);
		}printf("]\n");

		printf("mapping: [");
		for(j = 0; j < sub_n; j++){
			printf("%d,", mapping[j]);
		}printf("]\n");

		// put pertinent part of sub_iz into iz.
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
		iz[i]++; // increment because specs want index base 1. IMPORTANT *********************************************
	}

	for(i = 0; i < *qtreeSize; i++){
		if(qtree[i] != NULL)
			free(qtree[i]);
	}
	free(qtree);
	free(qtreeSize);
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
		printf("heyheyhey BOX: %d\n", b.index);
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

void build_tree(Point* points, Box** qtree, int* qtreeSize, int* perm, int n, int k){
	int i, currIndex, maxIndex, minIndex, numPointsInBox, *indexes;
	Box *curr, *root;

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
	qtree[0] = root;

	currIndex = 0;
	maxIndex = 0;
	minIndex = 0; // keep at zero now, but find way to make dynamic to get speed-up.

	int incr = 7;

	while(/*incr-- > 0){*/currIndex >= 0){//!done(qtree, maxIndex)){
		//printf("ITERATION: %d\n", 7-incr);
		if(maxIndex > (*qtreeSize)-10){ // make qtree bigger if need be.
			(*qtreeSize) *= 2;
			qtree = (Box**) realloc(qtree, *qtreeSize);
		}

		currIndex = -1;

		// look if there are any unchecked boxes.
		for(i = minIndex; i < maxIndex+1; i++){
			minIndex = i; // UNCOMMENT FOR POTENTIAL SPEEDUP ALSO POTENTIAL BREAK+++++++++
			if(qtree[i]->check == 0){
				currIndex = i;
				curr = qtree[i];
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
			// CHECK ALL THIS SHTUFF...
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

			// assign parents
			//c1->parent = c2.parent = c3.parent = c4.parent = currIndex;

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
			qtree[maxIndex+1] = c1;
			qtree[maxIndex+2] = c2;
			qtree[maxIndex+3] = c3;
			qtree[maxIndex+4] = c4;
			//printf("!\n");
			curr->c1 = c1->index = maxIndex+1;
			curr->c2 = c2->index = maxIndex+2;
			curr->c3 = c3->index = maxIndex+3;
			curr->c4 = c4->index = maxIndex+4;

			maxIndex += 4;

			free(indexes);

			// printBox(curr);
			// printBox(c1);
			// printBox(c2);
			// printBox(c3);
			// printBox(c4);
		}
		//printf("out of conditional\n");

		if(currIndex >= 0){ // box has been dealt with.
			curr->check = 1;}
			// printf("\nPermutation Array:\n");
			// printIntArr(n, perm);
			// printf("\n");
		//}

	}

	printf("whooo out of big loop!\n");
	printf("boxes in array:\n\n");

	for(i = 0; i < *qtreeSize; i++){
		if(qtree[i]){
			printBox(qtree[i]);
			printf("\n");
		}
	}

	printf("\nPermutation Array:\n");
	printIntArr(n, perm);

	return;
}

// indexes[0] is start of c1, indexes[1] start of c2, [2] start c3 etc
// points ll and ur gives dimensions of box to split into children and sort.
void sort(int* perm, Point* points, int start, int end, int* indexes, Box c1, Box c2, Box c3, Box c4){
	int *c1_arr, *c2_arr, *c3_arr, *c4_arr, c1ind, c2ind, c3ind, c4ind, i, indSum, last;
	c1ind = c2ind = c3ind = c4ind = 0;

	// printf("start: %d, end: %d\n", start, end);
	// 	printf("perm arr\n");
	// printIntArr(14, perm);

	c1_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c2_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c3_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c4_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));

	for(i = start; i < end; i++){
		// need else if's otherwise pts included twice.
		if(point_in_box(points[perm[i]], c1)){
			c1_arr[c1ind++] = perm[i];
			last = 1;
		}
		else if(point_in_box(points[perm[i]], c2)){
			c2_arr[c2ind++] = perm[i];
			last = 2;
		}
		else if(point_in_box(points[perm[i]], c3)){
			c3_arr[c3ind++] = perm[i];
			last = 3;
		}
		else if(point_in_box(points[perm[i]], c4)){
			c4_arr[c4ind++] = perm[i];
			last = 4;
		}
		else{
			// case for border?
		}
	}

	i = indexes[0] = start;
	indSum = start;
	if(c1ind > 0){
		indSum += c1ind;
		for(; i < indSum; i++)
			perm[i] = c1_arr[i];
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

	//assert(i == end);
	// printf("perm arr\n");
	// printIntArr(10, perm);
	// printf("index array:\n");
	// printIntArr(4, indexes);
	// printf("c1_arr: \n");
	// printIntArr(c1ind, c1_arr);
	// printf("c2_arr: \n");
	// printIntArr(c2ind, c2_arr);
	// printf("c3_arr: \n");
	// printIntArr(c3ind, c3_arr);
	// printf("c4_arr: \n");
	// printIntArr(c4ind, c4_arr);
	// printf("\n");

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

// call within seek function?
void seek_naive(double* a, int n, int k, int* iz){
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

	// for(i = 0; i < n; i++){
	// 	printf("%d: [%f, %f]\n", points[i].index, points[i].x, points[i].y);
	// }

	// find closest points
	for(i = 0; i < n; i++){
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
	}

	// put points back into iz
	for(i = 0; i < k*n; i++){
		iz[i] = (ret[i]).index;
		iz[i]++; // increment because specs want index base 1. IMPORTANT *********************************************
	}

	free(ret);
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