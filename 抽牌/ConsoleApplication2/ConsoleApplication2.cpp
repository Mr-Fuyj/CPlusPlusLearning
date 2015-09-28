
#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

bool card_condition[52];
char*card_number[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
char*card_type[4] = { "红桃", "黑桃", "方片", "梅花" };
int get_rand(int n);
void get_card();
void main(){
	int n;
	int i;
	srand(time(NULL));
	cout << "请输入要抽取的牌数：";
	cin >> n;
	for (i = 1; i <= n; i++){
		get_card();
	}
	system("pause");
}
void get_card(){
	int m, cn, ct;
	m = get_rand(52);
	if (card_condition[m]){
		get_card();
	}
	else{
		cn = m % 13;
		ct = m % 4;
		cout << card_type[ct] << card_number[cn] << endl;
		card_condition[m] = true;
	}
}
int get_rand(int n){
	return rand() % n;
}