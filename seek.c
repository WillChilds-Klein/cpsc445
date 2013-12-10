//#include <quaplot.c>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define INT_MAX (pow(2, 64))
#define REALLY_BIG_NUMBER (1000000)

typedef struct point {
	double x;
	double y;
	int index;
} Point;

typedef struct box {
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
void build_tree(Point* points, Box* qtree, int* qtreeSize, int* perm, int n, int k);
void sort(int* perm, Point* points, int start, int end, int* indexes, Point ll, Point ur);
int point_in_box(Point p, Box b);
void printBox(Box b);
void seek_naive(double* a, int n, int k, int* iz);
void insert(Point* arr, Point initial, Point test, int k);
void initPointArr(Point* arr, int k);
int pointEquals(Point p, Point q);
double distance(double x1, double y1, double x2, double y2);
double pointDistance(Point p, Point q);

int main(){
	double a[14] = {0, 0, .3, .3, .51, .51, .1, .1, .9, .9, .8, .8, .7, .7};
	int n, k, *iz, i, j;

	n = 7;
	k = 3;
	iz = malloc(n*k * sizeof(int));

	seek(a, n, k, iz);

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
	int i, *qtreeSize, *perm;
	Box *qtree;
	Point temp, *points;

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

	qtreeSize = malloc(sizeof(int));
	*qtreeSize = 5000;
	qtree = malloc(*qtreeSize * sizeof(Box));
	build_tree(points, qtree, qtreeSize, perm, n, k);


	// REMEMBER TO INCREMENT INDICES WHEN FINISHED DEVELOPING
	free(qtree);
	free(qtreeSize);
}

void build_tree(Point* points, Box* qtree, int* qtreeSize, int* perm, int n, int k){
	int i, currIndex, maxIndex, minIndex, numPointsInBox, *indexes;
	Box curr, root;

	// init root node
	root.ur_corner.x = 1;
	root.ur_corner.y = 1;
	root.ll_corner.x = 0;
	root.ll_corner.y = 0;
	root.perm_start = 0;
	root.perm_end = n;
	root.check = 0;
	qtree[0] = root;

	currIndex = 0;
	maxIndex = 0;
	minIndex = 0; // keep at zero now, but find way to make dynamic to get speed-up.

	int incr = 5;

	while(incr-- > 0){//currIndex >= 0){//!done(qtree, maxIndex)){
		if(maxIndex > (*qtreeSize)-10){ // make qtree bigger if need be.
			(*qtreeSize) *= 2;
			qtree = (Box*) realloc(qtree, *qtreeSize);
		}

		currIndex = -1;

		// look if there are any unchecked boxes.
		for(i = minIndex; i < maxIndex+1; i++){
			//minIndex = i; // UNCOMMENT FOR POTENTIAL SPEEDUP
			if(qtree[i].check == 0){
				currIndex = i;
				curr = qtree[i];
				break;
			}
		}
		
		// check if > k points in box. 
		// if so, create children and continue iterations
		// set maxInd to index of last child.
		numPointsInBox = 0;
		for(i = curr.perm_start; i < curr.perm_end; i++){
			// count number of points in box to decide whether or not to split.
			if(currIndex >= 0 && point_in_box(points[perm[i]], curr))
				numPointsInBox++;
			if(numPointsInBox > k)
				break;
		}
		// bust out the kidses
		if(numPointsInBox > k){
			Box c1, c2, c3, c4;
			c1.c1=c1.c2=c1.c3=c1.c4= -1;
			c2.c1=c2.c2=c2.c3=c2.c4= -1;
			c3.c1=c3.c2=c3.c3=c3.c4= -1;
			c4.c1=c4.c2=c4.c3=c4.c4= -1;
			// init check values
			c1.check = c2.check = c3.check = c4.check = 0;
			// CHECK ALL THIS SHTUFF...
			// determine boundaries of children
			c1.ll_corner.x = curr.ll_corner.x;
			c1.ll_corner.y = curr.ll_corner.y+((curr.ur_corner.y - curr.ll_corner.y)/2);
			c1.ur_corner.x = curr.ll_corner.x+((curr.ur_corner.x - curr.ll_corner.x)/2);
			c1.ur_corner.y = curr.ur_corner.y;

			c2.ll_corner.x = curr.ll_corner.x+((curr.ur_corner.x - curr.ll_corner.x)/2);
			c2.ll_corner.y = curr.ll_corner.y+((curr.ur_corner.y - curr.ll_corner.y)/2);
			c2.ur_corner.x = curr.ur_corner.x;
			c2.ur_corner.y = curr.ur_corner.y;

			c3.ll_corner.x = curr.ll_corner.x;
			c3.ll_corner.y = curr.ll_corner.y;
			c3.ur_corner.x = curr.ll_corner.x+((curr.ur_corner.x - curr.ll_corner.x)/2);
			c3.ur_corner.y = curr.ll_corner.y+((curr.ur_corner.y - curr.ll_corner.y)/2);

			c4.ll_corner.x = curr.ll_corner.x+((curr.ur_corner.x - curr.ll_corner.x)/2);
			c4.ll_corner.y = curr.ll_corner.y;
			c4.ur_corner.x = curr.ur_corner.x;
			c4.ur_corner.y = curr.ll_corner.y+((curr.ur_corner.y - curr.ll_corner.y)/2);

			// assign parents
			//c1.parent = c2.parent = c3.parent = c4.parent = currIndex;

			indexes = calloc(4, sizeof(int));
			sort(perm, points, curr.perm_start, curr.perm_end, indexes, curr.ll_corner, curr.ur_corner);

			// assign children start and end indexes in perm array
			c1.perm_start = indexes[0];
			c1.perm_end = indexes[1];
			c2.perm_start = indexes[1];
			c2.perm_end = indexes[2];
			c3.perm_start = indexes[2];
			c3.perm_end = indexes[3];
			c4.perm_start = indexes[3];
			c4.perm_end = curr.perm_end;

			printf("%d %d\n", maxIndex, *qtreeSize);
			qtree[maxIndex+1] = c1;
			qtree[maxIndex+2] = c2;
			qtree[maxIndex+3] = c3;
			qtree[maxIndex+4] = c4;
			printf("!\n");
			curr.c1 = maxIndex+1;
			curr.c2 = maxIndex+3;
			curr.c3 = maxIndex+2;
			curr.c4 = maxIndex+4;

			maxIndex += 4;

			free(indexes);

			printBox(curr);
			printBox(c1);
			printBox(c2);
			printBox(c3);
			printBox(c4);
		}
		printf("out of conditional\n");

		if(currIndex > 0) // box has been dealt with.
			curr.check = 1;
	}

	printf("whooo out of big loop!\n");

	return;
}

// indexes[0] is start of c1, indexes[1] start of c2, [2] start c3 etc
// points ll and ur gives dimensions of box to split into children and sort.
void sort(int* perm, Point* points, int start, int end, int* indexes, Point ll, Point ur){
	int *c1_arr, *c2_arr, *c3_arr, *c4_arr, c1ind, c2ind, c3ind, c4ind, i;
	c1ind = c2ind = c3ind = c4ind = 0;
	Box c1, c2, c3, c4;

	c1_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c2_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c3_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));
	c4_arr = malloc(REALLY_BIG_NUMBER * sizeof(int));

	c1.ll_corner.x = ll.x;
	c1.ll_corner.y = ll.y+((ur.y - ll.y)/2);
	c1.ur_corner.x = ll.x+((ur.x - ll.x)/2);
	c1.ur_corner.y = ur.y;

	c2.ll_corner.x = ll.x+((ur.x - ll.x)/2);
	c2.ll_corner.y = ll.y+((ur.y - ll.y)/2);
	c2.ur_corner.x = ur.x;
	c2.ur_corner.y = ur.y;

	c3.ll_corner.x = ll.x;
	c3.ll_corner.y = ll.y;
	c3.ur_corner.x = ll.x+((ur.x - ll.x)/2);
	c3.ur_corner.y = ll.y+((ur.y - ll.y)/2);

	c4.ll_corner.x = ll.x+((ur.x - ll.x)/2);
	c4.ll_corner.y = ll.y;
	c4.ur_corner.x = ur.x;
	c4.ur_corner.y = ll.y+((ur.y - ll.y)/2);

	for(i = start; i < end+1; i++){
		if(point_in_box(points[perm[i]], c1)){
			c1_arr[c1ind++] = perm[i];
		}
		else if(point_in_box(points[perm[i]], c2)){
			c2_arr[c2ind++] = perm[i];
		}
		else if(point_in_box(points[perm[i]], c3)){
			c3_arr[c3ind++] = perm[i];
		}
		if(point_in_box(points[perm[i]], c4)){
			c4_arr[c4ind++] = perm[i];
		}
	}

	i = indexes[0] = start;
	if(c1ind > 0){
		for(; i < c1ind+1; i++)
			perm[i] = c1_arr[i];
	}

	indexes[1] = i; 
	if(c2ind >= 0){
		for(; i < c1ind+c2ind+1; i++)
			perm[i] = c2_arr[i-c1ind];
	}

	indexes[2] = i;
	if(c3ind >= 0){
		for(; i < c1ind+c2ind+c3ind+1; i++)
			perm[i] = c3_arr[i-c1ind-c2ind];
	}

	indexes[3] = i;
	if(c4ind >= 0){
		for(; i < c1ind+c2ind+c3ind+c4ind+1; i++)
			perm[i] = c4_arr[i-c1ind-c2ind-c3ind];
	}

	// i = indexes[0] = start;
	// if(c1ind >= 0){
	// 	for(; i < c1ind+1; i++)
	// 		perm[i] = c1_arr[i];
	// }else{c1ind = 0;}

	// indexes[1] = i; 
	// if(c2ind >= 0){
	// 	for(; i < c1ind+c2ind+1; i++)
	// 		perm[i] = c2_arr[i-c1ind];
	// }else{c2ind = 0;}

	// indexes[2] = i;
	// if(c3ind >= 0){
	// 	for(; i < c1ind+c2ind+c3ind+1; i++)
	// 		perm[i] = c3_arr[i-c1ind-c2ind];
	// }else{c3ind = 0;}

	// indexes[3] = i;
	// if(c4ind >= 0){
	// 	for(; i < c1ind+c2ind+c3ind+c4ind+1; i++)
	// 		perm[i] = c4_arr[i-c1ind-c2ind-c3ind];
	// }else{c4ind = 0;}

	//assert(i == end);

	free(c1_arr);
	free(c2_arr);
	free(c3_arr);
	free(c4_arr);

	return;
}

int point_in_box(Point p, Box b){
	return p.x > b.ll_corner.x && p.y > b.ll_corner.y &&
		p.x < b.ur_corner.x && p.y < b.ur_corner.y;
}

// typedef struct box {
// 	// points of corners
// 	struct point ll_corner;
// 	struct point ur_corner;

// 	// start and end indices of box within permutation array.
// 	// [perm_start, perm_end) ie, start inclusive, end is index_of_last_elt+1.
// 	int perm_start;
// 	int perm_end;

// 	// indices of children and parent nodes in perm array...-1 if null.
// 	int c1, c2, c3, c4;
// 	int parent;

// 	// non-zero iff all work for this box is completed in construction of quadtree
// 	// checked after perm array sorted and children created.
// 	int check;
// } Box;

void printBox(Box b){
	printf("ll_corner: [%f, %f]\n", b.ll_corner.x, b.ll_corner.y);
	printf("ur_corner: [%f, %f]\n", b.ur_corner.x, b.ur_corner.y);
	printf("perm_start: %d, perm_end: %d\n", b.perm_start, b.perm_end);
	printf("check: %d\n", b.check);
	printf("children: [%d, %d, %d, %d]\n", b.c1, b.c2, b.c3, b.c4);
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
		//iz[i]++; // increment because specs want index base 1. IMPORTANT *********************************************
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