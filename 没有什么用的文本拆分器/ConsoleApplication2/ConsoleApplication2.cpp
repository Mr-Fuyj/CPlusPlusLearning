#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

void main(){
	char str[500];
	char *p;
	char *next_token;
	int i=0;
	cout << "input your article please:" << endl;
	cin.getline(str, 500);
	p = strtok_s(str, " ", &next_token);
	while (p){
		cout << p << endl;
		p = strtok_s(NULL, " ", &next_token);
		i++;
	}
	cout << "the number of letters you have input is " << i;
}