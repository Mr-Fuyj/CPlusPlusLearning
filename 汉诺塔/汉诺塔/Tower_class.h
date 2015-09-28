#include<iostream>
using namespace std;

class Tower{
public:
	int x_coordinate;
	int y_coordinate;
private:
	int length;
public:
	void set(int x, int y, int len){
		x_coordinate = x;
		y_coordinate = y;
		length = len;
	}
	void set_y(int y){
		y_coordinate = y;
	}
};