#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <iostream>
using namespace std;

int main()
{ 
	char charget[20] = { 0 };
	printf("******************�Ƿ�ػ�?**************** \n");
	printf("***����y:һ���Ӻ�ػ�   ****   ����n:ȡ���ػ�***\n");
	errorto:
	scanf("%s", charget);
	if (strcmp("y", charget) == 0)
	{
		printf("����ɹ�,һ���Ӻ�ػ�\n");
		system("shutdown -s -t 60");
		goto errorto;
	}

	else if (strcmp("n", charget) == 0)
	{
		system("shutdown -a");
		printf("ȡ���ػ��ɹ�!!!\n");
		goto errorto;
	}
	else
	{
		printf("�������,��������\n");
		goto errorto;
	}

	return 0;
}