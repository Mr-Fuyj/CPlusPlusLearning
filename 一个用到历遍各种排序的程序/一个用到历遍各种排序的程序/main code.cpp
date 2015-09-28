#include<iostream>
#define number 10
using namespace std;

int get_the_queue(int*a,int q);
int t[number];
int ct[number];
int member[number];
int cm[number];
int time(1);
void main(){
	int i;
	for (i = 0; i < number; i++){
		member[i] = i;
	}
	get_the_queue(member,0);
}

int get_the_queue(int*a,int q){
	int i = q;
	for (t[i] = i; t[i] <= number+i; t[i]++){
		if (t[i]>number){
			ct[i] = t[i] - number - 1;
		}
		else{ 
			ct[i] = t[i];
		}
		cm[i] = a[ct[i]];
		if (i < number){
			cm[i+1] = get_the_queue(member,q+1);
		}
		if (i == 0){
			int p;
			for (p = 0; p < number; p++){
				cout << cm[p] << " ";
			}
			cout << endl;
			cout << time<<endl;
			time++;
		}
		else{
			return cm[i];
		}
	}
	return 0;
}