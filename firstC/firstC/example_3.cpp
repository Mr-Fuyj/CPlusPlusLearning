#include<iostream>
#include <cstdlib>   
#include<iomanip>
#include<cmath>
using namespace std;

double power(double x, int n){
	double val = 1.0;
	while (n--){
		val *= x;
	}
	return val;
}
int change(char*ch){
	int sum=0;
	int j = 0;
	for (int i = 7; i >= 0; i--){
		if (ch[j] == '1'){
			sum += power(2, i);
		}
		j++;
	}
	return sum;
}
void test_1(){
	char bin[9];
	cout << "输入一个八位二进制数：" << endl;
	cin >> bin;
	int num;
	num = change(bin);
	cout << num;
}
double arctan(double x){
	int i;
	double r, e, f, sqr;
	sqr = x*x;
	r = 0;
	e = x;
	i = 1;
	while (e / i>1e-15){
		f = e / i;
		r = (i % 4 == 1) ? r + f : r - f;
		e = e*sqr;
		i += 2;
	}
	return  r;
}
bool symm(long n){
	long i, m;
	i = n;  m = 0;
	while (i){
		m = m * 10 + i % 10;
		i = i / 10;
	}
	return (m == n);
}
double tsin(double x)
{
	double p = 0.000001, g = 0, t = x;
	int n = 1;
	do {
		g = g + t;
		n++;
		t = -t*x*x / (2 * n - 1) / (2 * n - 2);
	} while (fabs(t) >= p);
	return g;
}
int rolldice();
int test_2(){
	int gamestatus, sum, mypoint;
	unsigned seed;
	cout << "Please enter an unsigned integer:";
	cin >> seed;
	srand(seed);
	sum = rolldice(); 
	switch (sum)
	{
	case 7:   
	case 11:
		gamestatus = 1;
		break;
	case 2:   
	case 3:
	case 12:
		gamestatus = 2;
		break;
	default:   
		gamestatus = 0;
		mypoint = sum;
		cout << "point is " << mypoint << endl;
		break;
	}
	while (gamestatus == 0)  {
		sum = rolldice();
		if (sum == mypoint)    
			gamestatus = 1;
		else
		if (sum == 7)    
			gamestatus = 2;
	}
	if (gamestatus == 1)
		cout << "player wins\n";
	else
		cout << "player loses\n";
	return 0;
}
int rolldice(void){ 
	int die1, die2, worksum;
	die1 = 1 + rand() % 6;
	die2 = 1 + rand() % 6;
	worksum = die1 + die2;
	cout << "player rolled " << die1 << '+' << die2 << '=' << worksum << endl;
	return worksum;
}
int test_3(){
	int a, b;
	int fun1(int x, int y);
	cin >> a >> b;
	cout << "a、b的平方和：" << fun1(a, b) << endl;
	return 0;
}
int fun1(int x, int y){
	int fun2(int m);
	return (fun2(x) + fun2(y));
}
int fun2(int m){
	return (m*m);
}
long fac(int n){
	long f;
	if (n<0) cout << "n<0,data error!" << endl;
	else if (n == 0) f = 1;
	else f = fac(n - 1)*n;
	return(f);
}
int comm(int n, int k){
	if (k>n)
		return 0;
	else if (n == k || k == 0)
		return 1;
	else
		return  comm(n - 1, k) + comm(n - 1, k - 1);
}
void move(char getone, char putone){
	cout << getone << "-->" << putone << endl;
}
void hanoi(int n, char one, char two, char three){
	void move(char getone, char putone);
	if (n == 1) move(one, three);
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}
int test_4(){
	void hanoi(int n, char one, char two, char three);
	int m;
	cout << "Enter the number of diskes:";
	cin >> m;
	cout << "the steps to moving " << m << " diskes:" << endl;
	hanoi(m, 'A', 'B', 'C');
	return 0;
}
void Swap(int &a, int &b){
	int t;
	t = a;
	a = b;
	b = t;
}
inline double CalArea(double radius){
	return 3.14*radius*radius;
}
int get_volume(int length, int width = 2, int height = 3){
	cout << setw(5) << length << setw(5) << width << setw(5) << height << ' ';
	return length * width * height;
}
int sum_of_square(int a, int b){
	return a*a + b*b;
}
double sum_of_square(double a, double b){
	return a*a + b*b;
}
int test_5(){
	const double PI = 3.14159265358979;
	double angle;
	cout << "please enter an angle:";
	cin >> angle;
	double radian = angle*PI / 180;
	cout << "sin(" << angle << ")=" << sin(radian) << endl;
	cout << "cos(" << angle << ")=" << cos(radian) << endl;
	cout << "tan(" << angle << ")=" << tan(radian) << endl;
	return 0;
}