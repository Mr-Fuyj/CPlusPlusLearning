// 大小写转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cctype>
#include<string>
using namespace std;

void convert_to_upper(char *s);
void convert_to_lower(char *s);
void main(){
	string a;
	char s[300];
	cout << "输入要转换的字母……" << endl;
	cin.getline(s, 300);
	cout << "输入“大写”或“小写”……" << endl;
	cin >> a;
	if (a == "大写"){
		convert_to_upper(s);
		cout << "大写形式是：" << s;
	}
	else if (a == "小写"){
		convert_to_lower(s);
		cout << "小写形式是：" << s;
	}
	else{
		cout << "输入错误……请重新输入……"<<endl;
		main();
	}
}
void convert_to_upper(char *s){
	int l = strlen(s);
	int i;
	for (i = 0; i < l; i++){
		s[i] = toupper(s[i]);
	}
}
void convert_to_lower(char*s){
	int l = strlen(s);
	int i;
	for (i = 0; i < l; i++){
		s[i] = tolower(s[i]);
	}
}