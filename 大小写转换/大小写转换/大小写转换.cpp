// ��Сдת��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "����Ҫת������ĸ����" << endl;
	cin.getline(s, 300);
	cout << "���롰��д����Сд������" << endl;
	cin >> a;
	if (a == "��д"){
		convert_to_upper(s);
		cout << "��д��ʽ�ǣ�" << s;
	}
	else if (a == "Сд"){
		convert_to_lower(s);
		cout << "Сд��ʽ�ǣ�" << s;
	}
	else{
		cout << "������󡭡����������롭��"<<endl;
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