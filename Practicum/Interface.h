#pragma once
#include "Mult.h"
#include <iostream>
#include <string>
using namespace std;

class Interface {
private:
	int SIZE;
	Mult m;
	typedef int (Mult::* Int_bez_param)();
	typedef int (Mult::* Int_s_param)(int**, int**, int);
	typedef int** (Mult::* Int_ukaz_bez_param)();

	struct int_bez_param {
		Int_bez_param f = NULL;
		string descr = "";
		string output = "";
		string error = "";
	};

	struct int_s_param {
		Int_s_param f = NULL;
		string descr = "";
		string output = "";
		string error = "";
	};
	struct int_ukaz_bez_param {
		Int_ukaz_bez_param f = NULL;
		string descr = "";
		string output = "";
		string error = "";
	};

	struct message_box {
		string descr = "";
	};


	void out_matr(int** A1, int N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << A1[i][j] << " ";
			}
			cout << "\n";
		}
	}

	int** alloc_mem(int n) {
		int** res;
		res = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++) {
			res[i] = (int*)malloc(n * sizeof(int));
		}
		return res;
	}

	int** rand_matrix(int n, int rand) {
		int** res;
		res = alloc_mem(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				res[i][j] = i + j + rand;
			}
		}
		return res;
	}


	int** cin_matr(int n) {
		int** res;
		res= alloc_mem(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> res[i][j];
			}
		}
		return res;
	}
public:
	int_bez_param i_b_p[3];
	int_s_param i_s_p[1];
	int_ukaz_bez_param i_u_b_p[3];
	message_box mess_box[10];

	void intrfHelllo() {
		cout << mess_box[0].descr << endl;
	}
	void intrfWork(int command) {
		
		switch (command)
		{
			int** A, ** B;
		case 0:
			cout << i_b_p[0].descr << endl;
			(m.*i_b_p[0].f)();
			cout << i_b_p[0].output << endl;
			break;
		case 1:
			cout << i_b_p[1].descr << endl;
			(m.*i_b_p[1].f)();
			cout << i_b_p[1].output << endl;
			break;
		case 2:
			cout << mess_box[5].descr << endl;
			cin >> SIZE;
			cout << mess_box[1].descr << endl;
			A = cin_matr(SIZE);
			cout << mess_box[2].descr << endl;
			B = cin_matr(SIZE);
			cout << mess_box[3].descr << endl;
			(m.*i_s_p[0].f)(A, B, SIZE);
			cout << i_s_p[0].output << endl;
			break;
		case 3:
			cout << mess_box[4].descr << endl;
			cout << mess_box[5].descr << endl;
			cin >> SIZE;
			A = rand_matrix(SIZE, 2);
			B = rand_matrix(SIZE, 3);
			cout << i_s_p[0].descr << endl;
			(m.*i_s_p[0].f)(A, B, SIZE);
			cout << i_s_p[0].output << endl;
			break;
		case 4:
			int** A1;
			A1 = alloc_mem(SIZE);
			cout << i_u_b_p[1].descr << endl;
			A1 = (m.*i_u_b_p[1].f)();
			out_matr(A1, SIZE);
			cout << i_u_b_p[1].output << endl;
			break;
		case 5:
			cout << i_u_b_p[2].descr << endl;
			A1 = (m.*i_u_b_p[2].f)();
			out_matr(A1, SIZE);
			cout << i_u_b_p[2].output << endl;
			break;
		case 6:
			int** res;
			res = alloc_mem(SIZE);
			cout << i_u_b_p[0].descr << endl;
			res = (m.*i_u_b_p[0].f)();
			out_matr(res, SIZE);
			cout << i_u_b_p[0].output << endl;
			break;
		case 7:
			cout << i_b_p[2].descr << endl;
			cout << (m.*i_b_p[2].f)() << endl;
			cout << i_b_p[2].output << endl;
			break;
		case 8:
			cout << mess_box[0].descr << endl;
			break;
		case 9:
			cout << mess_box[6].descr << endl;
			exit(0);
			break;
		default:
			cout << "wrong command! try again!" << endl;
			break;
		
		}
	
	
	}
};