#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STUDENT_NUM 5
#define SUM_MAX 2
#define AVG_MIN 3
typedef struct Stu
{
	char stuNum[9];
	char name[20];
	double chinese;
	double math;
	double english;
}stu;
void StuInit(stu* s)
{
	/*int i = 0;
	for (i = 0; i < STUDENT_NUM; i++)
	{
		printf("请输入第%d个学生的信息\n", i+1);
		printf("输入顺序为：学号，姓名，语文，数学，英语\n");
		scanf("%s%s%lf%lf%lf", s->stuNum, s->name, &s->chinese,&s->math,&s->english);
	}*/
	strcpy(s[0].stuNum, "1568616"); strcpy(s[0].name, "王多余"); s[0].chinese = 12; s[0].math = 88; s[0].english = 22;
	strcpy(s[1].stuNum, "5154156"); strcpy(s[1].name, "师傅夫"); s[1].chinese = 82; s[1].math = 19; s[1].english = 62;
	strcpy(s[2].stuNum, "2356651"); strcpy(s[2].name, "阿萨德"); s[2].chinese = 18; s[2].math = 15; s[2].english = 66;
	strcpy(s[3].stuNum, "2515651"); strcpy(s[3].name, "那几个"); s[3].chinese = 66; s[3].math = 95; s[3].english = 88;
	strcpy(s[4].stuNum, "1554512"); strcpy(s[4].name, "挺好用"); s[4].chinese = 88; s[4].math = 95; s[4].english = 100;
	//printf("%s", s[0].name);
}
void SumSort(stu* s)
{
	int i, j;
	
	stu tmp;
	for (i = 0; i < STUDENT_NUM; i++)
	{
		for (j = i + 1; j < STUDENT_NUM; j++)
		{
			if ((s[j].chinese + s[j].english + s[j].math) > (s[i].chinese + s[i].english + s[i].math))
			{
				
				tmp = s[i];
				
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
	
	FILE* fp = fopen("sum_max.txt", "w");
	FILE* fp1 = fopen("avg_min.txt", "w");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}
	if (fp1 == NULL)
	{
		printf("打开失败\n");
		return;
	}
	for (i = STUDENT_NUM-1; i >=STUDENT_NUM-AVG_MIN; i--)
	{
		fprintf(fp1, "%s %s %lf %lf %lf\n", s[i].stuNum, s[i].name, s[i].chinese, s[i].math, s[i].english);
	}
	for (i = 0; i < SUM_MAX; i++)
	{
		fprintf(fp, "%s %s %lf %lf %lf\n", s[i].stuNum, s[i].name, s[i].chinese, s[i].math, s[i].english);	
	}
	
	fclose(fp);
	fclose(fp1);
}
//void StuMin(stu* s)
//{
//	int i, j;
//	for (i = 0; i < STUDENT_NUM; i++)
//	{
//		for (j = i + 1; j < STUDENT_NUM; j++)
//		{
//			if()
//		}
//	}
//}
int main()
{
	stu s[STUDENT_NUM];
	StuInit(s);
	SumSort(s);

	return 0;
}