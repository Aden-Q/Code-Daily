#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode *Tree;
struct TreeNode {
    ElementType Element;
    Tree  Left;
    Tree  Right;
};

Tree BuildTree(); /* details omitted */

int Isomorphic( Tree T1, Tree T2 );

int main()
{
    Tree T1, T2;
    T1 = BuildTree();
    T2 = BuildTree();
    printf("%d\n", Isomorphic(T1, T2));
    return 0;
}

int Isomorphic( Tree T1, Tree T2 )
{
    static int degree=0;
    static int flag=1;
//    判断当前节点
    if(T1==NULL&&T2==NULL){
        if (degree==0)
            return 1;
        else;
    }
    else if(T1==NULL||T2==NULL)
        flag=0;
    else if(T1->Element!=T2->Element)
        flag=0;
    else;
//    判断下一层次的节点
    if(T1->Left!=NULL&&T1->Right!=NULL){
        if(T2->Left==NULL||T2->Right==NULL){
            flag=0;
            degree++;
            return 0;
        }
        else if(T1->Left->Element==T2->Left->Element){
            Isomorphic(T1->Left, T2->Left);
            Isomorphic(T1->Right, T2->Right);
        }
        else if(T1->Left->Element==T2->Right->Element){
            Isomorphic(T1->Left, T2->Right);
            Isomorphic(T1->Right, T2->Left);
        }
        else{
            flag=0;
            degree++;
            return 0;
        }
    }
    
    if(T1->Left==NULL&&T1->Right!=NULL){
        if((T2->Left==NULL&&T2->Right==NULL)||(T2->Left!=NULL&&T2->Right!=NULL)){
            flag=0;
            degree++;
            return 0;
        }
        else if(T2->Left==NULL){
            Isomorphic(T1->Right, T2->Right);
        }
        else if(T2->Right==NULL){
            Isomorphic(T1->Right, T2->Left);
        }
        else{
            flag=0;
            degree++;
            return 0;
        }
    }
    
    if(T1->Left!=NULL&&T1->Right==NULL){
        if((T2->Left==NULL&&T2->Right==NULL)||(T2->Left!=NULL&&T2->Right!=NULL)){
            flag=0;
            degree++;
            return 0;
        }
        else if(T2->Left==NULL){
            Isomorphic(T1->Left, T2->Right);
        }
        else if(T2->Right==NULL){
            Isomorphic(T1->Left, T2->Left);
        }
        else{
            flag=0;
            degree++;
            return 0;
        }
    }
    
    if(T1->Left==NULL&&T1->Right==NULL){
        if(T2->Left!=NULL||T2->Right!=NULL){
            flag=0;
            degree++;
            return 0;
        }
        else;
    }
    degree++;
    return flag;
}


