/*
 ============================================================================
 Name        : sqstack.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#define STACK_INIT_SIZE 100


typedef int status;
typedef struct{
	int *base;
	int *top;
	int stacksize;
}sqstack;

int initstack(sqstack *s){
	s->base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!s->base)
		{printf('初始化失败');
		exit(-2);
		}
	s->top=s->base;
	s->stacksize=STACK_INIT_SIZE;

	return 1;
}

int push(sqstack *s,int e){
	if(s->top-s->base>=s->stacksize)
		{
		s->base=(int *)realloc(s,s->stacksize+STACK_INIT_SIZE*sizeof(int));//申请新空间
		if(!s->base)
			{printf('添加失败');
			exit(-2);}
		s->top=s->base+s->stacksize;
		s->stacksize=s->stacksize+STACK_INIT_SIZE;
		}
	*s->top=e;
	*s->top++;
	return 1;
}

int getpop(sqstack *s,int *e){
	if(s->base==s->top)
		return 0;
	e=*(s->top-1);
	printf("栈顶元素是 : %d\n",e);
	return 1;
}

int pop(sqstack *s,int *e){
	if(s->base==s->top)
			return 0;
		e=*(s->top-1);//未释放
		*s->top--;
		printf("元素 %d 出栈\n",e);
		return 1;
}

int printstack(sqstack s){
	if(s.base==s.top)
		{
			printf("空栈\n");
			return 1;
		}
	else
		printf("栈内容是:   ");
		for(;s.base!=s.top;s.base++)
			{
				printf("%d   ",*s.base);
			}
		return 1;
}


int main()
{
	sqstack s;
	if(initstack(&s))
		printf("初始化栈成功\n");
	for(;;)
	{
		printf("\n请选择要进行的操作:\n");
		printf("1  进栈   2   出栈   3   获得栈顶元素   \n4  打印   0   退出\n");
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
			printf("输入要进栈的元素:    ");
			scanf("%d",&pushelem);
			if(push(&s,pushelem))
				printf("进栈成功\n");
			else
				printf("进栈失败\n");
			break;}
		case 2:
			{int e;
			if(pop(&s,e))
				printf("出栈成功");
			else
				printf("出栈失败\n");
			break;}
		case 3:
			{int e;
			if(getpop(&s,e))
				printf("获取栈顶元素成功\n");
			else
				printf("获得栈顶元素失败\n");
			break;}
		case 4:
			if(printstack(s))
				printf("打印完毕\n");
			break;
		default:
			printf("你进行了误操作，请重新选择:\n");
			break;
		}
	}
	return 1;
}

