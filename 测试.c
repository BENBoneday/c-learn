//
#define MAX 20
#define N 3
#include<stdio.h>
#include<assert.h>
#include<string.h>
typedef struct str
{
	char s[MAX];
}str;
void sort(str* s, int sortNum)
{
	assert(s); int i = 0, j = 0;
	str temp;
	if (sortNum == 0)
	{
		for (i = 0; i < N; i++)
		{
			for (j = i + 1; j < N; j++)
			{
				if (strcmp(s[i].s, s[j].s) < 0)
				{
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
	if (sortNum == 1)
	{
		for (i = 0; i < N; i++)
		{
			for (j = i + 1; j < N; j++)
			{
				if (strcmp(s[i].s, s[j].s) > 0)
				{
					temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
}
int main()
{
	str s[N] = {"asdsadsa","nbzczx","nopozxc"};
	int i = 0;
	sort(s,1);
	for (i = 0; i < N; i++)
	{
		printf("%s\n", s[i].s);
	}
	return 0;
}