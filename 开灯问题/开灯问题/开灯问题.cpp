//开灯问题
//有1~n（编号）n盏灯（不超过1000盏），k个人（不超过n个），第一个人把所有灯都打开，第二个人按下所有标号为2的倍数的灯，以此类推
//要求：输入n，k，输出开着的灯的编号

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define maxn 1010
bool light[maxn];

int main(){
	memset(light, 0, sizeof(light));
	int n = 0;
	int k = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &k);
	//外循环为人数
	for (int i = 1; i <= k; i++){
		//内循环为灯数
		for (int j = 1; j <= n; j++){
			//如果灯数除以人数余数为零
			if (!(j%i)){
				//该灯反号
				light[j] = !light[j];
			}
		}
	}
	//输出亮着的灯
	for (int i = 1; i <= n; i++){
		if (light[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}

