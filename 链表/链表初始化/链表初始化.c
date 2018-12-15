#include<stdio.h>
#include<stdlib.h>//链表必须要用到的库
#include"list_init__.h"

#define init_size 100

//int list_init__(&L);
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

int main()
{
//typedef struct L;
//或者
sqlist L;
//L={"lijie",5,100};
//不能像上面一样赋值
L.elem="lijie";
//调用初始化函数
list_init__(L);
printf("初始化结果：%d\n",list_init__(L));
printf("测试----------------------------\n一切正常------------------------\n");
printf("内容显示：elem:%s\n",L.elem);
return 0;
}

