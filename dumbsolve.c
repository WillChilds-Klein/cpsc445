#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE (1)
#define FALSE (0)

void dumb_solve(double* a, double* y, int n, double eps, int numit, double* x, int* niter, double* discreps);
double* gradient(int n, double** A, double* x, double* y);
double calculateGamma(int n, double** A, double* grad);
double vectorMagnitude(int n, double* v);
double* vectorScale(int n, double* v, double c);
double* vectorAdd(int n, double* u, double* v);
double* matrixVectorMultiply(int n, double** m, double* v);
double** matrixScale(int n, double** m, double c);
double** matrixMultiply(int n, double** left, double** right);
double** matrixTranspose(int n,double** matrix);
double* matrixFlatten(int n, double** matrix);
double** matrixExpand(int n, double* flat);
double** matrixCreate(int n);
void matrixPrint(int n, double** matrix);
void flatPrint(int n, double* flat);

void dumb_solve(double* a, double* y, int n, double eps, int numit, double* x, int* niter, double* discreps){

	double **A, *xCurr, *xNext, gamma, *grad;
	int i;

	A = matrixExpand(n, a);

	xCurr = malloc(n * sizeof(double));
	*niter = 0;

	do{
		if(*niter > 0 && discreps[(*niter)-1] < eps)
			break;
		grad = gradient(n, A, xCurr, y);
		matrixExpand(n, a);
		gamma = calculateGamma(n, A, grad);
		xNext = vectorAdd(n, xCurr, vectorScale(n, grad, -1*gamma)); // make gradient negative
		discreps[*niter] = pow(vectorMagnitude(n, grad), 2);
		xCurr = xNext;
	}while((*niter)++ < numit);

	for(i = 0; i < n; i++){
		x[i] = xCurr[i];
	}
}

double* gradient(int n, double** A, double* x, double* y){
	double* right = vectorAdd(n, matrixVectorMultiply(n, A, x), vectorScale(n, y, -1));
	double* left = matrixVectorMultiply(n, matrixTranspose(n, A), right);
	return vectorScale(n, left, 2);
}

double calculateGamma(int n, double** A, double* grad){
	return pow(vectorMagnitude(n, grad), 2) / (2 * pow(vectorMagnitude(n, matrixVectorMultiply(n, A, grad)), 2));
}

double vectorMagnitude(int n, double* v){
	int i;
	double sum;
	for(i = 0; i < n; i++){
		sum += pow(v[i], 2);
	}
	return sqrt(sum);
}

double* vectorScale(int n, double* v, double c){
	int i;
	double* ret = malloc(n * sizeof(double));
	for(i = 0; i < n; i++){
		ret[i] = c * v[i];
	}
	return ret;
}

double* vectorAdd(int n, double* u, double* v){
	double* ret = malloc(n * sizeof(double));
	int i;
	for(i = 0; i < n; i++){
		ret[i] = u[i] + v[i];
	}
	return ret;
}

double* matrixVectorMultiply(int n, double** m, double* v){
	double* ret = malloc(n * sizeof(double));
	double sum;
	int i, j;
	for(i = 0; i < n; i++){
		sum = 0;
		for(j = 0; j < n; j++){
			sum += m[i][j] * v[j];
		}
		ret[i] = sum;
	}
	return ret;
}

double** matrixScale(int n, double** m, double c){
	double** ret = matrixCreate(n);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			ret[i][j] = m[i][j] * c;
		}
	}
	return ret;
}

// multiplies 2 n x n matrices left and right, returns L*R as newly 
// malloc'd n x n matrix.
// CAUTION: does not free memory, so make sure that that's taken care
// of externally. This is a potential source for a HUGE memory leak.
double** matrixMultiply(int n, double** left, double** right){
	int i, j, k;
	double vectorSum;
	double** matrix = matrixCreate(n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			vectorSum = 0;
			for(k = 0; k < n; k++){
				vectorSum += left[i][k] * right[k][j];
			}
			matrix[i][j] = vectorSum;
		}
	}
	return matrix;
}

double** matrixTranspose(int n, double** matrix){
	double** transpose = matrixCreate(n);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			transpose[j][i] = matrix[i][j];
		}
	}
	return transpose;
}

// allocate space for new n x n matrix and populate all 0's
double** matrixCreate(int n){
	double** matrix = malloc(n * sizeof(double*));
	int i, j;
	for(i = 0; i < n; i++){
		matrix[i] = malloc(n * sizeof(double));
		for(j = 0; j < n; j++){
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

double* matrixFlatten(int n, double** matrix){
	double* flat = malloc(n*n * sizeof(double));
	int i, j, flatIndex;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			flatIndex = (i*n) + j;
			flat[flatIndex] = matrix[i][j];
		}
	}
	return flat;
}

double** matrixExpand(int n, double* flat){
	int i, j;
	double** matrix = matrixCreate(n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matrix[i][j] = flat[(i*n)+j];
		}
	}
	return matrix;
}

void matrixPrint(int n, double** matrix){
	int i, j;
	for(i = 0; i < n; i++){
		printf("[");
		for(j = 0; j < n; j++){
			if(j == n-1)
				printf(" %f]\n", matrix[i][j]);
			else
				printf(" %f,", matrix[i][j]);
		}
	}
	return;
}

void flatPrint(int n, double* flat){
	int i;
	for(i = 0; i < n; i++){
		printf("%f, ", flat[i]);
	}
	printf("\n");
	return;
}

int main(){
	double **a, *y, eps, *x, *discreps;
	int n, numit, *niter, i, k;

	eps = pow(10, -6);
	numit = 1000;
	discreps = calloc(numit, sizeof(double));
	niter = malloc(sizeof(int));

	int sizes[] = {3, 4, 6, 10};

	for(k = 0; k < 4; k++){
		int n = sizes[k];
		printf("n = %d\n", n);
		a = matrixCreate(n);
		for(i = 0; i < n; i++){
			a[i][i] = 1 / pow((i+1), 2);
		}
		y = malloc(n * sizeof(double));
		for(i = 0; i < n; i++){
			y[i] = 1;
		}
		printf("original a:\n");
		matrixPrint(n, a);
		printf("original y:\n");
		flatPrint(n, y);
		x = malloc(n * sizeof(double));
		dumb_solve(matrixFlatten(n, a), y, n, eps, numit, x, niter, discreps);
		printf("final x:\n");
		flatPrint(n, x);
		printf("niter: %d\n", *niter);
		printf("discreps: ");
		flatPrint(n, discreps);
		printf("\n");
	}

	return 0;
}

// OUTPUT!!

// n = 3
// original a:
// [ 1.000000, 0.000000, 0.000000]
// [ 0.000000, 0.250000, 0.000000]
// [ 0.000000, 0.000000, 0.111111]
// original y:
// 1.000000, 1.000000, 1.000000, 
// final x:
// 0.998692, 4.000000, 8.966841, 
// niter: 78
// discreps: 4.299383, 0.285634, 1.171258, 

// n = 4
// original a:
// [ 1.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.250000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.111111, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.062500]
// original y:
// 1.000000, 1.000000, 1.000000, 1.000000, 
// final x:
// 0.998625, 4.000000, 8.999999, 15.885888, 
// niter: 222
// discreps: 4.315008, 0.303255, 1.293981, 0.103682, 

// n = 6
// original a:
// [ 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.250000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.111111, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.062500, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.040000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.027778]
// original y:
// 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 
// final x:
// 0.998578, 4.000000, 9.000000, 16.000000, 24.994915, 35.393471, 
// niter: 938
// discreps: 4.324494, 0.314068, 1.369973, 0.114399, 0.666650, 0.064228, 

// n = 10
// original a:
// [ 1.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.250000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.111111, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.062500, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.040000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.027778, 0.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.020408, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.015625, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.012346, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.010000]
// original y:
// 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 
// final x:
// 1.002953, 4.000000, 9.000000, 16.000000, 24.997047, 35.532854, 44.285927, 47.758530, 46.577640, 42.954276, 
// niter: 1001
// discreps: 4.328146, 0.318252, 1.399390, 0.118634, 0.699716, 0.068310, 0.508946, 0.052399, 0.422263, 0.044069,

// ANALYSIS
// It would seem that the growth of niters diminishes as the size of the system grows. We 
// can't really generalize this, because our matrices are a special case. They are also
// pretty easy to solve, and require relatively few iterations to converge. This algorithm
// converges VERY slowly, requiring a number of iterations 100 times the size of the linear 
// system it is solving. With a non-diagonal A matrix, this number would surely be larger. 
// The behavior of discreps is slightly harder to clarify. At first, it seems to oscillate 
// significantly, but as gamma becomes smaller and smaller, discreps becomes smaller as well.
