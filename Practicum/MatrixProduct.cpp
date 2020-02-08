#include "MatrixProduct.h"

bool MatrixProduct::is_power_of_two(int n){
	while (1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			if (n == 1) {
				return true;
			}
			return false;
		}
	}
}

int MatrixProduct::pow_of_num(int n) {
	int pow = 0;
	while (n / 2 != 0) {
		n /= 2;
		pow++;
	}
	return pow;
}

int MatrixProduct::new_num(int pow){
	int two = 1;
	for (int i = 0; i < pow; i++) {
		two *= 2;
	}
	return two;
}

int** MatrixProduct::alloc_mem(int n){
	int** mas=new int *[n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
	}
	return mas;
}

int** MatrixProduct::zero_fill(int** mas, int size, int n){
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - n; j++) {
			mas[i][j] = 0;
		}
	}

	for (int i = 0; i < size - n; i++) {
		for (int j = 0; j < size; j++) {
			mas[i][j] = 0;
		}
	}
	return mas;
}

int** MatrixProduct::fill_mas(int** mas, int size, int n, int* buff, int beg){
	int g = beg;
	for (int i = size - n; i < size; i++) {
		for (int j = size - n; j < size; j++) {
			mas[i][j] = buff[g];
			g++;
		}
	}
	return mas;
}

int** MatrixProduct::fill_mas(int** mas, int size, int n, int** matr)
{
	int k = -1, h = 0;
	for (int i = size - n; i < size; i++) {
		k++;
		for (int j = size - n; j < size; j++) {
			mas[i][j] = matr[k][h];
			h++;
		}
		h = 0;
	}
	return mas;
}

void MatrixProduct::divideMatrix(int** mas, int m_size, int** m11, int** m12, int** m21, int** m22){

	for (int i = 0; i < m_size / 2; i++) {
		for (int j = 0; j < m_size / 2; j++) {
			m11[i][j] = mas[i][j];
		}
	}

	for (int i = 0; i < m_size / 2; i++) {
		for (int j = m_size / 2; j < m_size; j++) {
			m12[i][j - m_size / 2] = mas[i][j];
		}
	}

	for (int i = m_size / 2; i < m_size; i++) {
		for (int j = 0; j < m_size / 2; j++) {
			m21[i - m_size / 2][j] = mas[i][j];
		}
	}


	for (int i = m_size / 2; i < m_size; i++) {
		for (int j = m_size / 2; j < m_size; j++) {
			m22[i - m_size / 2][j - m_size / 2] = mas[i][j];
		}
	}

}
void MatrixProduct::printMatrix(int** matrix, int m_size, string fname){
	fstream out;
	out.open(fname, ios::out);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			out << matrix[i][j] << " ";
		}
		out << endl;
	}
}
int** MatrixProduct::sumMatrix(int** matrix1, int** matrix2, int size){

	int** result;
	result = alloc_mem(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	return result;
}
int** MatrixProduct::subtrMatrix(int** matrix1, int** matrix2, int size){

	int** result;
	result = alloc_mem(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}

	return result;
}
int** MatrixProduct::concatMatrix(int** C11, int** C12, int** C21, int** C22, int res_size) {
	int** result = alloc_mem(res_size);
	for (int i = 0; i < res_size / 2; i++) {
		for (int j = 0; j < res_size / 2; j++) {
			result[i][j] = C11[i][j];
		}
	}
	for (int i = 0; i < res_size / 2; i++) {
		for (int j = res_size / 2; j < res_size; j++) {
			result[i][j] = C12[i][j - res_size / 2];
		}
	}
	for (int i = res_size / 2; i < res_size; i++) {
		for (int j = 0; j < res_size / 2; j++) {
			result[i][j] = C21[i - res_size / 2][j];
		}
	}
	for (int i = res_size / 2; i < res_size; i++) {
		for (int j = res_size / 2; j < res_size; j++) {
			result[i][j] = C22[i - res_size / 2][j - res_size / 2];
		}
	}
	return result;
}
int** MatrixProduct::ordinaryMult(int** matrix1, int** matrix2, int m_size)
{
	int** result = alloc_mem(m_size);
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			result[i][j] = 0;
		}
	}
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < m_size; j++) {
			for (int k = 0; k < m_size; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
				this->count++;
			}
		}
	}
	return result;
}
int** MatrixProduct::mult(int** matr1, int** matr2, int m_size) {
	if (m_size >= 50) {

		int** A11, ** A12, ** A21, ** A22;
		int** B11, ** B12, ** B21, ** B22;
		int** C11, ** C12, ** C21, ** C22;
		int** P1, ** P2, ** P3, ** P4, ** P5, ** P6, ** P7;
		int** result;
		int half_size = m_size / 2;

		A11 = alloc_mem(half_size);
		A12 = alloc_mem(half_size);
		A21 = alloc_mem(half_size);
		A22 = alloc_mem(half_size);

		B11 = alloc_mem(half_size);
		B12 = alloc_mem(half_size);
		B21 = alloc_mem(half_size);
		B22 = alloc_mem(half_size);

		C11 = alloc_mem(half_size);
		C12 = alloc_mem(half_size);
		C21 = alloc_mem(half_size);
		C22 = alloc_mem(half_size);

		P1 = alloc_mem(half_size);
		P2 = alloc_mem(half_size);
		P3 = alloc_mem(half_size);
		P4 = alloc_mem(half_size);
		P5 = alloc_mem(half_size);
		P6 = alloc_mem(half_size);
		P7 = alloc_mem(half_size);

		divideMatrix(matr1, m_size, A11, A12, A21, A22);
		divideMatrix(matr2, m_size, B11, B12, B21, B22);

		P1 = mult(sumMatrix(A11, A22, half_size), sumMatrix(B11, B22, half_size), half_size);
		P2 = mult(sumMatrix(A21, A22, half_size), B11, half_size);
		P3 = mult(A11, subtrMatrix(B12, B22, half_size), half_size);
		P4 = mult(A22, subtrMatrix(B21, B11, half_size), half_size);
		P5 = mult(sumMatrix(A11, A12, half_size), B22, half_size);
		P6 = mult(subtrMatrix(A21, A11, half_size), sumMatrix(B11, B12, half_size), half_size);
		P7 = mult(subtrMatrix(A12, A22, half_size), sumMatrix(B21, B22, half_size), half_size);

		C11 = sumMatrix(sumMatrix(P1, P7, half_size), subtrMatrix(P4, P5, half_size), half_size);
		C12 = sumMatrix(P3, P5, half_size);
		C21 = sumMatrix(P2, P4, half_size);
		C22 = sumMatrix(sumMatrix(P1, P6, half_size), subtrMatrix(P3, P2, half_size), half_size);

		result = concatMatrix(C11, C12, C21, C22, m_size);
		return result;
	}
	else {
		int** result;
		result = ordinaryMult(matr1, matr2, m_size);
		return result;
	}
}
int** MatrixProduct::vinMult(int** matr1, int** matr2, int m_size)
{
	if (m_size >= 50) {//50

		int** A11, ** A12, ** A21, ** A22;
		int** B11, ** B12, ** B21, ** B22;
		int** C11, ** C12, ** C21, ** C22;
		int** P1, ** P2, ** P3, ** P4, ** P5, ** P6, ** P7;
		int** S1, ** S2, ** S3, ** S4, ** S5, ** S6, ** S7, **S8;
		int** T1, ** T2;
		int** result;
		int half_size = m_size / 2;

		A11 = alloc_mem(half_size);
		A12 = alloc_mem(half_size);
		A21 = alloc_mem(half_size);
		A22 = alloc_mem(half_size);

		B11 = alloc_mem(half_size);
		B12 = alloc_mem(half_size);
		B21 = alloc_mem(half_size);
		B22 = alloc_mem(half_size);

		C11 = alloc_mem(half_size);
		C12 = alloc_mem(half_size);
		C21 = alloc_mem(half_size);
		C22 = alloc_mem(half_size);

		P1 = alloc_mem(half_size);
		P2 = alloc_mem(half_size);
		P3 = alloc_mem(half_size);
		P4 = alloc_mem(half_size);
		P5 = alloc_mem(half_size);
		P6 = alloc_mem(half_size);
		P7 = alloc_mem(half_size);

		S1 = alloc_mem(half_size);
		S2 = alloc_mem(half_size);
		S3 = alloc_mem(half_size);
		S4 = alloc_mem(half_size);
		S5 = alloc_mem(half_size);
		S6 = alloc_mem(half_size);
		S7 = alloc_mem(half_size);
		S8 = alloc_mem(half_size);

		T1 = alloc_mem(half_size);
		T2 = alloc_mem(half_size);

		divideMatrix(matr1, m_size, A11, A12, A21, A22);
		divideMatrix(matr2, m_size, B11, B12, B21, B22);

		S1 = sumMatrix(A21, A22, half_size);
		S2 = subtrMatrix(S1, A11, half_size);
		S3 = subtrMatrix(A11, A21, half_size);
		S4 = subtrMatrix(A12, S2, half_size);
		S5 = subtrMatrix(B12, B11, half_size);
		S6 = subtrMatrix(B22, S5, half_size);
		S7 = subtrMatrix(B22, B12, half_size);
		S8 = subtrMatrix(S6, B21, half_size);

		P1 = vinMult(S2, S6, half_size);
		P2 = vinMult(A11, B11, half_size);
		P3 = vinMult(A12, B21, half_size);
		P4 = vinMult(S3, S7, half_size);
		P5 = vinMult(S1, S5, half_size);
		P6 = vinMult(S4, B22, half_size);
		P7 = vinMult(A22, S8, half_size);
		
		T1 = sumMatrix(P1, P2, half_size);
		T2 = sumMatrix(T1, P4, half_size);

		C11 = sumMatrix(P2, P3, half_size);
		C12 = sumMatrix(sumMatrix(T1, P5, half_size), P6, half_size);
		C21 = subtrMatrix(T2, P7, half_size);
		C22 = sumMatrix(T2, P5, half_size);

		result = concatMatrix(C11, C12, C21, C22, m_size);
		return result;
	}
	else {
		int** result;
		result = ordinaryMult(matr1, matr2, m_size);
		return result;
	}
}
int MatrixProduct::getMatrSize() {
	if (!isPowOfTwo) {
		return oldsize;
	}
	return matr_size;
}
int** MatrixProduct::MatrixMult() {
	int** AB;
	AB = alloc_mem(matr_size);
	AB = mult(A, B, matr_size);
	if (!isPowOfTwo) {
		ABres = alloc_mem(oldsize);
		for (int i = matr_size - oldsize; i < matr_size; i++) {
			for (int j = matr_size - oldsize; j < matr_size; j++) {
				ABres[i - matr_size + oldsize][j - matr_size + oldsize] = AB[i][j];
			}
		}
		printMatrix(ABres, oldsize, "out.txt");
		return ABres;
	}
	ABres = alloc_mem(matr_size);
	ABres = AB;
	printMatrix(ABres, matr_size, "out.txt");
	return ABres;

}

int** MatrixProduct::VinogradovMult()
{
	int** AB;
	AB = alloc_mem(matr_size);
	AB = vinMult(A, B, matr_size); 
	if (!isPowOfTwo) {
		ABres = alloc_mem(oldsize);
		for (int i = matr_size - oldsize; i < matr_size; i++) {
			for (int j = matr_size - oldsize; j < matr_size; j++) {
				ABres[i - matr_size + oldsize][j - matr_size + oldsize] = AB[i][j];
			}
		}
		printMatrix(ABres, oldsize, "out.txt");
		return ABres;
	}
	ABres = alloc_mem(matr_size);
	ABres = AB;
	printMatrix(ABres, matr_size, "out.txt");
	return ABres;
}

void MatrixProduct::scanMatrix(string fname){
	
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
		isPowOfTwo = is_power_of_two(matr_size);
		if (!isPowOfTwo) {
			int pow = pow_of_num(matr_size);
			oldsize = matr_size;
			matr_size = new_num(pow + 1);

		}
		else {
			oldsize = matr_size;
		}
		A = alloc_mem(matr_size);
		A = zero_fill(A, matr_size, oldsize);
		A = fill_mas(A, matr_size, oldsize, buff, 0); 
		B = alloc_mem(matr_size);
		B = zero_fill(B, matr_size, oldsize);
		B = fill_mas(B, matr_size, oldsize, buff, buff_len / 2);
	}
	in.close();
}

void MatrixProduct::inputMatrix(int** matr1, int** matr2, int size)
{
	matr_size = size;
	isPowOfTwo = is_power_of_two(matr_size);
	if (!isPowOfTwo) {
		int pow = pow_of_num(matr_size);
		oldsize = matr_size;
		matr_size = new_num(pow + 1);

	}
	else {
		oldsize = matr_size;
	}
	A = alloc_mem(matr_size);
	A = zero_fill(A, matr_size, oldsize);
	A = fill_mas(A, matr_size, oldsize, matr1);
	B = alloc_mem(matr_size);
	B = zero_fill(B, matr_size, oldsize);
	B = fill_mas(B, matr_size, oldsize, matr2);
}
int** MatrixProduct::getMatrixA()
{
	return A;
}

int** MatrixProduct::getMatrixB()
{
	return B;
}


int MatrixProduct::getCount()
{
	return this->count;
}
