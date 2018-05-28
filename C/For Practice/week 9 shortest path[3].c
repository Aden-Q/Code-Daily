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

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );

int main()
{
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    MGraph G = ReadG();
    
    scanf("%d", &S);
    ShortestDist( G, dist, count, S );
    
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G->Nv; V++ )
        printf("%d ", count[V]);
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


void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S )
{
    int i,j;
    int rear,front;
    int Q[1000];
    int V;
    int stack[100];
    int topofstack;
    topofstack=-1;
    rear=0;
    front=0;
    Q[rear]=S;
    int indegree[100];
    for(i=0;i<Graph->Nv;i++){
        dist[i]=INFINITY;
        count[i]=0;
        indegree[i]=0;
    }
    dist[S]=0;
    count[S]=1;
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
    for(i=0;i<Graph->Nv;i++)
        for(j=0;j<Graph->Nv;j++)
            if(Graph->G[i][j]!=INFINITY&&dist[j]==dist[i]+Graph->G[i][j])
                indegree[j]++;          //统计入度,只计入起作用的边的入度
    for(i=0;i<Graph->Nv;i++)
        if(indegree[i]==0)
            stack[++topofstack]=i;
    while(topofstack>=0){
        V=stack[topofstack--];
        for(i=0;i<Graph->Nv;i++){
            if(Graph->G[V][i]!=INFINITY){
                if(dist[V]+Graph->G[V][i]==dist[i]){
                    count[i]+=count[V];
                    indegree[i]--;
                    if(indegree[i]==0)
                        stack[++topofstack]=i;
                }
            }
        }
    }
}
