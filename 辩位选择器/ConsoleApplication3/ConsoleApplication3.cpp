// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
using namespace std;

int get_rand(int n);
void choose(int n,int i,bool p);
string name[4];
bool chosen[4];
int i, n(0);
void main(){
	string guarantee;
	srand(time(NULL));
	cout << "���˱�֤���γ�ǩ�������������˾������ӡ������롰ͬ�⡱�Լ�������"<<endl;
	getline(cin, guarantee);
	if (guarantee != "ͬ��"){
		cout << "��ͬ�ⲻ�ܼ�������"<<endl;
		main();
	}
	for (i = 0; i < 4; i++){
		cout << "�������" << i+1<< "����Ա�����������������ʲô�Ķ��С���"<<endl;
		getline(cin, name[i]);
	}
	for (i = 0; i < 4; i++){
		choose(n=0,i,chosen[n]);
	}
	cout << "��ž���������ӡ��������Ұɡ���" << endl;
	system("pause");
}

void choose(int n,int i,bool p){
	n = get_rand(4);
	if (!chosen[n-1]){
		cout << name[n-1] << "��" << i + 1 << "�硭��"<<endl;
		chosen[n-1] = true;
	}
	else{
		choose(n,i,chosen[n]);
	}
}

int get_rand(int n){
	return rand() % n + 1;
}