#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define N 3
typedef struct SaleTime
{
	int year;
	int month;
	int date;
}STime;
typedef struct Goods
{
	int id;
	char name[20];
	STime time;
	double price;
	int num;//数量
}goods;
void write(goods* g)
{
	//int i;
	g[0].id = 9; strcpy(g[0].name,"王老吉") ; g[0].time.year = 2021; g[0].time.month = 6; g[0].time.date = 20; g[0].price = 5.5; g[0].num = 55;
	g[1].id = 2; strcpy(g[1].name, "老干妈"); g[1].time.year = 2018; g[1].time.month = 7; g[1].time.date = 20; g[1].price = 10.3; g[1].num = 20;
	g[2].id = 10; strcpy(g[2].name,"康师傅");g[2].time.year = 2033; g[2].time.month = 10; g[2].time.date = 20; g[2].price = 500.2; g[2].num = 100;
	
}
void swap(goods* g1,goods* g2)
{
	goods tmp;
	tmp = *g1;
	*g1 = *g2;
	*g2 = tmp;
}
void Sort(goods* g)
{
	assert(g);
	int i = 0,j=0;
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (g[i].time.year < g[j].time.year)
			{
				swap(&g[i], &g[j]);

			}
			else if (g[i].time.year == g[j].time.year)
			{
				if (g[i].time.month < g[j].time.month)
				{
					swap(&g[i], &g[j]);
				}
				else if (g[i].time.month == g[j].time.month)
				{
					if (g[i].time.date < g[j].time.date)
					{
						swap(&g[i], &g[j]);
					}
				}
			}
		}

	}
}
int main()
{
	//goods g[N];
	
	//write(g);
	FILE* fp = fopen("sell.txt", "r");
	/*fprintf(fp, "%d %s %d-%d-%d %lf %d\n", g[0].id, g[0].name, g[0].time.year, g[0].time.month, g[0].time.date, g[0].price, g[0].num);
	fprintf(fp, "%d %s %d-%d-%d %lf %d\n", g[1].id, g[1].name, g[1].time.year, g[1].time.month, g[1].time.date, g[1].price, g[1].num);
	fprintf(fp, "%d %s %d-%d-%d %lf %d\n", g[2].id, g[2].name, g[2].time.year, g[2].time.month, g[2].time.date, g[2].price, g[2].num);
	*/
	goods g1[N];
	int i = 0;
	int sum = 0;
	double avergePrice = 0.00;
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%d %s %d-%d-%d %lf %d", &(g1[i].id), g1[i].name, &(g1[i].time.year), &(g1[i].time.month), &(g1[i].time.date), &(g1[i].price), &(g1[i].num));
	}
	//fprintf(stdout, "%d, %s, %d-%d-%d, %d, %d\n", g[2].id, g[2].name, g[2].time.year, g[2].time.month, g[2].time.date, g[2].price, g[2].num);
	//fprintf(stdout, "%d, %s, %d-%d-%d, %lf, %d\n", g1[2].id, g1[2].name, g1[2].time.year, g1[2].time.month, g1[2].time.date, g1[2].price, g1[2].num);
	Sort(&g1);
	for (int i = 0; i < N; i++)
	{
		printf("%d, %s ,%d-%d-%d, %lf, %d\n", g1[i].id, g1[i].name, g1[i].time.year, g1[i].time.month, g1[i].time.date, g1[i].price, g1[i].num);
		sum += g1[i].price;

	}
	avergePrice = sum / N + sum % N;
	printf("总金额为%d 平均价为%lf", sum, avergePrice);
	//printf("%lf", g1[1].price);
	fclose(fp);

	
	return 0;
}
