#include<iostream>
#include<ctime>
using namespace std;

void p1_1(){
	cout << "hello c++ 1";//简单的输出
	cout << "hello c++ 2";
	cout << "hello c++ 3";
	cout << "hello c++ 4";
}
void p1_2(){
	int x;//声明x
	cin >> x;//接受x
	cout << x;//输出x
}
void swap(int*p1, int*p2){
	*p1 = *p1 + *p2;
	*p2 = *p1 - *p2;
	*p1 = *p1 - *p2;
	/*交换两数的值*/
}
void p1_3(){
	int a, b, c;
	cout << "input the value of a:" << endl;
	cin >> a;
	cout << "input the value of b:" << endl;
	cin >> b;
	cout << "input the value of c:" << endl;
	cin >> c;
	/*获得abc的值*/
	if (a < b){
		swap(a, b);
	}
	if (a < c){
		swap(a, c);
	}
	if (b < c){
		swap(b, c);
	}
	/*对abc进行排序*/
	cout << a << " " << b << " " << c << endl;//输出
}
void p1_4(){
	int i;
	int k;
	int n;
	int m;
	for (i = 0; i < 20; i++){
		for (k = 0; k < 20 - i; k++){
			cout << " ";
		}
		/*输出空格占位*/
		for (n = 0; n < 2 * (i + 1) - 1; n++){
			cout << "*";
		}
		/*输出星号*/
		for (m = 0; m < 40 - 2 - k - n; m++){
			cout << " ";
		}
		/*输出空格占位*/
		cout << endl;
	}
}
void p1_5(){
	int num[10];
	int i;
	int k;
	for (i = 0; i < 10; i++){
		cout << "input the " << i + 1 << " number:" << endl;
		cin >> num[i];
	}
	for (i = 0; i < 9; i++){//最外层循环，共进行九次，完成后最小的数将会到达能到达的最后的位置
		for (k = 0; k < 9 - i; k++){//内层循环，每进行一次外层循环次数就会少一次，比较两个靠近的数并将较小的向下挪
			if (num[k] < num[k + 1]){
				swap(num[k], num[k + 1]);
			}
		}
	}
	for (i = 0; i < 10; i++){
		cout << num[i] << "  ";//输出
	}
}
void hw1_1(){
	int n;
	int i;
	int sum(0);
	cout << "input the last number:" << endl;
	cin >> n;//输入最后的数
	for (i = 1; i <= n; i++){
		sum += i;//将下一个数加到sum里
	}
	cout << sum;
}
void hw1_2(){
	int n;
	int i;
	double m;
	double t;
	double sum(1);
	cout << "input the denominator of the last number:" << endl;
	cin >> n;//获取最后一个数的分母
	for (i = 1; i <= n; i++){
		if (2 % (i+1)){//判断奇偶性
			m = i*1.;//将i转换成double型
			t = 1 / m;//获得分数的值
			sum += t;//加入sum里
		}
		else{
			m = i*1.;
			t = 1 / m;
			sum -= t;
		}//代码与if类似
	}
	cout << sum;
}
int factorial(int n){
	int i;
	int product(1);
	for (i = 1; i <= n; i++){
		product *= i;//计算阶乘
	}
	return product;
}
double lfactorial(int n){
	int i;
	double product(1);
	for (i = 1; i <= n; i++){
		product *= i;//计算较为高阶的阶乘
	}
	return product;
}
void hw1_3(){
	int n;
	int i;
	int sum(0);
	cout << "input the last number:" << endl;
	cin >> n;
	for (i = 1; i <= n; i++){
		sum += factorial(i);//累加阶乘
	}
	cout << sum;
}
void hw1_4(){
	int i;
	int n;
	int sum(2);
	cout << "input a number:";
	cin >> n;
	for (i = 1; i <= 2*n+1; i += 2){
		if (i%4==1){
			sum -= factorial(i);
		}
		else{
			sum += factorial(i);
		}
		/*确定正负号*/
	}
	cout << sum;
}
double power(double x, int n){
	int i;
	double product(1);
	for (i = 1; i <= n; i++){
		product *= x;
	}
	/*计算x的n次方*/
	return product;
}
void hw1_5(){
	int i;
	double n;
	double sum(0);
	bool c(1);
	cout << "input a number:";
	cin >> n;
	for (i = 1;; i += 2){
		if (i % 4 == 1){
			sum += (power(n, i)/lfactorial(i));
		}
		else{
			sum -= (power(n, i)/lfactorial(i));
		}
		/*由于阶乘增长速度很快，必须使用double或longlong型数据*/
		c = ((power(n, i) / lfactorial(i)) - 0.000001<=0);
		if (c){
			break;
		}
	}
	cout << sum; 
}
void hw1_6(){
	int m;
	int n;
	int result;
	cout << "input the number of all the member:";
	cin >> m;
	cout << "input the number of the member you want:";
	cin >> n;
	result = factorial(m) / (factorial(n)*factorial(m - n));
	//普通的阶乘运算
	cout << result;
}
void hw1_7(){
	int i;
	int k(-1);
	double tran;
	double power(0);
	double temp;
	bool c;
	for (i = 2;; i++){
		tran = i*1.;//将i转换成double型
		temp = (tran*(tran + 1)) / ((tran + 2)*(tran + 3)*(tran + 4));
		k = -k;
		power += k*temp;
		c = (temp - 0.000001 <= 0);
		if (c){
			break;
		}
	}
	cout << power;
}
void hw1_8(){
	int i;
	double num(1);
	double den(2);
	double temp;
	double sum(0);
	for (i = 1; i <= 200; i++){
		sum += num / den;
		temp = num + den;
		num = den;
		den = temp;
		/*类似于斐波那契数列的求法*/
	}
	cout << sum;
}
void hw1_9(){
	double PI(0);
	int i;
	int k(-1);
	for (i = 1;; i++){
		k *= -1;
		PI += k*(1 / (2.*i - 1));//其实是四分之PI
		if (2 * i - 1 > 1000000){
			break;
		}
	}
	cout << 4*PI;
}
void hw1_10(){
	int i;
	int n;
	int k;
	cout << "input an odd number:";
	cin >> n;
	for (i = 1; i <= (n+1)/2; i++){
		for (k = 1; k <= i; k++){
			cout << "*";
		}
		cout << endl;
	}
	for (i = ((n+1)/2)+1; i <= n;i++){//接引之前的行数就比较容易写
		for (k = 1; k <= n + 1 - i; k++){
			cout << "*";
		}
		cout << endl;
	}
}
void hw1_11(){
	int i;
	int k;
	for (i = 1; i <= 9; i++){
		for (k = 1; k <= i; k++){
			cout << k << "*" << i << "=" << k*i << "\t";
		}
		cout << endl;
	}
	for (i = 1; i <= 9; i++){
		for (k = 1; k <i; k++){
				cout << "\t";//输出制表符占位
			}
		for (k = i; k <= 9 ;k++){
				cout << i << "*" << k << "=" << i*k << "\t";
			}
		cout << endl;
	}
}
int get_rand(){
	return rand() % 100 + 1;//获得一个1~100之间的随机数
}
void hw1_12(){
	srand(time(NULL));
	int i;
	int n;
	n = get_rand();
	cout << "guess a number from 1 to 100:" << endl;
	cin>>i;
	while (1){
		if (i == n){
			cout << "you are right!" << endl;
			break;//正确则跳出循环
		}
		else if (i < n){
			cout << "the number you input is too small,guess again:" << endl;
			cin >> i;
		}
		else{
			cout << "the number you input is too large,guess again:" << endl;
			cin >> i;
		}
	}
}
void hw1_13(){
	int i;
	int s[10];
	int k;
	for (i = 0; i < 10; i++){
		cout << "input the " << i + 1 << " number:" << endl;
		cin >> s[i];
	}
	for (i = 0; i < 9; i++){
		for (k = 0; k < 9 - i;k++){
			if (s[k] < s[k + 1]){
				swap(s[k], s[k + 1]);
			}
		}
	}
	for (i = 0; i <= 9; i++){
		cout << s[i]<<" "<<endl;
	}
}//跟之前的作业一样
