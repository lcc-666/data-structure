#include "stdio.h"
#include "malloc.h"
#define maxsize 1024
typedef char elemtype;//更换数据类型名称
typedef struct
{
	elemtype list[maxsize];
	int length;

}sequenlist;

void creatlist(sequenlist *L)
{
	int n,i;
	char tmp;
	printf("请输入数据个数：");
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		printf("list[%d]=",i);
		fflush(stdin);   //清空输入缓冲区，通常是为了确保不影响后面的数据的读入
		getchar();
		scanf("%c",&tmp);
		L->list[i]=tmp;
	}
	L->length=n-1;
	printf("\n");
}

int insert(sequenlist *L,elemtype x,int i){
	int j;
	if(L->length==maxsize-1){
		printf("表已满");
		return 0;
	}
	else if((i<0||(i>L->length))){
		printf('位置错误');
		return 0;
	}
	else{
		for(j=L->length;j>=i;j--)
			L->list[j+1]=L->list[j];L->list[i]=x;//后移
		L->length=L->length+1;
	}
	return(1);
}

int dellist(sequenlist *L,int i)
{
	if((i<0)||(i>L->length))
	{
		printf('位置错误');
		return 0;
	}
	else
	{
		for(;i<L->length;i++)
			L->list[i]=L->list[i+1];L->length=L->length-1;
		return 1;
	}
}

void printout(sequenlist *L)
{
	int i;
	for(i=0;i<=L->length;i++)
	{
		printf("list[%d]=",i);
		printf("%c\n",L->list[i]);
	}
}
main()
{
	sequenlist *L;
	char cmd,x;
	int i;
	L=(sequenlist *)malloc(sizeof(sequenlist));
	creatlist(L);
	printout(L);
	do
	{
		printf("i,I...插入\n");
		printf("d,D...删除\n");
		printf("q,Q...退出\n");
		do
		{
			fflush(stdin);
			scanf("%c",&cmd);
		}
		while((cmd!='d')&&(cmd!='D')&&(cmd!='q')&&(cmd!='Q')&&(cmd!='i')&&(cmd!='I'));
		switch(cmd)
		{
		case 'i':
		case'I':
			printf("请输入你要插入的数据：");
			getchar();
			fflush(stdin);
			scanf("%c",&x);
			printf("请输入你要插入的位置：");
			getchar();
			scanf("%d",&i);
			insert(L,x,i);
			printout(L);
			break;
		case'd':
		case'D':
			printf("请输入你要删除的数据的位置：");
			fflush(stdin);
			getchar();
			scanf("%d",&i);
			dellist(L,i);
			printout(L);
			break;
		}
	}
	while((cmd!='q')&&(cmd!='Q'));
	printf("再见");
}
