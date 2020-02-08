#pragma once
#include"AbstractMatrix.h"
#include<iostream>
#include<string>
using namespace std;

class OrdinaryMult :public AbstractMatrix {
private:
	int matr_size;
	int** A;
	int** B;
	int** result;
	int count = 0;

	int** fill_mas(int** mas, int* buf, int size, int beg);
	int** fill_mas(int** mas, int** matr, int size);
	int** alloc_mem(int n);
public:
	OrdinaryMult() {
		A = B = result= NULL;
		matr_size = count = 0;
	}
	
	int** MatrixMult();
	void scanMatrix(string fname);
	void inputMatrix(int** matr1, int** matr2, int size);

	int** getMatrixA();
	int** getMatrixB();
	int getMatrSize();
	int getCount();
};