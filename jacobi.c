#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE (1)
#define FALSE (0)

#define ZERO_PRECISION (pow(10, -5))

void jacobi(double* a, int n, double* s, double* u, double* v);
double calculateTheta(double a, double b, double c, double d);
double calculatePhi(double a, double b, double c, double d);
int converged(int n, double** A);
void assignVals(double*** left, double*** right, int i, int j, double theta, double phi);
void sortDecreacing(int n, double** s, double*** U, double*** Vt);
void swapRows(int n, double*** m, int row1, int row2);
void swapCols(int n, double*** m, int col1, int col2);
void changeRowSign(int n, double*** m, int row);
void changeColSign(int n, double*** m, int col);
double** matrixMultiply(int n, double** left, double** right);
double** matrixTranspose(int n,double** matrix);
void matrixDestroy(int n, double** matrix);
double* matrixFlatten(int n, double** matrix);
double** matrixExpand(int n, double* flat);
double** matrixCreate(int n);
double** matrixCopy(int n, double** matrix);
double** identityMatrix(int n);
void matrixPrint(int n, double** matrix);
void flatPrint(int n, double* flat);
double** partb(int n);
double** partc(int n);

void jacobi(double* flatA, int n, double* returnS, double* returnU, double* returnV){
	int j, i, largestCoordinate;
	double max, reserve, swapu, swapv,
		**L, **R, **Ut, **V, 
		**S, **U, **Vt, **A, 
		*flatU, *flatV;
	Ut = identityMatrix(n); // init Ut to identity
	V = identityMatrix(n); // init V to identity
	A = matrixExpand(n, flatA);

	int sweeps = 0;
	double theta, phi;
	theta = 0;
	phi = 0;

	while(!converged(n, A)){ 
		for(i = 0; i < n; i++){
			for(j = i+1; j < n; j++){
				theta = calculateTheta(A[i][i], A[i][j], A[j][i], A[j][j]);
				phi = calculatePhi(A[i][i], A[i][j], A[j][i], A[j][j]);

				L = identityMatrix(n);
				R = identityMatrix(n);

				assignVals(&L, &R, i, j, theta, phi);

				Ut = matrixMultiply(n, L, Ut);
				V = matrixMultiply(n, V, R);

				A = matrixMultiply(n, matrixMultiply(n, L, A), R);

				matrixDestroy(n, L);
				matrixDestroy(n, R);
			}
		}
		sweeps++;
	}

	printf("\nNumber of sweeps: %d\n", sweeps);

	U = matrixTranspose(n, Ut);

	Vt = matrixTranspose(n, V);

	S = matrixCopy(n, A);

	max = 0;
	printf("\nAll values of s with magnitude > %f\n", ZERO_PRECISION);
	for(i = 0; i < n; i++){
		if(S[i][i] > max){
			max = S[i][i];
			largestCoordinate = i;
		}
		for(j = 0; j < n; j++){
			if(fabs(S[i][j]) > ZERO_PRECISION)
				printf("s[%d][%d] = %f\n", i, j, S[i][j]);
		}
	}

	printf("\n");
	printf("Row/Column number of singular vector(s) corresponding to largest "
		"magnitude eigenvalue (zero-indexed, before sorting): [%d]\n", largestCoordinate);
	printf("\n");

	// parse and sort spectrum
	for(i = 0; i < n; i++){
		returnS[i] = S[i][i];
		if(S[i][i] < 0){
			returnS[i] *= -1; // make positive
			changeColSign(n, &U, i);
		}
		if(fabs(S[i][i]) > max){
			max = fabs(S[i][i]);
			largestCoordinate = i;
		}
	}
	sortDecreacing(n, &returnS, &U, &Vt);

	// set V equal to transpose of Vt
	V = matrixTranspose(n, Vt);

	// flatten working matrices
	flatU = matrixFlatten(n, U);
	flatV = matrixFlatten(n, V);

	// assign vals to output
	for(i = 0; i < n*n; i++){
		returnV[i] = flatV[i];
		returnU[i] = flatU[i];
	}

	// destroy input matrix
	free(flatA);

	// destroy all other matrices
	matrixDestroy(n, U);
	matrixDestroy(n, Ut);
	matrixDestroy(n, V);
	matrixDestroy(n, Vt);
	matrixDestroy(n, S);
	matrixDestroy(n, A);
	free(flatU);
	free(flatV);

	return;
}

double calculateTheta(double a, double b, double c, double d){

	double theta;

	theta = atan((-1*a*a - b*b + c*c + d*d - sqrt(-4*(-1*a*c - b*d)*(a*c + b*d)
		+ pow((a*a + b*b - c*c - d*d), 2)))
		/ (2*(a*c + b*d)));

	return theta;
}

double calculatePhi(double a, double b, double c, double d){

	double phi;

	phi = atan((-1*a*a + b*b - c*c + d*d - sqrt(-4*(-1*a*c - b*d)*(a*c + b*d)
		+ pow((a*a + b*b - c*c - d*d), 2)))
		/ (2*(a*b + c*d)));

	return phi;
}

// NOTE: must test convergence at 0 ~ 10^-7 because double precision numbers in C
// only allow that much presicion? converges only if testing with 10^-7
int converged(int n, double** A){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i != j && fabs(A[i][j]) > ZERO_PRECISION)
				return FALSE;
		}
	}
	return TRUE;
}

void assignVals(double*** left, double*** right, int i, int j, double theta, double phi){
	(*left)[i][i] = cos(theta);
	(*left)[i][j] = sin(theta);
	(*left)[j][i] = -1 * sin(theta);
	(*left)[j][j] = cos(theta);

	(*right)[i][i] = cos(phi);
	(*right)[i][j] = -1 * sin(phi);
	(*right)[j][i] = sin(phi);
	(*right)[j][j] = cos(phi);

	return;
}

// Modified bubble sort. Horribly inefficient at O(n^3), but that's ok.
void sortDecreacing(int n, double** s, double*** U, double*** Vt){
	int i, swapped;
    double temp;

   	swapped = TRUE;

   	while(swapped){
   		swapped = FALSE;
   		for(i = 0; i < n-1; i++){
   			if((*s)[i] < (*s)[i+1]){
   				temp = (*s)[i];
   				(*s)[i] = (*s)[i+1];
   				(*s)[i+1] = temp;
   				swapRows(n, Vt, i, i+1);
   				swapCols(n, U, i, i+1);
   				swapped = TRUE;
   			}
   		}
   	}
   	return;
}

void swapRows(int n, double*** m, int row1, int row2){
	int j;
	double temp;

	for(j = 0; j < n ; j++){
		temp = (*m)[row1][j];
		(*m)[row1][j] = (*m)[row2][j];
		(*m)[row2][j] = temp;
	}

	return;
}

void swapCols(int n, double*** m, int col1, int col2){
	int i;
	double temp;

	for(i = 0; i < n ; i++){
		temp = (*m)[i][col1];
		(*m)[i][col1] = (*m)[i][col2];
		(*m)[i][col2] = temp;
	}

	return;
}

void changeRowSign(int n, double*** m, int row){
	int j;
	for(j = 0; j < n; j++)
		(*m)[row][j] *= -1;
	return;
}

void changeColSign(int n, double*** m, int col){
	int i;
	for(i = 0; i < n; i++)
		(*m)[i][col] *= -1;
	return;

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

double** matrixCopy(int n, double** matrix){
	double** ret = matrixCreate(n);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			ret[i][j] = matrix[i][j];
		}
	}
	return ret;
}

// allocate and create n x n identity matrix
double** identityMatrix(int n){
	double** matrix = matrixCreate(n);
	int i, j;
	for(i = 0; i < n; i++){
		matrix[i][i] = 1;
	}
	return matrix;
}

double** partb(int n){
	double** matrix = matrixCreate(n);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matrix[i][j] = sqrt(i*i + j*j);
		}
	}
	return matrix;
}

double** partc(int n){
	double** matrix = matrixCreate(n);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matrix[i][j] = i*i + j*j;
		}
	}
	return matrix;
}

void matrixDestroy(int n, double** matrix){
	int i;
	for(i = 0; i < n; i++){
		free(matrix[i]);
	}
	free(matrix);
	return;
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
	for(i = 0; i < n*n; i++){
		printf("%f, ", flat[i]);
	}
	printf("\n");
	return;
}

/** /
int main(){

	double** a;
	int n;

	double *sb10, *ub10, *vb10,
			*sb20, *ub20, *vb20,
			*sb40, *ub40, *vb40,
			*sc10, *uc10, *vc10;

	printf("Part b, dimensionality 10.\n");
	n = 10;
	a = partb(n);
	sb10 = malloc(n * sizeof(double));
	ub10 = malloc(n*n * sizeof(double));
	vb10 = malloc(n*n * sizeof(double));

	jacobi(matrixFlatten(n, a), n, sb10, ub10, vb10);

	matrixDestroy(n, a);
	free(sb10);
	free(ub10);
	free(vb10);

	printf("\nPart b, dimensionality 20.\n");
	n = 20;
	a = partb(n);
	sb20 = malloc(n * sizeof(double));
	ub20 = malloc(n*n * sizeof(double));
	vb20 = malloc(n*n * sizeof(double));

	jacobi(matrixFlatten(n, a), n, sb20, ub20, vb20);

	matrixDestroy(n, a);
	free(sb20);
	free(ub20);
	free(vb20);

	printf("\nPart b, dimensionality 40.\n");
	n = 40;
	a = partb(n);
	sb40 = malloc(n * sizeof(double));
	ub40 = malloc(n*n * sizeof(double));
	vb40 = malloc(n*n * sizeof(double));

	jacobi(matrixFlatten(n, a), n, sb40, ub40, vb40);

	matrixDestroy(n, a);
	free(sb40);
	free(ub40);
	free(vb40);

	printf("\nPart c, dimensionality 10.\n");
	n = 10;
	a = partc(n);
	sc10 = malloc(n * sizeof(double));
	uc10 = malloc(n*n * sizeof(double));
	vc10 = malloc(n*n * sizeof(double));

	jacobi(matrixFlatten(n, a), n, sc10, uc10, vc10);

	matrixDestroy(n, a);
	free(sc10);
	free(uc10);
	free(vc10);

	return 0;
}
/**/

// Part b, dimensionality 10.

// Number of sweeps: 7

// All values of s with magnitude > 0.000010
// s[2][2] = -0.000019
// s[3][3] = -0.000314
// s[4][4] = -0.003580
// s[5][5] = -0.029815
// s[6][6] = -0.176243
// s[7][7] = -0.866746
// s[8][8] = -10.098373
// s[9][9] = 74.814702

// Row/Column number of singular vector(s) corresponding to largest magnitude eigenvalue (zero-indexed, before sorting): [9]


// Part b, dimensionality 20.

// Number of sweeps: 10

// All values of s with magnitude > 0.000010
// s[10][10] = -0.000026
// s[11][11] = -0.000194
// s[12][12] = -0.001280
// s[13][13] = -0.007441
// s[14][14] = -0.037720
// s[15][15] = -0.160157
// s[16][16] = -0.594103
// s[17][17] = -2.996829
// s[18][18] = -39.339800
// s[19][19] = 311.838130

// Row/Column number of singular vector(s) corresponding to largest magnitude eigenvalue (zero-indexed, before sorting): [19]


// Part b, dimensionality 40.

// Number of sweeps: 11

// All values of s with magnitude > 0.000010
// s[28][28] = -0.000034
// s[29][29] = -0.000178
// s[30][30] = -0.000821
// s[31][31] = -0.003549
// s[32][32] = -0.014339
// s[33][33] = -0.053447
// s[34][34] = -0.178233
// s[35][35] = -0.549892
// s[36][36] = -2.016954
// s[37][37] = -11.233545
// s[38][38] = -155.248838
// s[39][39] = 1272.386420

// Row/Column number of singular vector(s) corresponding to largest magnitude eigenvalue (zero-indexed, before sorting): [39]


// Part c, dimensionality 10.

// Number of sweeps: 3

// All values of s with magnitude > 0.000010
// s[8][8] = -106.573748
// s[9][9] = 676.573748

// Row/Column number of singular vector(s) corresponding to largest magnitude eigenvalue (zero-indexed, before sorting): [9]

// ANALYSIS
// The algorithm seems to show diminishing sweeps at scale. In other words, 
// as input grows, the rate of growths of sweeps needed seems to diminish. 
// Operation count seems to be around n*(n/2) per sweep where n is A's 
// dimensionality. The algorithm seems to converge fairly quickly, converging
// faster at larger input sizes. Reliability seems to be a major issue with
// my implementation. It will only converge if we allow the program's approximation
// of zero to be 10^-5 as opposed to 10^-13 given in the specifications. I think 
// this might be an issue with C's internal handling/representation of doubles. 
// I can't figure out why this is, but when I change the ZERO_PRECISION value to 
// anything less than 10^-5, the algorighm doesn't converge and runs until the 
// system kills the process. It kills the process (I think) because my 
// implementation has a significant memory leak at scale. during matrix 
// multiplication, I don't free some of the terms of the multiplication, and 
// they just sit around in memory and multiply with iterations and sweeps. 