#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<sys/timeb.h>
#define MAX 100000
long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}
void Print(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void InsertSort(int arr[], int length)
{
	int j;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}
void ShellSort(int arr[],int length)
{
	int increasement=length;
	int i, j, k;
	do
	{
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++)
		{
			for (j = i + increasement; j<length; j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement>1);
}
int main()
{
	int arr[MAX];
	int arr1[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		int randNum = rand() % MAX;
		arr[i] = randNum;
		arr1[i] = randNum;
	}
	//int arr1[10] = { 3,3,55,6,48,88,99,100,0,77 };
	//Print(arr, MAX);
	long tShellStart = getSystemTime();
	ShellSort(arr, MAX);
	long tShellEnd = getSystemTime();
	printf("希尔排序排%d个元素需要%ldms的时间\n", MAX, tShellEnd - tShellStart);
	//Print(arr, MAX);

	long tInsertStart = getSystemTime();
	InsertSort(arr1, MAX);
	long tInsertEnd = getSystemTime();
	printf("插入排序排%d个元素需要%ldms的时间", MAX, tInsertEnd - tInsertStart);
	return 0;
}