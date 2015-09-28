// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int array[10];
void swap(int*p1,int*p2);
void get_the_order(int a);
void main(){
	int i;
	for (i = 0; i <= 9; i++){
		cout << "请输入第" << i+1 << "个数据：";
		cin >> array[i];
	}
	cout << "您输入的数列为：";
	for (i = 0 ; i < 9; i++){
		cout << array[i] << ",";
	}
	cout << array[9] << endl;
	get_the_order(10);
	cout << "排序后的数列为：";
	for (i = 0; i < 9; i++){
		cout << array[i] << ",";
	}
	cout << array[9] << endl;
}
void get_the_order(int n){
	int i;
	int m;
	for (i = 0; i <= n - 1; i++){
		for (m = i + 1; m <= n-1; m++){
			if (array[i]>array[m]){
				swap(&array[i], &array[m]);
			}
		}
	}
}
void swap(int*p1, int*p2){
	int m;
	m = *p1;
	*p1 = *p2;
	*p2 = m;
}