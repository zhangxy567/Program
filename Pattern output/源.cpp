#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>
// Sleep ������windows�ṩ�ĺ���,��������ʱ���,��ʱ��λ��ms / 1000ms=1s
// Sleep��system("cls")�����γɺܺõĶ�����ʱЧ��
// sizeof�����������������(������������������,Ҳ����������ṹ��)�Ĵ�С(��λ�ֽ�)  
// strlen������ַ�����(���������ַ�)�е�һ���ַ�'\0'ǰ����ַ�����
//
// 
// 
//

#include <iostream>
using namespace std;

int main()
{
	char arrch1[] = "welcome to C++!!!";
	char arrch2[] = "*****************";
	int lefcoor=0;
	int rigtcoor=strlen(arrch1)-1;

	while(lefcoor<=rigtcoor)
	{
		system("cls");
		arrch2[lefcoor] = arrch1[lefcoor];
		arrch2[rigtcoor] = arrch1[rigtcoor];
		printf("%s\n", arrch2);
		lefcoor++;
		rigtcoor--;
		Sleep(700);

	}

	return 0;
}