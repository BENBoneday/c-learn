#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int* singNumber(int* nums, int numSize, int* returnSize)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < numSize; ++i)
	{
		ret ^= nums[i];
	}
	//找出第m位为1
	int m = 0;
	while (m < 32)
	{
		if (ret & (1 << m))
		{
			break;
		}
		else
		{
			++m;
		}

	}
	//分离数字
	int x1 = 0, x2 = 0;
	for (i = 0; i < numSize; ++i)
	{
		if (nums[i] & (1 << m))
		{
			x1 ^= nums[i];
		}
		else
		{
			x2 ^= nums[i];
		}
	}
	int* retArray = (int*)malloc(sizeof(int) * 2);
	retArray[0] = x1;
	retArray[1] = x2;
	*returnSize = 2;
	return retArray;
}
int main()
{
	int arr[6] = { 0,6,3,4,2,7 };
	int* size=arr;
	int* ret = singNumber(arr,6,size);
	printf("%d %d", ret[0],ret[1]);
	
	return 0;
}