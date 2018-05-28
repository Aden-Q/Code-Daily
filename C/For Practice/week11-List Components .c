#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0
#define MAXSIZE 10

typedef int VERTICES;
typedef int EDGES;

void DFS(int Adj[][MAXSIZE],int Visited[],int N,int Cur);
void BFS(int Adj[][MAXSIZE],int Visited[],int N,int Cur);

int main(void)
{
	VERTICES N;				//N<=10
	EDGES E;
	int i,j;
	int Adj[MAXSIZE][MAXSIZE];
	VERTICES end1,end2;
	int Visited[MAXSIZE];
	for(i=0;i<MAXSIZE;i++)
		for(j=0;j<MAXSIZE;j++)
			Adj[i][j]=0;			//初始化邻接矩阵，0是断
	for(i=0;i<MAXSIZE;i++)
		Visited[i]=NO;				//初始化访问数组 
	scanf("%d %d",&N,&E);
	for(i=1;i<=E;i++){
		scanf("%d %d",&end1,&end2);
		Adj[end1][end2]=Adj[end2][end1]=1;		//存在边 
	}
	for(i=0;i<N;i++){						//深度优先 
		if(Visited[i]==NO){					//取集合起点 
			printf("{");					//为集合标识左界 
			DFS(Adj,Visited,N,i);			//没有访问过则以i为起点进行深度优先搜索 
			printf(" }\n");					//为集合标识右界 
		}
	}
	for(i=0;i<MAXSIZE;i++)
		Visited[i]=NO;						//初始化访问数组 
	for(i=0;i<N;i++){						//广度优先 
		if(Visited[i]==NO){					//取集合起点 
			printf("{ %d",i);				//为集合标识左界并将起点预输出
			Visited[i]=YES;					//预访问 
			BFS(Adj,Visited,N,i);			//没有访问过则以i为起点进行深度优先搜索 
			printf(" }\n");					//为集合标识右界 
		}
	}
	
	return 0;
 }
 
void DFS(int Adj[][MAXSIZE],int Visited[],int N,int Cur)
{
	int i; 
	Visited[Cur]=YES;			//预访问
	printf(" %d",Cur);			//输出该顶点 
	for(i=0;i<N;i++)
		if(Adj[Cur][i]!=0&&Visited[i]==NO)			//找到第一个可访问边后开始递归
			DFS(Adj,Visited,N,i);
}

void BFS(int Adj[][MAXSIZE],int Visited[],int N,int Cur)
{
	int i;
	int Q[MAXSIZE];				//递归参数队列 
	int front,rear;
	rear=-1;
	front=0;
	for(i=0;i<N;i++)			//寻找需要入队的参数 
		if(Adj[Cur][i]!=0&&Visited[i]==NO){
			Q[++rear]=i;
			Visited[i]=YES;
			printf(" %d",i);			//输出该顶点
		}
	while(rear>=front)			//递归 
		BFS(Adj,Visited,N,Q[front++]);
}

