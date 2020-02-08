#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include <vector>
#include "AbstractMatrix.h"
using namespace std;

class MatrixProduct :public AbstractMatrix {
private:
	int** A;
	int** B;
	int** ABres;
	int matr_size;
	bool isPowOfTwo;
	int oldsize;
	int count;

	bool is_power_of_two(int n); 
	int pow_of_num(int n);
	int new_num(int pow); 
	int** alloc_mem(int n);

	int** zero_fill(int** mas, int size, int n);
	int** fill_mas(int** mas, int size, int n, int* buff, int beg);
	int** fill_mas(int** mas, int size, int n, int** matr);
	
	void printMatrix(int** matrix, int m_size, string fname);

	void divideMatrix(int** mas, int m_size, int** m11, int** m12, int** m21, int** m22);
	int** sumMatrix(int** matrix1, int** matrix2, int size);
	int** subtrMatrix(int** matrix1, int** matrix2, int size);
	int** concatMatrix(int** C11, int** C12, int** C21, int** C22, int res_size);
	int** ordinaryMult(int** matrix1, int** matrix2, int m_size);
	int** mult(int** matr1, int** matr2, int m_size);
	int** vinMult(int** matr1, int** matr2, int m_size);
	
public:
	MatrixProduct() {
		A = NULL;
		B = NULL;
		ABres = NULL;
		matr_size = 0;
		isPowOfTwo = 0;
		count = 0;
		oldsize = 0;
	}

	int** MatrixMult();
	int** VinogradovMult();
	void scanMatrix(string fname);
	void inputMatrix(int** matr1, int** matr2, int size);
	
	int getMatrSize();
	int** getMatrixA();
	int** getMatrixB();
	int getCount();
};