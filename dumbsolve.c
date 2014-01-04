/****************************dumbsolve.c***************************************

						Will Childs-Klein

	dumbsolve is an implementation of the steepest descent method for
	solving linear systems. Steepest descent is advantageous because
	although it does not completely converge quickly, in general, it
	quickly approaches convergence. This means that this is an efficient
	algorithm to use when solving many things at scale, where a quick-and-
	dirty approximation of values is sufficient, and needs to be aquired 
	quickly. The parameter double *a represents the coefficients of the 
	system, y is a vector of the solutions, n is the size of the system, 
	eps is the relative accuracy to which the solution is to be solved, 
	numit is the maximum number of iterations to be allowed, x is a return 
	parameter which holds are solution vector, niter is also a return 
	parameter which holds the number of iterations performed, and discreps 
	is a vector of length niter which holds the discrepancies between the x
	vector between iterations.

******************************************************************************/

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
double** matrixTranspose(int n,double** matrix);
double* matrixFlatten(int n, double** matrix);
double** matrixExpand(int n, double* flat);
double** matrixCreate(int n);
void matrixPrint(int n, double** matrix);
void flatPrint(int n, double* flat);

void dumb_solve(double* a, double* y, int n, double eps, int numit, double* x, int* niter, double* discreps){

	double **A, *xCurr, *xNext, gamma, *grad, *tempVec1, *tempVec2, *tempVec3;
	int i;

	A = matrixExpand(n, a);

	xCurr = calloc(n, sizeof(double));
	*niter = 0;

	do{
		if(*niter > 0 && discreps[(*niter)-1] < eps) // converged.
			break;

		grad = gradient(n, A, xCurr, y); // calculate gradient vector
		gamma = calculateGamma(n, A, grad); // find next step size

		tempVec1 = vectorScale(n, grad, -1*gamma); // make gradient negative
		xNext = vectorAdd(n, xCurr, tempVec1); // find next guess for x
		free(tempVec1);

		tempVec1 = matrixVectorMultiply(n, A, xNext);
		tempVec2 = vectorScale(n, y, -1);
		tempVec3 = vectorAdd(n, tempVec1, tempVec2);
		discreps[*niter] = pow(vectorMagnitude(n, tempVec3), 2); // discrepancy
		free(tempVec1);
		free(tempVec2);
		free(tempVec3);

		free(grad);
		free (xCurr);

		xCurr = xNext; // prepare for next iteration
	}while(++(*niter) < numit);

	for(i = 0; i < n; i++){
		x[i] = xCurr[i];
	}

	free(xCurr);
	for(i = 0; i < n; i++)
		free(A[i]);
	free(A);
}

// calculates gradient vector of matrix A.
double* gradient(int n, double** A, double* x, double* y){
	double *left, *right, *grad, *tempVec1, *tempVec2, **transp;
	int i;

	tempVec1 = matrixVectorMultiply(n, A, x);
	tempVec2 = vectorScale(n, y, -1);
	right = vectorAdd(n, tempVec1, tempVec2);
	free(tempVec1);
	free(tempVec2);

	transp = matrixTranspose(n, A);
	left = matrixVectorMultiply(n, transp, right);
	grad = vectorScale(n, left, 2);
	
	free(right);
	free(left);
	// destroy transpose
	for(i = 0; i < n; i++)
		free(transp[i]);
	free(transp);

	return grad;
}

double calculateGamma(int n, double** A, double* grad){
	double *temp, gamma;
	temp = matrixVectorMultiply(n, A, grad);
	gamma = pow(vectorMagnitude(n, grad), 2) / (2 * pow(vectorMagnitude(n, temp), 2));
	free(temp);
	return gamma;
}

double vectorMagnitude(int n, double* v){
	int i;
	double sum = 0;
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
	double **a, *y, eps, *x, *discreps, *flatA;
	int n, numit, *niter, i, j, k;

	eps = pow(10, -6);
	numit = 10000;
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
		printf("original a:\n");
		matrixPrint(n, a);

		y = malloc(n * sizeof(double));
		for(i = 0; i < n; i++){
			y[i] = 1.0;
		}
		printf("original y:\n");
		flatPrint(n, y);

		x = malloc(n * sizeof(double));

		flatA = matrixFlatten(n, a);
		dumb_solve(flatA, y, n, eps, numit, x, niter, discreps);
		free(flatA);

		printf("final x:\n");
		flatPrint(n, x);
		printf("niter: %d\n", *niter);
		printf("discreps: ");
		flatPrint(n, discreps);
		printf("\n");

		free(x);
		free(y);
		for(j = 0; j < n; j++)
			free(a[j]);
		free(a);
	}

	free(discreps);
	free(niter);

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
// 1.000034, 4.000000, 8.991110, 
// niter: 97
// discreps: 1.849377, 1.250871, 0.935307, 

// n = 4
// original a:
// [ 1.000000, 0.000000, 0.000000, 0.000000]
// [ 0.000000, 0.250000, 0.000000, 0.000000]
// [ 0.000000, 0.000000, 0.111111, 0.000000]
// [ 0.000000, 0.000000, 0.000000, 0.062500]
// original y:
// 1.000000, 1.000000, 1.000000, 1.000000, 
// final x:
// 1.000020, 4.000000, 9.000000, 15.984136, 
// niter: 311
// discreps: 2.841016, 2.209011, 1.858582, 1.624633, 

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
// 0.998915, 4.000000, 9.000000, 16.000000, 24.997104, 35.537180, 
// niter: 1000
// discreps: 4.835918, 4.183746, 3.811623, 3.553460, 3.370466, 3.216369, 

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
// 0.972983, 4.000000, 9.000000, 16.000000, 24.997042, 35.532453, 44.283748, 47.754130, 46.571819, 42.947947, 
// niter: 1000
// discreps: 8.833951, 8.174075, 7.793534, 7.525918, 7.333635, 7.170017, 7.029558, 6.901693, 6.785027, 6.676876, 6, 0.318252, 1.399390, 0.118634, 0.699716, 0.068310, 0.508946, 0.052399, 0.422263, 0.044069,

// ANALYSIS
// It would seem that the growth of niters diminishes as the size of the system grows. We 
// can't really generalize this, because our matrices are a special case (square). They are also
// pretty easy to solve, and require relatively few iterations to converge. This algorithm
// converges VERY slowly, requiring a number of iterations 100 times the size of the linear 
// system it is solving. With a non-diagonal A matrix, this number would surely be larger. 
// The behavior of discreps is slightly harder to clarify. At first, it seems to oscillate 
// significantly, but as gamma becomes smaller and smaller, discreps becomes smaller as well.
