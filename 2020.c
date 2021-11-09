#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void fun(int arr[],int num)
//{
//	int* temp = arr;
//	int min = arr[0];
//	int max = arr[0];
//	int t=0;
//	int s1=0, s2=0;
//	
//	//int* head = *arr;
//	while (t!=num)
//	{
//		if (*temp > max)
//		{
//			max = *temp;
//			s1 = t;
//		}
//		if (*temp < min)
//		{
//			min = *temp;
//			s2 = t;
//		}
//		temp++;
//		t++;
//	}
//	arr[s1] = arr[0];
//	arr[0] = max;
//	arr[s2] = arr[5];
//	arr[5] = min;
	//printf("%d %d\n", s1, s2);
	
	/*for (i = 0; i < num; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
		arr++;
		
	}*/
	/*arr[0] = max;
	arr[6] = min;*/
	
//}
//int main()
//{
//	
//	int arr[6] = { 5,4,3,9,8,12 };
//	int i = 0;
//	int j = 0;
//	fun(arr,6);
//	for (i = 0; i < 6; i++)
//	{
//		
//			
//			printf("%d ", arr[i]);
//		
//	}
//	return 0;
//}
int find(char* str, char* str1)
{
	char* temp=str;
	char* temp1 = str1;
	int count = 0;
	
	while (*str!='\0')
	{
		if (*str == *str1)
		{
			str1++;
			temp = str;
		}
		else
		{
			if(*str1!=*temp1)
				str = temp;
			str1 = temp1;
			
			
		}
		if (*str1 == '\0')
		{
			count++;
			str1 = temp1;
		}
		str++;
	}
	return count;
}
int main()
{
	char* str = "ajddsjsdjsdaddsjsdsajsd";
	char* str1 = "jsd";
	int ret=find(str, str1);
	printf("%d", ret);
	return 0;
}