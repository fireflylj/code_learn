#include<stdio.h>
#include<stdlib.h>

struct out_of_order
{
int *elem;
int length;
}List;

struct out_of_order L;
//查找函数是否含有x
int find_if_have_x(int x,struct out_of_order L)
{
int i,j;
//for循环找到匹配的则正常返回结束，如果找不到，则顺序向下执行
for(i=0;i<L.length;i++)
{
if(x==L.elem[i])
return 1;
}
return 2;
}
int main()
{
int i,j;
struct out_of_order La,Lb,L;
La.elem=(int*)malloc(La.length*sizeof(int));
Lb.elem=(int*)malloc(Lb.length*sizeof(int));
La.elem[0]=2;
La.elem[1]=5;
La.elem[2]=9;
La.length=3;
Lb.elem[0]=5;
Lb.elem[1]=1;
Lb.elem[2]=0;
Lb.elem[3]=4;
Lb.length=4;

L.elem=(int*)malloc((La.length+Lb.length)*sizeof(int));

for(i=0;i<La.length;i++)
{
L.elem[i]=La.elem[i];
L.length=La.length;
	for(j=0;j<Lb.length;j++)
	{
	if(find_if_have_x(Lb.elem[j],La)==2)
		{
			L.elem[L.length]=Lb.elem[j];
			L.length++;
		}
	}
}

printf("La:");
for(i=0;i<La.length;i++)
{
printf("%d",La.elem[i]);
}
printf("\n");


printf("Lb:");
for(i=0;i<Lb.length;i++)
{
printf("%d",Lb.elem[i]);
}
printf("\n");

printf("L:");
for(i=0;i<L.length;i++)
{
printf("%d",L.elem[i]);
}
printf("\n");
return 0;
}
