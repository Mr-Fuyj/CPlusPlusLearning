//��������
//��1~n����ţ�nյ�ƣ�������1000յ����k���ˣ�������n��������һ���˰����еƶ��򿪣��ڶ����˰������б��Ϊ2�ı����ĵƣ��Դ�����
//Ҫ������n��k��������ŵĵƵı��

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
	//��ѭ��Ϊ����
	for (int i = 1; i <= k; i++){
		//��ѭ��Ϊ����
		for (int j = 1; j <= n; j++){
			//�������������������Ϊ��
			if (!(j%i)){
				//�õƷ���
				light[j] = !light[j];
			}
		}
	}
	//������ŵĵ�
	for (int i = 1; i <= n; i++){
		if (light[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}

