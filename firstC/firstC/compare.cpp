#include<iostream>
#include<string>
using namespace std;

int compare_str(string a,string b){
	int min=b.length();
	if (a.length()<b.length()){
		min = a.length();
	}
	for (int i = 0; i < min; i++){
		if (a[i] < b[i]){
			return -1;
		}
		else if (a[i]>b[i]){
			return 1;
		}
		else if ((i == min - 1) && a[i] == b[i]&&a.length()==b.length()){
			return 0;
		}
		else if ((i == min - 1) && a[i] == b[i] && a.length() < b.length()){
			return -1;
		}
		else if ((i == min - 1) && a[i] == b[i] && a.length() > b.length()){
			return 1;
		}
	}
}

void compare_test(){
	string a, b;
	int result;
	cout << "input the first string (string a) here:" << endl;
	cin >> a;
	cout << "input the second string (string b) here:" << endl;
	cin >> b;
	result=compare_str(a, b);
	switch (result){
		case -1:{
			cout << "b is bigger than a;" << endl;
			break;
		}
		case 1:{
			cout << "a is bigger than b;" << endl;
			break;
		}
		case 0:{
			cout << "a is equal to b;" << endl;
		}
	}
}