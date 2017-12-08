#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFTY 10000
#define MaxVertexNum 110
#define EPS 1e-4                                    //为double型邻接矩阵大小准备判断精度

typedef int Vertex;
typedef double Weight;
typedef int StepLength;

typedef struct location *PtrTolocation;
struct location{                                    //鳄鱼的坐标结构
    int x;
    int y;
    int known;
    int count;                                      //记录跳跃次数
    int path;                                       //跳跃的来源
};

typedef struct GNode *PtrToGNode;
struct GNode{
    Vertex N;                                       //鳄鱼数
    StepLength D;
    PtrTolocation Cor[MaxVertexNum];                //坐标结构数组
    Weight G[MaxVertexNum][MaxVertexNum];           //临接矩阵
};

void GerCrocodiles(PtrToGNode GNode,Vertex N,StepLength D);         //初始化GNode结构
int ExitPoint(Vertex exitstack[],int exittopofstack,PtrToGNode GNode);
int EnterPoint(Vertex enterstack[],int entertopofstack,PtrToGNode GNode);
void SearchPath(Vertex exitstack[],int exittopofstack,Vertex enterstack[],int entry,PtrToGNode GNode);      //entry为主栈入口，多次改变entry并调用以防止函数内部变复杂
void TailRecursion(PtrToGNode GNode,int index);
void ReInitialize(PtrToGNode GNode);

int main(int argc, const char * argv[]) {
    int i;
    Vertex exitstack[MaxVertexNum];                     //出口栈
    Vertex enterstack[MaxVertexNum];                    //入口栈
    int exittopofstack=-1;                              //初始两个栈空
    int entertopofstack=-1;
    int entry,mincount,newmincount,index,initialdist,endpoint,newendpoint;  //调用入口，到达终点栈中点的最小花费，最优索引，最优初始距离
    PtrToGNode GNode;
    Vertex N;
    StepLength D;
    GNode=malloc(sizeof(struct GNode));
    if(GNode==NULL){
        printf("Malloc Error!\n");
        exit(0);
    }
    scanf("%d %d",&N,&D);                           //N为鳄鱼数，D为每次跳跃的长度上限值
    GerCrocodiles(GNode,N,D);
    exittopofstack=ExitPoint(exitstack,exittopofstack,GNode);
    entertopofstack=EnterPoint(enterstack,entertopofstack,GNode);
    //接下来只要寻找起点到终点的通路即可，试图反向寻路到,把栈中的点作为起点，回探到(0,0)的通路
    if(exittopofstack==-1||entertopofstack==-1)       //若起点栈为空或者终点栈为空，则不可能有路径出去
        printf("0\n");
    else{                                                //可能存在路径则搜索之
        if(GNode->D>42){                //一步跳出
            printf("1\n");
            return 0;
        }
        entry=entertopofstack;
        index=entry;                                    //entry的索引
        initialdist=pow(GNode->Cor[enterstack[entry]]->x,2)+pow(GNode->Cor[enterstack[entry]]->y,2);      //初始距离
        SearchPath(exitstack,exittopofstack,enterstack,entry,GNode);          //第一次调用
        i=exitstack[exittopofstack];                    //临时索引
        mincount=GNode->Cor[i]->count;
        endpoint=i;
        for(i=0;i<=exittopofstack;i++)                   //搜索终点栈的最小count
            if(GNode->Cor[exitstack[i]]->count<mincount){
                mincount=GNode->Cor[exitstack[i]]->count;
                endpoint=exitstack[i];
            }
        while(1){                           //开始多重调用，需要初始化所有count为INFITY和path为-1
            entry--;
            if(entry<0)
                break;
            ReInitialize(GNode);
            SearchPath(exitstack,exittopofstack,enterstack,entry,GNode);
            i=exitstack[exittopofstack];                    //临时索引
            newmincount=GNode->Cor[i]->count;
            newendpoint=i;
            for(i=0;i<=exittopofstack;i++)                   //搜索终点栈的最小count
                if(GNode->Cor[exitstack[i]]->count<newmincount){
                    newmincount=GNode->Cor[exitstack[i]]->count;
                    newendpoint=exitstack[i];
                }
            if(newmincount<mincount){                   //如果新的到终点栈的花费更少，则更新(记录)这次的索引，初始距离以及花费,以及终点
                index=entry;
                initialdist=pow(GNode->Cor[enterstack[entry]]->x,2)+pow(GNode->Cor[enterstack[entry]]->y,2);
                mincount=newmincount;
                endpoint=newendpoint;
            }
            else if(newmincount==mincount)      //如果两次花费相同，但是后面一次的初始距离更少，则只需更新索引、初始距离以及终点(花费不变)
                if(pow(GNode->Cor[enterstack[entry]]->x,2)+pow(GNode->Cor[enterstack[entry]]->y,2)<initialdist){
                    index=entry;
                    initialdist=pow(GNode->Cor[enterstack[entry]]->x,2)+pow(GNode->Cor[enterstack[entry]]->y,2);
                    endpoint=newendpoint;
                }
        }
        ReInitialize(GNode);
        SearchPath(exitstack,exittopofstack,enterstack,index,GNode);  //离开循环代表已经找到了最好的索引位置，初始距离，花费
        if(mincount==INFTY)             //不存在可能的通路
            printf("0\n");
        else{
            printf("%d\n",mincount+1);        //+1是因为从终点到岸上还要跳一次，打印第一行
            TailRecursion(GNode,endpoint);       //尾递归输出
        }
    }
    return 0;
}

void GerCrocodiles(PtrToGNode GNode,Vertex N,StepLength D){
    GNode->N=N;                                //记录鳄鱼数
    GNode->D=D;
    int i,j;
    int x,y;
    j=0;
    for(i=0;i<N;i++){                           //读入每只鳄鱼的坐标
        GNode->Cor[i]=malloc(sizeof(struct location));
        if(GNode->Cor[i]==NULL){                //错误处理
            printf("Malloc Error!\n");
            exit(0);
        }
        scanf("%d %d",&x,&y);
        if((pow(x,2)+pow(y,2))<pow(7.5,2)||x>50-EPS||x<-50+EPS||y>50-EPS||y<-50+EPS)         //鳄鱼在岛内或者岸上
            continue;
        GNode->Cor[j]->x=x;
        GNode->Cor[j]->y=y;
        GNode->Cor[j]->count=INFTY;          //初始时均为不可达到(要跳跃无数次)
        GNode->Cor[j]->path=-1;              //开始时都没有路径能到达
        j++;
    }
    GNode->N=j;
    for(i=0;i<GNode->N;i++)                     //初始化邻接矩阵,对角线上为double型的0，当(距离-D)小于EPS时，可以跳
        for(j=0;j<GNode->N;j++)
            GNode->G[i][j]=sqrt(pow(GNode->Cor[i]->x-GNode->Cor[j]->x,2)+pow(GNode->Cor[i]->y-GNode->Cor[j]->y,2));
}

int ExitPoint(Vertex exitstack[],int exittopofstack,PtrToGNode GNode){
    int i;
    double dist[4];
    double mindist;
    for(i=0;i<GNode->N;i++){                     //遍历每条鳄鱼，看是否可以从作为出口
        dist[0] =abs(GNode->Cor[i]->x+50);        //计算左右上下的距离
        dist[1] =abs(GNode->Cor[i]->x-50);
        dist[2] =abs(GNode->Cor[i]->y-50);
        dist[3] =abs(GNode->Cor[i]->y+50);
        mindist=dist[0];
        if(dist[1]<mindist)
            mindist=dist[1];
        if(dist[2]<mindist)
            mindist=dist[2];
        if(dist[3]<mindist)
            mindist=dist[3];
        if(mindist-GNode->D<EPS)
            exitstack[++exittopofstack]=i;                 //可以作为出口则入栈
    }
    return exittopofstack;                              //返回栈顶
}

int EnterPoint(Vertex enterstack[],int entertopofstack,PtrToGNode GNode){
    int i;
    double dist;
    for(i=0;i<GNode->N;i++){                            //遍历每条鳄鱼，看是否可以从作为入口
        dist=sqrt(pow(GNode->Cor[i]->x,2)+pow(GNode->Cor[i]->y,2))-7.5;              //边缘最小距离
        if(dist-GNode->D<EPS)
            enterstack[++entertopofstack]=i;            //可以作为入口则入栈
    }
    return entertopofstack;                             //返回栈顶
}

void SearchPath(Vertex exitstack[],int exittopofstack,Vertex enterstack[],int entry,PtrToGNode GNode){
    int Q[5000];
    int i;
    int rear,front;
    Vertex V;
    V=enterstack[entry];
    GNode->Cor[V]->count=1;                     //开始的时候从岛上跳到这只鳄鱼身上
    rear=front=0;
    Q[rear]=V;
    while(rear>=front){                         //队列非空则进行
        V=Q[front++];
        for(i=0;i<=exittopofstack;i++)
            if(V==exitstack[i])
                break;
        if(i<=exittopofstack)                   //如果当前处理的节点在终点栈中，则不需要再处理
            continue;
        for(i=0;i<GNode->N;i++){
            if(i==V)                            //i=V时，距离看为0,需避免
                continue;
            if(GNode->G[V][i]-GNode->D<EPS&&GNode->Cor[i]->count>GNode->Cor[V]->count+1){  //把当前可更新count的节点全部入队
                GNode->Cor[i]->count=GNode->Cor[V]->count+1;
                GNode->Cor[i]->path=V;                              //从V跳到i
                Q[++rear]=i;
            }
        }
    }
}

void TailRecursion(PtrToGNode GNode,int index){
    if(GNode->Cor[index]->path!=-1)
        TailRecursion(GNode,GNode->Cor[index]->path);
    printf("%d %d\n",GNode->Cor[index]->x,GNode->Cor[index]->y);
    return;
}

void ReInitialize(PtrToGNode GNode){
    int i;
    for(i=0;i<GNode->N;i++){
        GNode->Cor[i]->count=INFTY;          //初始时均为不可达到(要跳跃无数次)
        GNode->Cor[i]->path=-1;              //开始时都没有路径能到达
    }
}
