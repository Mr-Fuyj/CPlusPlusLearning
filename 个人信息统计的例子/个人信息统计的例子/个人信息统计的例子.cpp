// 个人信息统计的例子.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

void main(){
	char inf[600];
	char name[200];
	char addr[300];
	char work[100];
	cout << "put in your name please:";
	cin.getline(name, 200);
	cout << "put in your address please:";
	cin.getline(addr, 300);
	cout << "put in your work please:";
	cin.getline(work, 100);
	strcpy_s(inf, "\nyour name is ");
	strncat_s(inf, name, 200);
	strcat_s(inf, ",and you live at ");
	strncat_s(inf, addr, 300);
	strcat_s(inf, ",and you works as a ");
	strncat_s(inf, work, 100);
	strcat_s(inf, ".");
	cout << inf;
}
