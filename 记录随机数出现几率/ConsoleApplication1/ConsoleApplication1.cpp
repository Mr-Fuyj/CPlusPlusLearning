// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int get_rand();
double rate[10];
void main(){
	int n,i,t,p;
	srand(time(NULL));
	cout << "������������������س���";
	cin >> n;
	for (i = 1; i <= n; i++){
		int m = get_rand();
		for (t = 0; t <= 9; t++){
			if (m == t){
				rate[m] += 1;
				break;
			}
		}
	}
	for (p = 0; p <= 9; p++){
		rate[p] = rate[p] / n;
	}
	for (i = 0; i <= 9; i++){
		cout << rate[i] << endl;
	}
	system("pause");
}
int get_rand(){
	return rand()%10;
}