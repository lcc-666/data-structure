/*
 ============================================================================
 Name        : LinkQueue.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//
#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr Front;
	QueuePtr rear;
}LinkQueue;

int InitQueue(LinkQueue *Q){
	Q->Front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q->Front)exit(0);
	Q->Front->next=NULL;
	return 0;
}

int EnQueue(LinkQueue *Q,int e){
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(0);
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return 1;
}

int DeQueue(LinkQueue *Q,int e){
	QueuePtr p;
	if(Q->Front==Q->rear)return 0;
	p=Q->Front->next;
	e=p->data;
	Q->Front->next=p->next;
	if(Q->rear==p)Q->rear=Q->Front;
	free(p);
	return 1;
}

int PrintQueue(LinkQueue *Q){
	QueuePtr p;
	printf("链式队列中的元素\n");
	if(Q->Front->next!=NULL){
		p=Q->Front->next;
	do
	{
		printf("%d	",p->data);
		p=p->next;
	}while(p!=NULL);
	}
	else
		printf("队列为空\n");
	return 1;
}

void main()
{
 int n,e,i;
LinkQueue Q;
InitQueue(&Q);
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
			if(EnQueue(&Q,pushelem))
				printf("进队列成功\n");
			else
				printf("进队列失败\n");
			break;}
		case 2:
			{int e;
			if(DeQueue(&Q,e))
				printf("出队列成功\n");
			else
				printf("出队列失败\n");
			break;}
		case 3:
			{int e;
			if(PrintQueue(&Q))
				printf("\n打印完毕\n");
			break;
		default:
			printf("你进行了误操作，请重新选择:\n");
			break;}
		}
	}
}
