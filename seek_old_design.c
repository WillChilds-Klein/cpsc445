//#include <quaplot.c>
#include <math.h>
#include <stdlib.h>

#define INT_MAX (pow(2, 64))
#define QTREE_SIZE (1000000)

typedef struct point {
	double x;
	double y;
} *Point;

typedef struct box {
	struct point ul_corner;
	struct point ur_corner;
	struct point ll_corner;
	struct point lr_corner;
} *Box;

void seek(double* a, int n, int k, int* iz);
void seek_naive(double* a, int n, int k, int* iz);
Box* construct_qtree(Point* points, int n, int k);
int inBox(Box box, Point p);
Box initial_box(Point* points, int n);
double distance(Point u, Point v);

int main(){}

// call within seek function?
void seek_naive(double* a, int n, int k, int* iz){
	int i;
	//Box* qtree;
	Point temp, *points;

	// put points into structure that's easier to work with.
	points = malloc(n * sizeof(Point));
	for(i = 0; i < 2*n; i+=2){
		temp = malloc(sizeof(struct point));
		temp->x = a[i];
		temp->y = a[i+1];
		points[i/2] = temp;
	}

	for(i = 0; i < n; i++){

	}

	// qtree = construct_qtree(points, n, k);

	// for(i = 0; i < QTREE_SIZE; i++){
	// 	if(qtree[i] != NULL)
	// 		free(qtree[i]);
	// }
	// free(qtree);
	return;	
}


Box* construct_qtree(Point* points, int n, int k){
	int i;
	Box* qtree = calloc(QTREE_SIZE, sizeof(Box));
	
	qtree[0] = initial_box(points, n);

	return qtree;
}

int inBox(Box box, Point p){
	return (p->x > box->ll_corner.x && p->x < box->ur_corner.x) &&
			(p->y > box->ll_corner.y && p->y < box->ur_corner.y);
}

Box initial_box(Point* points, int n){
	int i;
	double leastX, greatestX, leastY, greatestY;
	Box init;

	leastX = INT_MAX;
	greatestX = -1 * INT_MAX;
	leastY = INT_MAX;
	greatestY = -1 * INT_MAX;
	init = malloc(sizeof(struct  box));

	for(i = 0; i < n; i++){
		if(points[i]->x < leastX)
			leastX = points[i]->x;
		if(points[i]->x > greatestX)
			greatestX = points[i]->x;
		if(points[i]->y < leastY)
			leastY = points[i]->y;
		if(points[i]->y > greatestY)
			greatestY = points[i]->y;
	}

	init->ul_corner.x = leastX;
	init->ul_corner.y = greatestY;
	init->ur_corner.x = greatestX;
	init->ur_corner.y = greatestY;
	init->ll_corner.x = leastX;
	init->ll_corner.y = leastY;
	init->lr_corner.x = greatestX;
	init->lr_corner.y = leastY;

	return init;
}

double distance(Point u, Point v){
	return sqrt(pow(u->x - v->x, 2) + pow(u->y - v->y, 2));
}