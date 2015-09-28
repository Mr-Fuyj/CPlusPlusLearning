// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
	cout << "要写东西还是读东西呢……（输入“写”或“读”……其他命令是没用的……）"<<endl;
	getline(cin, read_or_write);
	if (read_or_write == "写"){
		input();
		system("pause");
	}
	else if (read_or_write == "读"){
		output();
		system("pause");
	}
	else{
		cout << "都说了别的不行了……真是调皮……重新输一遍吧……"<<endl;
		main();
	}
}

void input(){
	string name;
	string input_line;
	string code;
	cout << "额……给文件取个名字吧……顺便说一句……这个程序挺粗暴的……如果文件跟其他文件重名了那那个文件就没了……" << endl;
	getline(cin, name);
	ofstream file_out(name);
	if (!file_out){
		cout << "总觉得这个名字起得不太对啊……换一个试试吧……" << endl;
		input();
		main();
	}
	cout << "想写点啥就写点啥吧……写完就敲个“@@@”然后敲回车……" << endl;
	while (1){
		getline(cin, input_line);
		code = encryption_(input_line);
		file_out << code << endl;
		if (input_line == "@@@" || input_line == "@@@"){
			cout << "额……弄完了是吧……那我就把自己关了……" << endl;
			cout << "算了……你自己关吧……或者你再想读一遍什么的……" << endl;
			file_out.close();
			main();
		}
	}
}

void output(){
	string name;
	string output_line;
	string code;
	string continue_or_not("继续");
	int i;
	cout << "要打开哪个文件啊……" << endl;
	getline(cin, name);
	ifstream file_in(name);
	if (!file_in){
		cout << "名字打错了吧……再查一遍什么的……重新打一遍吧……" << endl;
		output();
	}
	while (continue_or_not == "继续"){
		for (i = 0; i < 24; i++){
			getline(file_in, output_line);
			code = decryption_(output_line);
			cout << code<<endl;
			if (file_in.eof()){
				break;
			}
		}
		cout << "虽然估计你应该写不了这么多东西……但还是问一句……还要往下看么……看的话输个“继续”什么的……没有什么的……"<<endl;
		getline(cin, continue_or_not);
	}
	cout << "然后……回到最开始那里……" << endl;
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