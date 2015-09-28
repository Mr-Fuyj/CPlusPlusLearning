// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<ctime>
using namespace std;

string encryption_(string p);
string decryption_(string p);
void input();
void output();

void main(){
	string read_or_write;
	cout << "Ҫд�������Ƕ������ء��������롰д���򡰶�����������������û�õġ�����"<<endl;
	getline(cin, read_or_write);
	if (read_or_write == "д"){
		input();
		system("pause");
	}
	else if (read_or_write == "��"){
		output();
		system("pause");
	}
	else{
		cout << "��˵�˱�Ĳ����ˡ������ǵ�Ƥ����������һ��ɡ���"<<endl;
		main();
	}
}

void input(){
	string name;
	string input_line;
	string code;
	cout << "������ļ�ȡ�����ְɡ���˳��˵һ�䡭���������ͦ�ֱ��ġ�������ļ��������ļ����������Ǹ��ļ���û�ˡ���" << endl;
	getline(cin, name);
	ofstream file_out(name);
	if (!file_out){
		cout << "�ܾ������������ò�̫�԰�������һ�����԰ɡ���" << endl;
		input();
		main();
	}
	cout << "��д��ɶ��д��ɶ�ɡ���д����ø���@@@��Ȼ���ûس�����" << endl;
	while (1){
		getline(cin, input_line);
		code = encryption_(input_line);
		file_out << code << endl;
		if (input_line == "@@@" || input_line == "@@@"){
			cout << "���Ū�����ǰɡ������ҾͰ��Լ����ˡ���" << endl;
			cout << "���ˡ������Լ��ذɡ��������������һ��ʲô�ġ���" << endl;
			file_out.close();
			main();
		}
	}
}

void output(){
	string name;
	string output_line;
	string code;
	string continue_or_not("����");
	int i;
	cout << "Ҫ���ĸ��ļ�������" << endl;
	getline(cin, name);
	ifstream file_in(name);
	if (!file_in){
		cout << "���ִ���˰ɡ����ٲ�һ��ʲô�ġ������´�һ��ɡ���" << endl;
		output();
	}
	while (continue_or_not == "����"){
		for (i = 0; i < 24; i++){
			getline(file_in, output_line);
			code = decryption_(output_line);
			cout << code<<endl;
			if (file_in.eof()){
				break;
			}
		}
		cout << "��Ȼ������Ӧ��д������ô�ණ��������������һ�䡭����Ҫ���¿�ô�������Ļ������������ʲô�ġ���û��ʲô�ġ���"<<endl;
		getline(cin, continue_or_not);
	}
	cout << "Ȼ�󡭡��ص��ʼ�����" << endl;
	main();
}

string encryption_(string p){
	char a[1000];
	string d;
	int i;
	strncpy_s(a, p.c_str(), p.length());
	for (i = 0; i <= 999 && a[i]; i++){
		a[i]+=1;
	}
	d = a;
	return d;
}

string decryption_(string p){
	char a[1000];
	int i;
	string f;
	strncpy_s(a, p.c_str(), p.length());
	for (i = 0; i <= 999 && a[i]; i++){
		a[i] -= 1;
	}
	f = a;
	return f;
}