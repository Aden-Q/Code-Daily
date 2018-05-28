#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 105
typedef struct AdjNode *PtrtoNode;
typedef struct AdjNode                      //节点
{
    int value;                              //被指向的节点
    int cost;                               //节点的cost
    PtrtoNode next;
}Node;
struct Node{
    PtrtoNode Firstedge;
    PtrtoNode Lastedge;
}AdjList[MAXSIZE];                          //M个表

int main() {
    int N,M,S[5000],E[5000],L[5000];
    int i;
    int indegree[MAXSIZE];                    //记录各个节点的入度
    int box[MAXSIZE];
    int topofstack;
    int cur;
    int num=0;
    int maxcost=-100;
    int weight[MAXSIZE][MAXSIZE];
    topofstack=-1;
    PtrtoNode temp;
    scanf("%d %d",&N,&M);                   //M:number of activities, N:number of check points
    PtrtoNode node[MAXSIZE];
    for(i=0;i<N;i++){                       //事先创建空节点 O(n)
        node[i]=malloc(sizeof(struct AdjNode));
        node[i]->next=NULL;
        node[i]->value=i;
        node[i]->cost=0;                    //初始花费为0
    }
    for(i=0;i<N;i++){
        AdjList[i].Firstedge=NULL;          //初始化 O(n)
        AdjList[i].Lastedge=NULL;
    }
    for(i=0;i<N;i++)                        // O(n)
        indegree[i]=0;                      //初始化入度
    for(i=0;i<M;i++){                       //读M行数据并创建完成邻接表
        scanf("%d %d %d", S+i,E+i,L+i);
        weight[S[i]][E[i]]=L[i];            //权值矩阵
        indegree[E[i]]++;                   //改入度 
        temp=malloc(sizeof(struct AdjNode));
        temp->next=NULL;
        temp->value=E[i];
        if(AdjList[S[i]].Firstedge==NULL){                     //建立邻接表
            AdjList[S[i]].Firstedge=temp;
            AdjList[S[i]].Lastedge=temp;
            continue;
        }
        else{
            AdjList[S[i]].Lastedge->next=temp;
            AdjList[S[i]].Lastedge=temp;
        }
    }
    for(i=0;i<N;i++){                   //N个节点
        if(indegree[i]==0)
            box[++topofstack]=i;        //先扫一遍，让度为0的节点入队
    }
    while(topofstack>=0){              //当栈为空时跳出循环即可
        cur=box[topofstack--];
        num++;                      //处理过的节点数
        temp=AdjList[cur].Firstedge;
        while(temp!=NULL){
            if(weight[cur][temp->value]+node[cur]->cost>node[temp->value]->cost)
                node[temp->value]->cost=weight[cur][temp->value]+node[cur]->cost;         //更新节点cost
            indegree[temp->value]--;      //处理度数，这边都需要处理
            if(indegree[temp->value]==0)
                box[++topofstack]=temp->value;
            temp=temp->next;
        }
    }
    if(num<N)               //没有处理完全部节点
        printf("Impossible\n");
    else{
        for(i=0;i<N;i++){
            if(node[i]->cost>maxcost)
                maxcost=node[i]->cost;
        }
        printf("%d\n",maxcost);
    }
    return 0;
}


