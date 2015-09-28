#include<iostream>
using namespace std;

int get_the_days(int n);
bool judge_the_year(int n);
void print_the_calendar(int n,int m);
int judge_the_month(int n);
int get_the_week(int n);
int nyear;
void main(){
	int ndays;
	int week;
	int i;
	cout << "input the year:" << endl;
	cin >> nyear;
	ndays = get_the_days(nyear);
	week = get_the_week(ndays);
	for (i = 1; i <= 12; i++){
		cout << i << "月" << endl;
		cout << "周一\t周二\t周三\t周四\t周五\t周六\t周日\t" << endl;
		print_the_calendar(week, i);
		ndays += judge_the_month(i);
		week = get_the_week(ndays);
	}
}

int get_the_days(int n){
	n -= 1;
	return n * 365 + n / 4 - n / 100+n/400;
}

bool judge_the_year(int n){
	if (!(n % 4) &&( n % 100)){
		return 1;
	}
	else if(!(n%400)){
		return 1;
	}
	else{
		return 0;
	}
}

void print_the_calendar(int n,int m){
	int t;
	for (t = 1; t < n; t++){
		cout << " "<<"\t";
	}
	for (t = 1; t <= judge_the_month(m); t++){
		cout << t<< "\t";
		if ((t + n-1) % 7==0){
			cout << endl;
		}
	}
	cout << endl;
}

int judge_the_month(int n){
	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12){
		return 31;
	}
	if (n == 4 || n == 6 || n == 9 || n == 11){
		return 30;
	}
	if (n == 2){
		if (judge_the_year(nyear)){
			return 29;
		}
		else{
			return 28;
		}
	}
}

int get_the_week(int n){
	int week;
	week = n % 7+1;
	return week;
}