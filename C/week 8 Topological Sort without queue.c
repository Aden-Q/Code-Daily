#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool TopSort( LGraph Graph, Vertex TopOrder[] );

int main()
{
    int i;
    Vertex TopOrder[MaxVertexNum];
    LGraph G = ReadG();
    
    if ( TopSort(G, TopOrder)==true )
        for ( i=0; i<G->Nv; i++ )
            printf("%d ", TopOrder[i]);
    else
        printf("ERROR");
    printf("\n");
    
    return 0;
}

bool TopSort( LGraph Graph, Vertex TopOrder[] )
{
    PtrToAdjVNode temp;
    int i,j;
    int indegree[Graph->Nv];
//  int box[Graph->Nv];             //存入度为0的
    int topofstack;
    topofstack=-1;
    for(i=0;i<Graph->Nv;i++)
        indegree[i]=0;
    for(i=0;i<Graph->Nv;i++) {           //计算所有入度
        temp = Graph->G[i].FirstEdge;
        while(temp!=NULL){
            indegree[temp->AdjV]++;     //当前节点入度加1
            temp=temp->Next;            //询问下一个节点
        }
    }
//    for(i=0;i<Graph->Nv;i++){
//      if(indegree[i]==0)              //节点i的入度为0
//            box[++topofstack]=i;
//    }
//    while(topofstack>=0){
//        TopOrder[j]=box[topofstack];
//        temp=Graph->G[box[topofstack]].FirstEdge;
//        while(temp!=NULL){
//            indegree[temp->AdjV]--;
//            temp=temp->Next;
//        }
//    }
    for(j=0;j<Graph->Nv;j++){           //往toporder写这么多次
        for(i=0;i<Graph->Nv;i++){
            if(indegree[i]==0)
                break;
        }
        if(i>=Graph->Nv)
            return false;
        indegree[i]=-1;
        TopOrder[j]=i;                  //写
        temp=Graph->G[i].FirstEdge;
        while(temp!=NULL){              //更新出度
            indegree[temp->AdjV]--;
            temp=temp->Next;
        }
    }
    return true;
}
