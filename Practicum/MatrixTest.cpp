#include "MatrixTest.h"
#include <time.h>

using namespace std;

double MatrixTest::ordinaryMultTime(OrdinaryMult* ordProduct, int matr_size, int& steps)
{
	int** A = (int**)malloc(matr_size * sizeof(int*));
	for (int i = 0; i < matr_size; i++) {
		A[i] = (int*)malloc(matr_size * sizeof(int));
	}

	for (int i = 0; i < matr_size; i++) {
		for (int j = 0; j < matr_size; j++) {
			A[i][j] = i + j;
		}
	}
	
	ordProduct->inputMatrix(A, A, matr_size);

	clock_t start = clock();
	ordProduct->MatrixMult();
	clock_t end = clock();

	steps = ordProduct->getCount();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double MatrixTest::fastMultTime(MatrixProduct* matrProduct, int matr_size, int& steps)
{
	int** A = (int**)malloc(matr_size * sizeof(int*));
	for (int i = 0; i < matr_size; i++) {
		A[i] = (int*)malloc(matr_size * sizeof(int));
	}

	for (int i = 0; i < matr_size; i++) {
		for (int j = 0; j < matr_size; j++) {
			A[i][j] = i + j;
		}
	}


	matrProduct->inputMatrix(A, A, matr_size);

	clock_t start = clock();
	matrProduct->MatrixMult();
	clock_t end = clock();

	steps = matrProduct->getCount();
	return (double)(end - start) / CLOCKS_PER_SEC;
}

double MatrixTest::vinogradovMultTime(MatrixProduct* matrProduct, int matr_size, int& steps)
{
	int** A = (int**)malloc(matr_size * sizeof(int*));
	for (int i = 0; i < matr_size; i++) {
		A[i] = (int*)malloc(matr_size * sizeof(int));
	}

	for (int i = 0; i < matr_size; i++) {
		for (int j = 0; j < matr_size; j++) {
			A[i][j] = i + j;
		}
	}

	matrProduct->inputMatrix(A, A, matr_size);

	clock_t start = clock();
	matrProduct->VinogradovMult();
	clock_t end = clock();

	steps = matrProduct->getCount();
	return (double)(end - start) / CLOCKS_PER_SEC;
}
