// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#define group_size 3
#define group_sep ','
using namespace std;

string output_formatted_string(long long num);
long long fibo(int n);
void main(){
	int the_number_of_series;
	cout << "input the number of series please:" << endl;
	cin >> the_number_of_series;
	cout << output_formatted_string(fibo(the_number_of_series));
	system("pause");
}

string output_formatted_string(long long num){
	stringstream temp,out;
	temp << num;
	string s(temp.str());
	int n(s.size());
	int i=0;
	if (n % group_size != 0 && n > group_size){
		out << s.substr(i, n % group_size) << group_sep;
		i += n%group_size;
	}
	for (; n - i > group_size; i += group_size){
		out << s.substr(i, group_size) << group_sep;
	}
	out << s.substr(i);
	return out.str();
}

long long fibo(int n){
	long long f_1 = 1;
	long long f_2 = 1;
	long long temp;
	int i;
	if (n <= 2){
		return 1;
	}
	for (i = 3; i <= n; i++){
		temp = f_1 + f_2;
		f_1 = f_2;
		f_2 = temp;
	}
	return temp;
}