// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
	cout << "你想在几件事中做出选择呢……"<<endl;
	cin >> n;
	for (i = 0; i < n; i++){
		char a[50];
		cout << "输入第" << i+1<< "件事吧……"<<endl;
		cin>>a;
		things_to_do[i] = a;
	}
	m = get_rand(n);
	cout << "你大概要……这个……" << endl << things_to_do[m]<<endl;
	system("PAUSE");
}
int get_rand(int n){
	int m;
	m = rand() % n;
	return m;
}