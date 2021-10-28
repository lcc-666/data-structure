//============================================================================
// Name        : add.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct QNode
{
int data;
struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
QueuePtr front;//队头指针
QueuePtr rear;//队尾指针
}LinkQueue;

int InitQueue(LinkQueue &Q)
{
Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
if(!Q.front)exit(0);
Q.front->next=NULL;
return 0;
}//初始化链式队列

int EnQueue(LinkQueue &Q,int e)
{
QueuePtr p;
p=(QueuePtr)malloc(sizeof(QNode));
if(!p)exit(0);
p->data=e;
p->next=NULL;
Q.rear->next=p;
Q.rear=p;
return 1;
}//在队尾插入元素e

int DeQueue(LinkQueue &Q,int e)
{
QueuePtr p;
if(Q.front==Q.rear)return 0;
p=Q.front->next;
e=p->data;
Q.front->next=p->next;
if(Q.rear==p)Q.rear=Q.front;

free(p);
return 0;
}//删除队头元素e

int PrintQueue(LinkQueue &Q)
{
QueuePtr p;
printf("链式队列中的元素");
if(Q.front->next!=NULL)
{
p=Q.front->next;
if(Q.front->next!=NULL)
do
{
	printf("%5d",p->data);
	p=p->next;
}while(p!=NULL);
}
else
	printf("队列为空\n");
	printf("\n");
return 0;
}//遍历链式队列

int main()
{
 int n,e,i;
LinkQueue Q;
InitQueue(Q);
printf("初始化队列成功！\n");
for(;;)
	{
		printf("请选择要进行的操作:\n");
		printf("1  进队列   2   出队列   3   打印队列    0   退出\n");
		int select;
		scanf("%d",&select);
		if(select==0)
			break;
		switch(select)
		{
		case 0:
			break;
		case 1:
			{int pushelem;
			printf("输入要进队列的元素:    ");
			scanf("%d",&pushelem);
			if(EnQueue(Q,pushelem))
				printf("进队列成功\n");
			else
				printf("进队列失败\n");
			break;}
		case 2:
			{int e;
			if(DeQueue(Q,e))
				printf("出队列成功\n");
			else
				printf("出队列失败\n");
			break;}
		case 3:
			{int e;
			if(PrintQueue(Q))
				printf("\n打印完毕\n");
			break;
		default:
			printf("你进行了误操作，请重新选择:\n");
			break;}
		}
	}
return 1;
}
