#include<stdio.h>
#include<stdlib.h>

#define overspace 10


#define init_size 100

//int list_init__(L);
//链表结构体
typedef struct 
{
	char *elem;//链表内容
	int length;//内容长度
	int list_size;//链表长度
}sqlist;

int list_init__(sqlist L)
{
//指针用点，正常用->
//给elem分配内存，(char*)为类型强制转换为char指针指向的地址，malloc后面参数
//为分配地址的大小
L.elem=(char*)malloc(init_size*sizeof(char));
//错误处理
if(!L.elem)
//0表示正常退出，其他为异常
exit(0);
//内容长度初始化
L.length=0;
//链表长度初始化
L.list_size=init_size;
return 1;
}



//插入函数
int list_insert__(sqlist L,int i,char e)
{
//错误处理
if(i<0||i>L.length)
exit -1;//异常退出


/*
//新建存储空间
char *newspace;
if(L.length>=L.list_size)
{
//relloc为重新分配内存的函数
newspace=(char*)realloc(L.elem,(L.length+overspace)*sizeof(char));
if(!newspace)
exit(0);
L.elem=newspace;
//新链表长度
L.list_size+=overspace;
}
*/


//正式插入函数
char *p,*q;
p=&(L.elem[i-1]);//获取插入点地址
for(q=&(L.elem[L.length-1]);q>=p;q--)//i指向的位置小于内容长度时，循环
*(q+1)=*q;//i之后的元素后移一个地址单元
*p=e;//给i点赋插入值
L.length++;
return 1;
}

int main()
{
sqlist L;
list_init__(L);
printf("请输入10个字符：");
for(int i=0;i<10;i++)
{
scanf("%c",&L.elem[i]);
L.length++;
}

list_insert__(L,3,'l');
printf("在3处插入元素l:\n");
for(int i=0;i<10;i++)
{
printf("%c",L.elem[i]);
}
return 0;
}
