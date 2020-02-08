#include"OrdinaryMult.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int** OrdinaryMult::fill_mas(int** mas, int* buf, int size, int beg)
{
	int b = beg;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[i][j] = buf[b];
			b++;
		}
	}
	return mas;
}

int** OrdinaryMult::fill_mas(int** mas, int** matr, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[i][j] = matr[i][j];
		}
	}
	return mas;
}

int** OrdinaryMult::alloc_mem(int n)
{
	int** mas = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mas[i] = (int*)malloc(n * sizeof(int));
	}
	return mas;
}

int OrdinaryMult::getMatrSize()
{
	return matr_size;
}

int OrdinaryMult::getCount()
{
	return count;
}

int** OrdinaryMult::MatrixMult()
{
	result = alloc_mem(matr_size);
	for (int i = 0; i < matr_size; i++) {
		for (int j = 0; j < matr_size; j++) {
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < matr_size; i++) {
		for (int j = 0; j < matr_size; j++) {
			for (int k = 0; k < matr_size; k++) {
				result[i][j] += A[i][k] * B[k][j];
				this->count++;
			}
		}
	}
	return result;
}

void OrdinaryMult::inputMatrix(int** matr1, int** matr2, int size)
{
	matr_size = size;
	A = alloc_mem(matr_size);
	A = fill_mas(A, matr1, matr_size);
	B = alloc_mem(matr_size);
	B = fill_mas(B, matr2, matr_size);
}

int** OrdinaryMult::getMatrixA()
{
	return A;
}

int** OrdinaryMult::getMatrixB()
{
	return B;
}

void OrdinaryMult::scanMatrix(string fname)
{
	fstream in;
	int buff_len;
	in.open(fname, ios::in);
	if (in.is_open()) {

		int buff[500];
		int i = 0;
		while (!in.eof()) {
			in >> buff[i];
			i++;
		}

		buff_len = i;
		matr_size = sqrt((i) / 2);
		A = alloc_mem(matr_size);
		A = fill_mas(A, buff, matr_size, 0);
		B = alloc_mem(matr_size);
		B = fill_mas(B, buff, matr_size, buff_len / 2);

	}
	in.close();
}