// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int get_rand(int i);
void main(){
	int n;
	int i;
	int m;
	srand(time(NULL));
	string things_to_do[20];
	cout << "�����ڼ�����������ѡ���ء���"<<endl;
	cin >> n;
	for (i = 0; i < n; i++){
		char a[50];
		cout << "�����" << i+1<< "���°ɡ���"<<endl;
		cin>>a;
		things_to_do[i] = a;
	}
	m = get_rand(n);
	cout << "����Ҫ�����������" << endl << things_to_do[m]<<endl;
	system("PAUSE");
}
int get_rand(int n){
	int m;
	m = rand() % n;
	return m;
}