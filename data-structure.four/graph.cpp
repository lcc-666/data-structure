//============================================================================
// Name        : graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<stdio.h>
#define MAXVEXNUM 50  //最大顶点个数
#define INFINITY 65535    // INFINITY表示没有邻接的顶点间弧长
typedef char VertexType[3];
typedef struct vertex
{
	int adjvex;//顶点编号
	VertexType data;//顶点信息
}Vertex_Type;//顶点类型
typedef struct graph
{
	int Vertex_Num;//顶点数
	int Edge_Num;//边数
	Vertex_Type vexs[MAXVEXNUM];//顶点数组
	int edges[MAXVEXNUM][MAXVEXNUM];// 边的二维数组
}AdjMatix;//图的邻接矩阵类型

/*--------生成邻接矩阵--------*/
int Create_Adjmatix(AdjMatix &g)
{
	int i,j,k,b,t,w;
	printf("请输入图的顶点数和边数：\n");
	scanf("%d%d",&g.Vertex_Num,&g.Edge_Num);
	for (i=0;i<g.Vertex_Num;i++)
	{
		printf("顶点vexs[%d]的名称：",i);
		scanf("%s",g.vexs[i].data);
		g.vexs[i].adjvex=i;
	}
	for (i=0;i<g.Vertex_Num;i++)//初始化邻接矩阵
			{
				for(j=0;j<g.Vertex_Num;j++)
			    g.edges[i][j]=INFINITY;
	        }

	for(k=0;k<g.Edge_Num;k++)
	{
			printf("请输入Edge[%d]的边的信息：\n",k);
	        printf("起点下标 终点下标  权值\n");
		    scanf("%d%d%d",&b,&t,&w);
		    if(b<g.Vertex_Num&&t<g.Vertex_Num&&w>0)
			   g.edges[b][t]=w;
			else
			{printf("输入错误！");
			return 0;}
	}



	for (i=0;i<g.Vertex_Num;i++)//输出矩阵
	{
		for(j=0;j<g.Vertex_Num;++j)
		printf("%10d",g.edges[i][j]);
		printf("\n");
	}
		return 1;

}
/*--------迪杰斯特拉算法求最短路径--------*/
void shortesPath_DIJ(AdjMatix g,int v0)
{
	int dist[MAXVEXNUM];//辅助数组，存放起点v0(编号为0)到其他顶点的路径长度
	int path[MAXVEXNUM][MAXVEXNUM];//存放起点v0(编号为0)到其他顶点的最短路径
	//path[v][w]=1,则w是从起点v0到v当前求得最短路径上的顶点
	int s[MAXVEXNUM];//存放源点集
	int mindis,i,j,k,m,u,v,w;
	/*---------初始化数据--------*/
	for(i=0;i<g.Vertex_Num;i++)
	{
		dist[i]=g.edges[v0][i];//将与起点有连线的顶点加上权值
		s[i]=v0; //s集合最初只有起点v0
		for(j=0;j<g.Vertex_Num;j++)
			path[i][j]=0;//初始化路径数组path[][]为0
		if(dist[i]<INFINITY)
		{
			path[i][v0]=1;
		    path[i][i]=1;
		}
	}
	dist[v0]=0;//v0到自己的距离设定为零
	s[v0]=1;//V0放入源点集合
	printf("------------------------------------\n");
	printf("迪杰斯特拉最短路径求解如下：\n");
	//开始主循环
	for(i=1;i<g.Vertex_Num;i++)
	{	u=-1;
	    mindis=INFINITY;//mindis为当前所知离v0的最短距离，先令mindis为极大值
	    for(w=0;w<g.Vertex_Num;w++)
		{  if(s[w]==0&&dist[w]<mindis)//w不在s中且w离v0更近
			{
				u=w;
			    mindis=dist[w];
			}
		}
	    if(u!=-1)
		{
		    s[u]=1;//并入顶点集合
		    for(j=0;j<g.Vertex_Num;j++)
//修正v0到其他顶点的当前最短路径p及距离dist[j]
			{
			    if(s[j]==0&&mindis+g.edges[u][j]<dist[j])//找到v0到其他顶点的更短路径
				{
						dist[j]=g.edges[u][j]+dist[u];//修改当前路径长度
						for(k=0;k<g.Vertex_Num;k++)
							path[j][k]=path[u][k];
				        path[j][j]=1;//表示路径上有此顶点
				}
			}
			printf("\n第%d次：",i);
			printf("\n s[]: "); //打印中间结果，跟踪数据变化
			for(v=0; v<g.Vertex_Num; ++v)
				printf("%6d",s[v]);
			printf("\n\n dist[]: ");
			for(v=0; v<g.Vertex_Num; ++v)
				printf("%6d",dist[v]);
			printf("\n\n path[][]:\n");
			for(v=0; v<g.Vertex_Num; ++v)
			{
				for(m=0; m<g.Vertex_Num; ++m)
					printf("%6d",path[v][m]);
				printf("\n");
			}

			printf("\n起点%s到终点%s的最短路径为：",g.vexs[0].data,g.vexs[u].data);
		    for(m=1;m<g.Vertex_Num;m++)
		    {
			     for(k=0;k<g.Vertex_Num;k++)
		         {
			          if(path[u][k]==m)
			          printf("->%s",g.vexs[k].data);
				 }
			}
		    printf("\n");
		    printf("最短路径长度为：%d",dist[u]);
		    printf("\n");
		}
		else
		{
			printf("\n第%d次：",i);
			for(m=0;m<g.Vertex_Num;m++)
				if(s[m]==0)
					printf("顶点%s到顶点%s没有路径\n",g.vexs[0].data,g.vexs[m].data);
		}
	}
}

int main()
{
	AdjMatix g;
    Create_Adjmatix(g);
    shortesPath_DIJ(g,0);
    return 0;
}
