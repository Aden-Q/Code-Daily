#include <stdio.h>

#define MAXSIZE 501
#define NOTEXIST -1
#define DESTROYED 0
#define INUSE 1
#define YES 1
#define NO 0
#define INFINITY 10000

void DFS(int Highway[][MAXSIZE],int Visited[],int Inherit[],int N,int Cur,int Conquer);
void AllNotVisited(int Visited[]);
int CalMinCost(int Highway[][MAXSIZE],int BuildCost[][MAXSIZE],int Inherit[],int N,int Conquer);

int main(void)
{
	int MaxCost=0;
	int CurCost;
	int N,M;			//N:cities; M:highways
	int i,j;
	int count=0;
	int Inherit[MAXSIZE];						//继承数组 
	int City1,City2,Cost,Status,Conquer;		//Conquer是当前被占领的城市 
	int Highway[MAXSIZE][MAXSIZE];
	int BuildCost[MAXSIZE][MAXSIZE];
	int Visited[MAXSIZE];
	scanf("%d %d",&N,&M);		//读取顶点数N和边数M
	AllNotVisited(Visited);			//初始化Visited数组
	for(i=1;i<MAXSIZE;i++){
		for(j=1;j<MAXSIZE;j++){
			Highway[i][j]=NOTEXIST;	//初始化为任何高速通道都不存在 
			BuildCost[i][j]=0;			//初始化为0表示无任何花费 
		}
	}
	for(i=1;i<=M;i++){
		scanf("%d %d %d %d",&City1,&City2,&Cost,&Status);
		Highway[City1][City2]=Highway[City2][City1]=Status;		//destroy或者in use都被记录，其他未记录的都是NOTEXIST
		BuildCost[City1][City2]=BuildCost[City2][City1]=Cost; 	//记录rebuild的花费 
	}
	
	for(Conquer=1;Conquer<=N;Conquer++){				//每次被Conquer都不同，依次考虑
		AllNotVisited(Visited);					//初始化Visited数组为未Visited
		for(i=1;i<=N;i++)
			Inherit[i]=-1;						//初始化继承数组为每个都是root(用-1表示) 
		for(i=1;i<=N;i++)						//以i为起点做DFS，i是这个类的root 
			if(i!=Conquer&&Visited[i]==NO)
				DFS(Highway,Visited,Inherit,N,i,Conquer);		//对于一个Conquer完成了继承类的修改
		CurCost=CalMinCost(Highway,BuildCost,Inherit,N,Conquer);		//计算当前Conquer情况下的最小重建花费
		if(MaxCost<CurCost)
			MaxCost=CurCost;
	}
	if(MaxCost==0)
		printf("0\n");
	else{
		for(Conquer=1;Conquer<=N;Conquer++){		//每次被Conquer都不同，依次考虑
			AllNotVisited(Visited);					//初始化Visited数组为未Visited
			for(i=1;i<=N;i++)
				Inherit[i]=-1;						//初始化继承数组为每个都是root(用-1表示) 
			for(i=1;i<=N;i++)						//以i为起点做DFS，i是这个类的root 
				if(i!=Conquer&&Visited[i]==NO)
					DFS(Highway,Visited,Inherit,N,i,Conquer);		//对于一个Conquer完成了继承类的修改
			CurCost=CalMinCost(Highway,BuildCost,Inherit,N,Conquer);		//计算当前Conquer情况下的最小重建花费
			if(MaxCost==CurCost){
				count++;
				if(count==1)
					printf("%d",Conquer);
				else
					printf(" %d",Conquer);
			}
		}
	}
	return 0;
}

void AllNotVisited(int Visited[])
{
	int i;
	for(i=0;i<MAXSIZE;i++)
		Visited[i]=NO;				//初始化为全部未访问
}


void DFS(int Highway[][MAXSIZE],int Visited[],int Inherit[],int N,int Cur,int Conquer)
{
	int i;
	Visited[Cur]=YES;			//预访问
	for(i=1;i<=N;i++)
		if(Highway[Cur][i]==INUSE&&Visited[i]==NO&&i!=Conquer){		//找到第一个可访问边后开始递归
			Inherit[i]=Cur;				//修改继承关系 
			DFS(Highway,Visited,Inherit,N,i,Conquer);
		}
}

int FindRoot(int City,int Inherit[]){
	if(Inherit[City]==-1)
		return City;
	else
		FindRoot(Inherit[City],Inherit);		//利用继承关系数组进行递归 
}

int CalMinCost(int Highway[][MAXSIZE],int BuildCost[][MAXSIZE],int Inherit[],int N,int Conquer)
{
	int TotalCost=0;
	int cost=INFINITY;				//重建额最小花费
	int i,j,k;
	int root1,root2;
	int Curroot2;
	int CurRoot; 
	for(i=1;i<=N;i++){
		if(i==Conquer)
			continue;
		root1=FindRoot(i,Inherit);
		cost=INFINITY;
		for(j=1;j<=N;j++){
			root2=FindRoot(j,Inherit);
			if(j==Conquer||root2==root1)		//如果是同根或者是Conquer城市 
				continue;
			for(k=1;k<=N;k++){
				if(k==Conquer||FindRoot(k,Inherit)!=root1||Highway[j][k]!=DESTROYED)
					continue;
				if(cost>BuildCost[j][k]){
					cost=BuildCost[j][k];
					Curroot2=root2;
				}
			}
		}
		if(cost!=INFINITY){
			Inherit[Curroot2]=root1;
			TotalCost+=cost;
		}	
	}
	return TotalCost;
}

