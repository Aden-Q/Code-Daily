
#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph ReadG(void);

void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S );

int main()
{
    int dist[MaxVertexNum], path[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();
    
    scanf("%d", &S);
    ShortestDist( G, dist, path, S );
    
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", path[V]);
    printf("\n");
    
    return 0;
}

MGraph ReadG(void)
{
    MGraph G;
    G=malloc(sizeof(struct GNode));
    int a,b,c;
    int i,j;
    scanf("%d %d",&G->Nv,&G->Ne);
    for(i=0;i<G->Nv;i++)
        for(j=0;j<G->Nv;j++)
            G->G[i][j]=INFINITY;
    for(i=0;i<G->Ne;i++){
        scanf("%d %d %d",&a,&b,&c);
        G->G[a][b]=c;
    }
    return G;
}


void ShortestDist( MGraph Graph, int dist[], int path[], Vertex S )
{
    int i;
    int rear,front;
    int Q[1000];
    int V;
    int topofstack;
    int count[100];
    topofstack=-1;
    rear=0;
    front=0;
    Q[rear]=S;
    for(i=0;i<Graph->Nv;i++){
        dist[i]=INFINITY;
        path[i]=-1;
        count[i]=INFINITY;         //最短路径的最小长度
    }
    dist[S]=0;
    count[S]=0;
    while(rear>=front)
    {
        V=Q[front++];
        for(i=0;i<Graph->Nv;i++)
        {
            if(Graph->G[V][i]!=INFINITY)
            {
                if(dist[i]==INFINITY)
                    Q[++rear]=i;
                if(dist[i]>dist[V]+Graph->G[V][i]){
                    dist[i]=dist[V]+Graph->G[V][i];
                    if(Q[rear]!=i)
                        Q[++rear]=i;
                }
            }
        }
    }
    for(i=0;i<Graph->Nv;i++)
        if(dist[i]==INFINITY)
            dist[i]=-1;
    rear=0;
    front=0;
    Q[rear]=S;                  //初始化队列
    while(rear>=front){         //队列非空则做
        V=Q[front++];           //处理当前节点
        if(count[V]==INFINITY&&dist[V]!=-1){     //若当前节点是当前不可达到的而且是未来可以达到的，之后再处理
            Q[++rear]=V;                        //这段应该多余了
            continue;
        }
        for(i=0;i<Graph->Nv;i++){
            if(Graph->G[V][i]!=INFINITY&&dist[V]+Graph->G[V][i]==dist[i]&&count[V]+1<count[i]){
                count[i]=count[V]+1;            //更新count
                path[i]=V;
                Q[++rear]=i;
            }
        }
    }
}

