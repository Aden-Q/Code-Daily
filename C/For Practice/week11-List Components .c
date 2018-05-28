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
			Adj[i][j]=0;			//��ʼ���ڽӾ���0�Ƕ�
	for(i=0;i<MAXSIZE;i++)
		Visited[i]=NO;				//��ʼ���������� 
	scanf("%d %d",&N,&E);
	for(i=1;i<=E;i++){
		scanf("%d %d",&end1,&end2);
		Adj[end1][end2]=Adj[end2][end1]=1;		//���ڱ� 
	}
	for(i=0;i<N;i++){						//������� 
		if(Visited[i]==NO){					//ȡ������� 
			printf("{");					//Ϊ���ϱ�ʶ��� 
			DFS(Adj,Visited,N,i);			//û�з��ʹ�����iΪ����������������� 
			printf(" }\n");					//Ϊ���ϱ�ʶ�ҽ� 
		}
	}
	for(i=0;i<MAXSIZE;i++)
		Visited[i]=NO;						//��ʼ���������� 
	for(i=0;i<N;i++){						//������� 
		if(Visited[i]==NO){					//ȡ������� 
			printf("{ %d",i);				//Ϊ���ϱ�ʶ��粢�����Ԥ���
			Visited[i]=YES;					//Ԥ���� 
			BFS(Adj,Visited,N,i);			//û�з��ʹ�����iΪ����������������� 
			printf(" }\n");					//Ϊ���ϱ�ʶ�ҽ� 
		}
	}
	
	return 0;
 }
 
void DFS(int Adj[][MAXSIZE],int Visited[],int N,int Cur)
{
	int i; 
	Visited[Cur]=YES;			//Ԥ����
	printf(" %d",Cur);			//����ö��� 
	for(i=0;i<N;i++)
		if(Adj[Cur][i]!=0&&Visited[i]==NO)			//�ҵ���һ���ɷ��ʱߺ�ʼ�ݹ�
			DFS(Adj,Visited,N,i);
}

void BFS(int Adj[][MAXSIZE],int Visited[],int N,int Cur)
{
	int i;
	int Q[MAXSIZE];				//�ݹ�������� 
	int front,rear;
	rear=-1;
	front=0;
	for(i=0;i<N;i++)			//Ѱ����Ҫ��ӵĲ��� 
		if(Adj[Cur][i]!=0&&Visited[i]==NO){
			Q[++rear]=i;
			Visited[i]=YES;
			printf(" %d",i);			//����ö���
		}
	while(rear>=front)			//�ݹ� 
		BFS(Adj,Visited,N,Q[front++]);
}

