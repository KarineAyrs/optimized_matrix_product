#pragma once
#include "AbstractMatrix.h"
#include "MatrixProduct.h"
#include "OrdinaryMult.h"
#include <iostream>

using namespace std;

class MatrixTest {
public:
	
	double ordinaryMultTime(OrdinaryMult* ordProduct,int matr_size,int &steps);
	double fastMultTime(MatrixProduct* matrProduct, int matr_size, int&steps);
	double vinogradovMultTime(MatrixProduct* matrProduct, int matr_size, int& steps);
};