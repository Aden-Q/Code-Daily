#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode{
    int val;
    int height;
    Tree Left;
    Tree Right;
};


Tree insert(Tree T, int val);
Tree singleright(Tree T);
Tree LRrotation(Tree T);
Tree RLrotation(Tree T);
Tree RRrotation(Tree T);
int rmax(int a, int b);
int height(Tree T);


int main(void)
{
    Tree T=NULL;
    int i,n;
    int val;
    
    
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&val);
        T = insert(T,val);
    }
    if(T!=NULL)
        printf("%d\n",T->val);
    return 0;
}

Tree insert(Tree T,int val){
    if(T==NULL){
        T=(Tree)malloc(sizeof(struct TreeNode));
        T->val=val;
        T->Right=T->Left=NULL;
        T->height=0;
    }
    else if(T->val>val){
        T->Left=insert(T->Left,val);
        if(height(T->Left)-height(T->Right)>1){  //T is trouble maker
            if(val<T->Left->val)        //LL type
                T = singleright(T);
            else                      //LR type
                T = LRrotation(T);
        }
    }
    else if(T->val<val){
        T->Right=insert(T->Right,val);
        if(height(T->Left)-height(T->Right)<-1){
            if(val<T->Right->val)   //RL type
                T = RLrotation(T);
            else                      //RR type
                T = RRrotation(T);
        }
    }
    else
        ;
    T->height=rmax(height(T->Left),height(T->Right))+1;
    return T;
}

int height(Tree T)
{
    if(T==NULL)
        return -1;
    else
        return T->height;
}

Tree singleright(Tree T)
{
    Tree p;
    p=T->Left;
    T->Left=p->Right;
    p->Right=T;
    T->height=rmax(height(T->Left),height(T->Right))+1;
    p->height=rmax(height(p->Left),height(p->Right))+1;
    return p;
}

Tree LRrotation(Tree T)
{
    T->Left=RRrotation(T->Left);
    T=singleright(T);
    return T;
}

Tree RLrotation(Tree T)
{
    T->Right=singleright(T->Right);
    T=RRrotation(T);
    return T;
}

Tree RRrotation(Tree T)
{
    Tree p;
    p=T->Right;
    T->Right=p->Left;
    p->Left=T;
    T->height=rmax(height(T->Left),height(T->Right))+1;
    p->height=rmax(height(p->Left),height(p->Right))+1;
    return p;
}

int rmax(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}



