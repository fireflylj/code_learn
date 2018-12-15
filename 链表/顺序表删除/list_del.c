#include<stdio.h>
#include<stdlib.h>

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


/*存在一些问题
//删除
int list_del__(sqlist L,int i)
{
char*p,*q;
//p=&(L.elem[i-1]);
q=&(L.elem[L.length-1]);
for(p=&(L.elem[i-1]);i<L.length-1;++i)
*p=*(p+1);
//L.elem[i]=L.elem[i-1];
L.length-=1;
}
*/

//删除
int list_del__(sqlist L,int i)
{
int j;
for(j=i;j<L.length;j++)
L.elem[j-1]=L.elem[j];
L.length--;
return 0;
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

list_del__(L,3);
printf("删除i=3处的元素:\n");
for(int i=0;i<10;i++)
{
printf("%c",L.elem[i]);
}
printf("\n");
return 0;
}
