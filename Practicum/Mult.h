#pragma once
#include "MatrixProduct.h"
#include "OrdinaryMult.h"
#include "AbstractMatrix.h"
#include <iostream>
#include <vector>
using namespace std;

class Mult {
	int i=-1;
	vector <AbstractMatrix*> vect;

public:
	int ordinaryMult();
	int strassenMult();
	int getComplexity();
	int inp_matr(int** matr1, int** matr2, int n);
	
	int** getResult();
	int** getMatrA();
	int** getMatrB();
	
	
};