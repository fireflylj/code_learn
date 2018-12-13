#include<stdio.h>
#include<string.h>
struct __stu
{
	int num;
	char name;
	double score;
	float math;
};
/*
struct lijie
{
	int num=17;
	char *name="lijie";
};
*/
int main()
{
//struct __stu list ={12,"lijie",44.7,98.8};
struct __stu list ={0};
//struct lijie li;
int a=8;
//string s="tyuiop";
//printf("size of char is %ld\n",sizeof(s));
printf("size of int is %ld\n",sizeof(a));
printf("size of char is %ld\nsize of double is %ld\nsize of float is %ld\n",sizeof(list.name),sizeof(list.score),sizeof(list.math));

int test=5;
int *p;
p=&test;

printf("test:%d\n&test:%p\n",test,&test);
printf("*p:%d\np:%p\n&p:%p\n",*p,p,&p);
//printf("姓名：%c,学号：%d\n",li.name,li.num);
return 0;
}
