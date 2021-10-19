#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int* spinarray(int* array,int len,int k)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	int i = 0;
	int j = len-1;
	int count = 0;
	for (i = 0; i < len; i++)
	{
		if (k > 0)
		{
			tmp[i] = array[j];
			k--;
			j--;
		}
		else
		{
			
			tmp[i] = array[count];
			count++;
			
		}
	}
	return tmp;
}
int main()
{
	int* array[] = { 1,2,3,4,5,6,7,8,9 };
	int* ret=spinarray(array, 9,3);
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		printf("%d ", ret[i]);
	}
	return 0;
}