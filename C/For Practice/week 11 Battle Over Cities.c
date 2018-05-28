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
	int Inherit[MAXSIZE];						//�̳����� 
	int City1,City2,Cost,Status,Conquer;		//Conquer�ǵ�ǰ��ռ��ĳ��� 
	int Highway[MAXSIZE][MAXSIZE];
	int BuildCost[MAXSIZE][MAXSIZE];
	int Visited[MAXSIZE];
	scanf("%d %d",&N,&M);		//��ȡ������N�ͱ���M
	AllNotVisited(Visited);			//��ʼ��Visited����
	for(i=1;i<MAXSIZE;i++){
		for(j=1;j<MAXSIZE;j++){
			Highway[i][j]=NOTEXIST;	//��ʼ��Ϊ�κθ���ͨ���������� 
			BuildCost[i][j]=0;			//��ʼ��Ϊ0��ʾ���κλ��� 
		}
	}
	for(i=1;i<=M;i++){
		scanf("%d %d %d %d",&City1,&City2,&Cost,&Status);
		Highway[City1][City2]=Highway[City2][City1]=Status;		//destroy����in use������¼������δ��¼�Ķ���NOTEXIST
		BuildCost[City1][City2]=BuildCost[City2][City1]=Cost; 	//��¼rebuild�Ļ��� 
	}
	
	for(Conquer=1;Conquer<=N;Conquer++){				//ÿ�α�Conquer����ͬ�����ο���
		AllNotVisited(Visited);					//��ʼ��Visited����ΪδVisited
		for(i=1;i<=N;i++)
			Inherit[i]=-1;						//��ʼ���̳�����Ϊÿ������root(��-1��ʾ) 
		for(i=1;i<=N;i++)						//��iΪ�����DFS��i��������root 
			if(i!=Conquer&&Visited[i]==NO)
				DFS(Highway,Visited,Inherit,N,i,Conquer);		//����һ��Conquer����˼̳�����޸�
		CurCost=CalMinCost(Highway,BuildCost,Inherit,N,Conquer);		//���㵱ǰConquer����µ���С�ؽ�����
		if(MaxCost<CurCost)
			MaxCost=CurCost;
	}
	if(MaxCost==0)
		printf("0\n");
	else{
		for(Conquer=1;Conquer<=N;Conquer++){		//ÿ�α�Conquer����ͬ�����ο���
			AllNotVisited(Visited);					//��ʼ��Visited����ΪδVisited
			for(i=1;i<=N;i++)
				Inherit[i]=-1;						//��ʼ���̳�����Ϊÿ������root(��-1��ʾ) 
			for(i=1;i<=N;i++)						//��iΪ�����DFS��i��������root 
				if(i!=Conquer&&Visited[i]==NO)
					DFS(Highway,Visited,Inherit,N,i,Conquer);		//����һ��Conquer����˼̳�����޸�
			CurCost=CalMinCost(Highway,BuildCost,Inherit,N,Conquer);		//���㵱ǰConquer����µ���С�ؽ�����
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
		Visited[i]=NO;				//��ʼ��Ϊȫ��δ����
}


void DFS(int Highway[][MAXSIZE],int Visited[],int Inherit[],int N,int Cur,int Conquer)
{
	int i;
	Visited[Cur]=YES;			//Ԥ����
	for(i=1;i<=N;i++)
		if(Highway[Cur][i]==INUSE&&Visited[i]==NO&&i!=Conquer){		//�ҵ���һ���ɷ��ʱߺ�ʼ�ݹ�
			Inherit[i]=Cur;				//�޸ļ̳й�ϵ 
			DFS(Highway,Visited,Inherit,N,i,Conquer);
		}
}

int FindRoot(int City,int Inherit[]){
	if(Inherit[City]==-1)
		return City;
	else
		FindRoot(Inherit[City],Inherit);		//���ü̳й�ϵ������еݹ� 
}

int CalMinCost(int Highway[][MAXSIZE],int BuildCost[][MAXSIZE],int Inherit[],int N,int Conquer)
{
	int TotalCost=0;
	int cost=INFINITY;				//�ؽ�����С����
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
			if(j==Conquer||root2==root1)		//�����ͬ��������Conquer���� 
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

