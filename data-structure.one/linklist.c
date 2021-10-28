/*
 ============================================================================
 Name        : linklist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
typedef int Elemtype;
typedef int Status;
typedef struct node//定义存储节点
{
	int data;//数据域
	struct node *next;//结构体指针
} *linklist,node;//结构体变量，结构体名称

linklist creat(int n)
{
	linklist head,p;
	int x,i;
	head=(node *)malloc(sizeof(node));
	printf("请依次%d个输入数据\n",n);
	for(i=n;i>0;i--){
		getchar();
		scanf("%d",&x);
		p=(node *)malloc(sizeof(node));
		p->data=x;
		p->next=head->next;
		head->next=p;
	}
return head;
}
Status insert ( linklist *l,int i, Elemtype e)//插入操作
{
	int j=0;
	linklist p=l,s;
	while(j<i-1 && p)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i-1){
			printf("无法插入");
			return 0;
	}
	else
	{
		s=(node *)malloc(sizeof(node));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return 1;
	}
}

Status delect(linklist *l,int i,Elemtype *e)
{
	int j=0;
	linklist p=l,q;
	while(j<i-1 && p->next)
	{
		p=p->next;
			++j;
	}
	if(!p->next || j>i-1){
		printf("无法删除");
		return 0;
	}
	else
	{
		q=p->next;
		p->next=q->next;
		e=q->data;
		free(q);
		return 1;
	}
}

void output(linklist head)
{
	linklist p;
	p=head->next;
	do
	{
		printf("%3d",p->data);
		p=p->next;
	}
	while(p);
	printf("\n");
}
Status GetElem(linklist l,int i,Elemtype *e )//查找操作
{
	 linklist p;
	 int j;
	 p=l->next;
	 j=1;
	 while(p && j<i)
	 {
		 p=p->next;
		 ++j;
	 }
	 if(!p || j>i){
		 printf("无法查找");
		 return 0;
	 }
	 e=p->data;
	 return e;


}

void main()
{
	linklist la;
	int n;
	int i,j;
	Elemtype e;
	char cmd;
	printf("输入链表元素的个数:\n");
	scanf("%d",&n);
	la=creat(n);
	printf("输出链表:\n");
	output(la);

do
	{
		printf("g,G...查找\n");
		printf("i,I...插入\n");
		printf("d,D...删除\n");
		printf("q,Q...退出\n");
		do
		{
			getchar();
			scanf("%c",&cmd);
		}
		while((cmd!='g')&&(cmd!='G')&&(cmd!='d')&&(cmd!='D')&&(cmd!='q')&&(cmd!='Q')&&(cmd!='i')&&(cmd!='I'));
		switch(cmd)
		{
		case 'g':
		case'G':
			printf("请输入要查找元素的位置:\n");
			getchar();
			scanf("%d",&i);
			j=GetElem(la,i,e);
			printf("所要查找的元素是%d\n",j);
			break;
		case 'i':
		case'I':
			printf("请输入你要插入的数据：");
			getchar();
			scanf("%d",&e);
			printf("请输入你要插入的位置：");
			getchar();
			scanf("%d",&i);
			insert(la,i,e);
			printf("插入后的链表:\n");
			output(la);
			break;
		case'd':
		case'D':
			printf("请输入要删除的位置:\n");
			getchar();
			scanf("%d",&i);
			delect(la,i,e);
			printf("删除的那个元素是:%d\n",e);
			printf("输出删除后的顺序表:\n");
			output(la);
			break;
		}
	}
	while((cmd!='q')&&(cmd!='Q'));
printf("再见");
}

