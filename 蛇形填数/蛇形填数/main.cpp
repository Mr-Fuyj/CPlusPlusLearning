//在n*n的方阵中蛇形填入1~n*n
#include <stdio.h>
#include<string.h>
#define maxn 20
int matrix[maxn][maxn];
int main(){
	for (int i = 0; i < maxn; i++){
		for (int j = 0; j < maxn; j++){
			matrix[i][j] = 0;
		}
	}
	int lengthOfSide = 0;
	int count = 1;
	int x = 0, y = 0;
	scanf_s("%d", &lengthOfSide);
	for (int i = 0; i <= lengthOfSide - 1; i++){
		for (int j = 0; j <= lengthOfSide - 1; j++){
			matrix[i][j] = 1;
		}
	}
	y = lengthOfSide - 1;
	while (count < lengthOfSide*lengthOfSide){
		while ((x < y )/*&& (matrix[x][y] == 1)*/){
			x++; 
			matrix[x][y] += matrix[x - 1][y];
			count++; 
		}
		while ((y > lengthOfSide - 1-x)/* && (matrix[x][y]==1)*/){
			y--; 
			matrix[x][y] += matrix[x][y + 1]; 
			count++;
		}
		while ((x > y) /*&& (matrix[x][y] == 1)*/){
			x--; 
			matrix[x][y] += matrix[x + 1][y]; 
			count++; 
		}
		while ((y < (lengthOfSide - 2 - x)) /*&& (matrix[x][y] == 1)*/){
			y++; 
			matrix[x][y] += matrix[x][y - 1]; 
			count++; 
		}
	}
	for (int i = 0; i < lengthOfSide; i++){
		for (int j = 0; j < lengthOfSide; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}