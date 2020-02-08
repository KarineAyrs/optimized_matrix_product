#include <iostream>
#include <fstream>
#include "Interface.h"
#include "intrfLang.h"
#include "MatrixTest.h"
#include <math.h>
using namespace std;

int main()
{

	int command;
	Interface intrf;
	intrf.mess_box[0].descr = hello;
	intrf.mess_box[1].descr = inpA;
	intrf.mess_box[2].descr = Asuccess;
	intrf.mess_box[3].descr = Bsuccess;
	intrf.mess_box[4].descr = myself;
	intrf.mess_box[5].descr = dimension;
	intrf.mess_box[6].descr = goodbye;

	intrf.i_b_p[0].f = &(Mult::ordinaryMult);
	intrf.i_b_p[0].descr = onlySquare;
	intrf.i_b_p[0].output = randOrno;
	intrf.i_b_p[0].error = error;

	intrf.i_b_p[1].f = &(Mult::strassenMult);
	intrf.i_b_p[1].descr = onlySquare;
	intrf.i_b_p[1].output = randOrno;
	intrf.i_b_p[1].error = error;

	intrf.i_b_p[2].f = &(Mult::getComplexity);
	intrf.i_b_p[2].descr = complexity;
	intrf.i_b_p[2].output = restartEx;
	intrf.i_b_p[2].error = error;

	intrf.i_s_p[0].f = &(Mult::inp_matr);
	intrf.i_s_p[0].descr = matrxSuccess;
	intrf.i_s_p[0].output = pressMult;
	intrf.i_s_p[0].error = error;

	intrf.i_u_b_p[0].f = &(Mult::getResult);
	intrf.i_u_b_p[0].descr = resultMult;
	intrf.i_u_b_p[0].output = getCompl;
	intrf.i_u_b_p[0].error = error;


	intrf.i_u_b_p[1].f = &(Mult::getMatrA);
	intrf.i_u_b_p[1].descr =matrA;
	intrf.i_u_b_p[1].output = getBmult;
	intrf.i_u_b_p[1].error = error;


	intrf.i_u_b_p[2].f = &(Mult::getMatrB);
	intrf.i_u_b_p[2].descr = matrB;
	intrf.i_u_b_p[2].output = getAmult;
	intrf.i_u_b_p[2].error = error;


	intrf.intrfHelllo();
	
	while (true) {
		cin >> command;
		intrf.intrfWork(command);
		command = -1;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return 0;

		
}









	//MatrixProduct mProduct;
	//OrdinaryMult ordProduct;
	//MatrixTest test;
	//int N = 700;
	//	double time;
	//	int complex = 0;

	//	ofstream info;
	//	info.open("info1.txt", ios::app);
	//	//info << "II      N      time      steps      time/complex       theoretic      theoretic/time  Strassen's Algorithm" << endl;
	//	int theoretic;
	//	theoretic = pow(N, log10(7)/log10(2));
	//	time = test.fastMultTime(&mProduct, N, complex);
	//	info << "      " << N << "      " <<time<<"      "<<complex<<"      "<<time/complex<<"      "<<theoretic<<"      "<<time/theoretic<<endl;

	//	return 0;