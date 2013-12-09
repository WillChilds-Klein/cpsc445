//#include <quaplot.c>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX (pow(2, 64))
#define QTREE_SIZE (1000000)

typedef struct point {
	double x;
	double y;
	int index;
} Point;

typedef struct box {
	// points of corners
	struct point ul_corner;
	struct point ur_corner;
	struct point ll_corner;
	struct point lr_corner;

	// start and end indices of box within permutation array.
	int perm_start;
	int perm_end;

	int check;

	// indices of child nodes...-1 if null.
	int c1, c2, c3, c4;
} Box;

void seek(double* a, int n, int k, int* iz);
void seek_naive(double* a, int n, int k, int* iz);
void insert(Point* arr, Point initial, Point test, int k);
void initPointArr(Point* arr, int k);
int pointEquals(Point p, Point q);
double distance(double x1, double y1, double x2, double y2);
double pointDistance(Point p, Point q);

int main(){
	double a[10] = {0,0,.3,.3,.5,.5,-.1,-.1,.9,.9};
	int n, k, *iz, i, j;

	n = 5;
	k = 3;
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
	int *perm;



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
		iz[i]++; // increment because specs want index base 1.
	}

	free(ret);
	return;	
}

void insert(Point* arr, Point initial, Point test, int k){
	int i, j, lrgst_index;
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