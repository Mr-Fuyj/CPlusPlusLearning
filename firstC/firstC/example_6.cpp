#include <iostream>   
using namespace std;

int eg6_1(){
	int A[10], B[10];
	int i;
	for (i = 0; i<10; i++){
		A[i] = i * 2 - 1;
		B[10 - i - 1] = A[i];
	}
	for (i = 0; i<10; i++){
		cout << "A[" << i << "]=" << A[i];
		cout << " B[" << i << "]=" << B[i] << endl;
	}
	return 0;
}
void RowSum(int A[][4], int nrow) {
	for (int i = 0; i < nrow; i++){
		for (int j = 1; j < 4; j++)
			A[i][0] += A[i][j];
	}
}
void eg6_2(void){
	int Table[3][4] = { { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 3, 4, 5, 6 } };
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++)
			cout << Table[i][j] << "   ";
		cout << endl;
	}
	RowSum(Table, 3);
	for (int i = 0; i < 3; i++){
		cout << "Sum of row " << i << " is " << Table[i][0] << endl;
	}
}
int eg6_5(){
	int i;
	int *ptr = &i;
	i = 10;
	cout << "i=" << i << endl;
	cout << "*ptr=" << *ptr << endl;
	return 0;
}
int eg6_7_1(){
	int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	for (int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	return 0;
}
int eg6_7_2(){
	int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	for (int i = 0; i < 10; i++){
		cout << *(a + i) << " ";
	}
	return 0;
}
int eg6_7_3(){
	int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	for (int*p = a; p < (a + 10); p++){
		cout << *p << " ";
	}
	return 0;
}
void eg6_8(){
	int line1[] = { 1, 0, 0 };
	int line2[] = { 0, 1, 0 };
	int line3[] = { 0, 0, 1 };
	int *p_line[3]; 
	p_line[0] = line1;   
	p_line[1] = line2;
	p_line[2] = line3;
	cout << "Matrix test:" << endl; 
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++){
			cout << p_line[i][j] << " ";
		}
		cout << endl;
	}
}
void eg6_9(){
	int array2[2][3] = { { 11, 12, 13 }, { 21, 22, 23 } };   
	for (int i = 0; i<2; i++){
		cout << *(array2 + i) << endl;
		for (int j = 0; j<3; j++){
			cout << *(*(array2 + i) + j) << " ";
		}
		cout << endl;
	}
}
void splitfloat(float x, int *intpart, float *fracpart){
	*intpart = int(x);
	*fracpart = x - *intpart;
}

void eg6_10(){
	int i, n;
	float x, f;
	cout << "Enter 3 float point numbers:" << endl;
	for (i = 0; i<3; i++){
		cin >> x;
		splitfloat(x, &n, &f);
		cout << "Integer Part=" << n << " Fraction Part=" << f << endl;
	}
}
