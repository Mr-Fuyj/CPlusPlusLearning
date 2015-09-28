#include<iostream>
using namespace std;

int eg2_1(){
	cout << "hello!" << endl;
	cout << "welcome to c++!" << endl;
	return 0;
}
int eg2_2(){
	int year;
	bool is_leap_year;
	cout << "enter the year:" << endl;
	cin >> year;
	is_leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (is_leap_year){
		cout << year << "is a leap year" << endl;
	}
	else{
		cout << year << "is not a leap year" << endl;
	}
	return 0;
}
int eg2_3(){
	int x, y;
	cout << "enter x and y:" << endl;
	cin >> x >> y;
	if (x != y){
		if (x > y){
			cout << "x>y" << endl;
		}
		else{
			cout << "x<y" << endl;
		}
	}
	else{
		cout << "x==y" << endl;
	}
	return 0;
}
int eg2_4(){
	int day;
	cin >> day;
	switch (day){
	case 0:{
			   cout << "sunday" << endl;
			   break;
	}
	case 1:{
			   cout << "monday" << endl;
			   break;
	}
	case 2:{
			   cout << "tuesday" << endl;
			   break;
	}
	case 3:{
			   cout << "wednessday" << endl;
			   break;
	}
	case 4:{
			   cout << "thursday" << endl;
			   break;
	}
	case 5:{
			   cout << "friday" << endl;
			   break;
	}
	case 6:{
			   cout << "saturday" << endl;
			   break;
	}
	default:{
				cout << "error!" << endl;
				break;
	}
	}
	return 0;
}
int eg2_5(){
	int i = 1, sum = 0;
	while (i <= 10){
		sum += i;
		i++;
	}
	cout << "sum=" << sum << endl;
	return 0;
}
int eg2_6(){
	int num, right_digit;
	cout << "enter a number" << endl;
	cin >> num;
	do{
		right_digit = num % 10;
		cout << right_digit;
		num /= 10;
	} while (num != 0);
	cout << endl;
	return 0;
}
int eg2_7(){
	int i = 1, sum = 0;
	do{
		sum += i;
		i++;
	} while (i <= 10);
	cout << "sum=" << sum << endl;
	return 0;
}
int eg2_8(){
	int num, i;
	cout << "enter the number:" << endl;
	cin >> num;
	cout << "number " << num << " factors:" << endl;
	for (i = 1; i <= num; i++){
		if (num%i == 0){
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
int eg2_9(){
	const int N = 4;
	for (int i = 1; i <= N;i++){
		for (int j = 1; j <= 30; j++){
			cout << ' ';
		}
		for (int j = 1; j <= 8 - 2 * i; j++){
			cout << ' ';
		}
		for (int j = 1; j <= 2 * i - 1; j++){
			cout << '*';
		}
		cout << endl;
	}
	for (int i = 1; i <= N - 1; i++){
		for (int j = 1; j <= 30; j++){
			cout << ' ';
		}
		for (int j = 1; j <= 7 - 2 * i; j++){
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}
int eg2_10(){
	int i = 0, j = 0, n;
	cout << "enter some integers please(enter 0 to quit):" << endl;
	cin >> n;
	while (n != 0){
		if (n > 0){
			i += 1;
		}
		if (n < 0){
			j += i;
		}
		cin >> n;
	}
	cout << "count of positive integers:" << i << endl;
	cout << "count of negative integers:" << j << endl;
	return 0;
}
int eg2_11(){
	enum game_result{win,lose,tie,cancel};
	game_result result;
	enum game_result omit = cancel;
	for (int count = win; count <= cancel; count++){
		result = game_result(count);
		if (result == omit){
			cout << "the game was cancelled" << endl;
		}
		else{
			cout << "the game was played";
			if (result == win){
				cout << "and we won.";
			}
			if (result == lose){
				cout << "and we lost.";
			}
			cout << endl;
		}
	}
	return 0;
}