#include "Mult.h"

int Mult::ordinaryMult()
{
	OrdinaryMult* ord=new OrdinaryMult();
	vect.push_back(ord);
	i++;
	return 0;
}

int Mult::strassenMult()
{
	MatrixProduct* mpr=new MatrixProduct();
	vect.push_back(mpr);
	i++;
	return 0;
}

int Mult::inp_matr(int** matr1, int** matr2, int n)
{
	if (n <= 0) { return -1; }
	vect[i]->inputMatrix(matr1, matr2, n);
	return 0;
}

int** Mult::getResult()
{
	return vect[i]->MatrixMult();
}

int** Mult::getMatrA()
{
	return vect[i]->getMatrixA();
}

int** Mult::getMatrB()
{
	return vect[i]->getMatrixB();
}

int Mult::getComplexity()
{
	return vect[i]->getCount();
}
