#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
char* Judge(char* s,char* t)
{
	assert(s);
	assert(t);
	char* str1 = s;
	//char* cur = s;
	char* str2 = t;
	int count1 = 0;
	int count2 = 0;
	if (strlen(s) != strlen(t))
	{
		return "false";
	}
	else
	{
		for (int i = 0; i < strlen(s); i++)
		{
			int tmp = *(str1 + i);
			while (*str1 != '\0')
			{
				if (*str1 == tmp)
				{
					count1++;
				}
				str1++;
			}
			while (*str2 != '\0')
			{
				if (*str2 == tmp)
				{
					count2++;
				}
				str2++;
			}
			if (count1 != count2)
			{
				return "false";
			}
			count1 = 0;
			count2 = 0;
			str1 = s;
			str2 = t;
		}
	}
	return "true";
}
int main()
{
	char* s = "anagramalll";
	char* t = "nagaramall";
	char* ret = Judge(s, t);
	printf("%s", ret);
	return 0;
}