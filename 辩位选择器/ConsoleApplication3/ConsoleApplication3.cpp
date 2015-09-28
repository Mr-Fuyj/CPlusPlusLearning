// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
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
	cout << "本人保证本次抽签公正公开否则本人就是孙子……输入“同意”以继续……"<<endl;
	getline(cin, guarantee);
	if (guarantee != "同意"){
		cout << "不同意不能继续……"<<endl;
		main();
	}
	for (i = 0; i < 4; i++){
		cout << "请输入第" << i+1<< "名队员的姓名……或者外号什么的都行……"<<endl;
		getline(cin, name[i]);
	}
	for (i = 0; i < 4; i++){
		choose(n=0,i,chosen[n]);
	}
	cout << "大概就是这个样子……关了我吧……" << endl;
	system("pause");
}

void choose(int n,int i,bool p){
	n = get_rand(4);
	if (!chosen[n-1]){
		cout << name[n-1] << "打" << i + 1 << "辩……"<<endl;
		chosen[n-1] = true;
	}
	else{
		choose(n,i,chosen[n]);
	}
}

int get_rand(int n){
	return rand() % n + 1;
}