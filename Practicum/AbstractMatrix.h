#pragma once
#include <iostream>
#include <string>
using namespace std;

class AbstractMatrix {
public:
	AbstractMatrix() {};
	
	virtual int** MatrixMult()=0;
	virtual void scanMatrix(string fname)=0;
	virtual void inputMatrix(int **matr1, int **matr2, int size)=0;

	virtual int** getMatrixA()=0;
	virtual int** getMatrixB()=0;
	virtual int getMatrSize() = 0;
	virtual int getCount() = 0;
};