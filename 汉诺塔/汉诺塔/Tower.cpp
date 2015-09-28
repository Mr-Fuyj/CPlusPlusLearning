#include<iostream>
#include"Tower_class.h"
using namespace std;

void print_a_floor(int n);//done
void print_a_row(int x, int lenth);//done
void get_back(int x);//done
void print_a_tower(Tower*ptower, int number_of_tower);//done
void set_y(Tower*ptower_floor,Tower*ptower,int x);//done
void move_the_tower(int n, Tower*tower, int des);//done
void set_the_tower(int n,Tower*tower);//done
const int Start = 1;
const int Destination = 2;
const int Rest = 3;
const int sum = 6;
int number_of_tower;
int main(){
	cout << "input the height of the tower:" << endl;
	cin >> number_of_tower;
	Tower* ptowers = new Tower [number_of_tower];
	set_the_tower(number_of_tower,ptowers);
	print_a_tower(ptowers,number_of_tower);
	move_the_tower(number_of_tower,ptowers,Destination);
	system("pause");
	return 0;
}
void set_the_tower(int number_of_tower,Tower*ptower){
	for (int i = 0; i < number_of_tower; i++){
		(ptower+i)->set(Start, number_of_tower - i, 2 * (i+1) - 1);//最底层为第一层而非第零层；
	}
}

void move_the_tower(int n,Tower*ptower,int des){
	int now = ptower->x_coordinate;
	int rest = sum - now - des;
	if (n == 2){
		ptower->x_coordinate = rest;
		set_y(ptower,ptower,rest);
		print_a_tower(ptower, number_of_tower);
		(ptower + 1)->x_coordinate = des;
		set_y(ptower + 1,ptower,des);
		print_a_tower(ptower, number_of_tower);
		ptower->x_coordinate = des;
		set_y(ptower, ptower, des);
		print_a_tower(ptower, number_of_tower);
	}
	if (n > 2){
		move_the_tower(n - 1, ptower, rest);
		(ptower + n - 1)->x_coordinate = des;
		set_y(ptower + n - 1,ptower,des);
		print_a_tower(ptower, number_of_tower);
		move_the_tower(n - 1, ptower, des);
		//print_a_tower(ptower, number_of_tower);
	}
}

void print_a_tower(Tower*ptower, int number_of_tower){
	int width = number_of_tower * 2 - 1;
	for (int i = number_of_tower; i >= 1; i--){
		for (int k = 0; k < number_of_tower; k++){
			if ((ptower + k)->y_coordinate == i && (ptower + k)->x_coordinate==3){
				print_a_row((ptower+k)->x_coordinate, 2*(k+1)-1);
				get_back((ptower + k)->x_coordinate);
			}
		}
		for (int k = 0; k < number_of_tower; k++){
			if ((ptower + k)->y_coordinate == i && (ptower + k)->x_coordinate==2){
				print_a_row((ptower + k)->x_coordinate, 2 * (k + 1) - 1);
				get_back((ptower + k)->x_coordinate);
			}
		}
		for (int k = 0; k < number_of_tower; k++){
			if ((ptower + k)->y_coordinate == i && (ptower + k)->x_coordinate==1){
				print_a_row((ptower + k)->x_coordinate, 2 * (k + 1) - 1);
				get_back((ptower + k)->x_coordinate);
			}
		}
		cout << endl;//这里存在一个回车和换行的问题
	}
	cout << "===============================================" << endl;
}

void print_a_row(int x, int lenth){
	for (int i = 1; i < x; i++){
		for (int k = 0; k < (2*number_of_tower)-1; k++){
			cout << " ";
		}
	}
	for (int k = 0; k < ((2 * number_of_tower) - 1 - lenth) / 2; k++){
		cout << " ";
	}
	for (int k = 0; k < lenth; k++){
		cout << "*";
	}
	for (int k = 0; k < ((2 * number_of_tower) - 1 - lenth) / 2; k++){
		cout << " ";
	}
}

void get_back(int x){
	for (int i = 0; i < x; i++){
		for (int k = 0; k < (2 * number_of_tower) - 1; k++){
			cout << "\b";
		}
	}
}

void set_y(Tower*ptower_floor, Tower*ptower,int x){
	int number_of_floor(0);
	for (int i = number_of_tower;; i--){
		if (((ptower + i - 1)->x_coordinate) == x){
			number_of_floor++;
		}
		if ((ptower + i - 1) == ptower_floor){
			break;
		}
	}
	ptower_floor->set_y(number_of_floor);
}
