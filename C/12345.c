#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treenode *Tree;
struct treenode{
    int Element;
    Tree left;
    Tree right;
    Tree father;
};

Tree BuildTree(int N);
void Postorder(Tree T,int N);

int main(void)
{
    int N;
    scanf("%d",&N);
    Tree T;
    T=BuildTree(N);
    Postorder(T,N);
    return 0;
}

Tree BuildTree(int N)
{
    int g=1;   //回溯标志
    int i;
    int r;
    int j=0;
    int value;
    static char s[80][10];
    int a[40];
    int topofstack=0;
    Tree tree[40];
    Tree cur;           //current tree
    cur=NULL;
    //getchar();
    for(i=0;i<2*N;i++){
        //gets(s[i]);
        scanf("%s",s[i]);
        //if(s[i][3]>='a'&&s[i][3]<='z')
        //    s[i][4]='\0';
        // else
        //   s[i][3]='\0';
        if(strcmp(s[i],"Push")==0){
            scanf("%d",&value);
            g=1;
            //if(s[i][6]>='0'&&s[i][6]<='9')
            //  a[++topofstack]=(s[i][5]-'0')*10+s[i][6]-'0';
            //else
            //  a[++topofstack]=s[i][5]-'0';
            a[++topofstack]=value;
            
            tree[j]=(Tree)malloc(sizeof(struct treenode));
            tree[j]->Element=0;
            tree[j]->left=NULL;
            tree[j]->right=NULL;
            if(j==0){
                tree[j]->father=NULL;
                cur=tree[j];
            }
            else{
                tree[j]->father=cur;
                if (cur!= NULL&&cur->left==NULL)
                    cur->left=tree[j];
                else if(cur!=NULL&&cur->right==NULL)
                    cur->right=tree[j];
                else
                    ;
                cur=tree[j];
            }
            j++;
        }
        else if(strcmp(s[i],"Pop")==0){
            int flag=0;        //检测是否赋值的符号
            r=a[topofstack--];
            if(g==1&&cur->Element==0){     //进行过回溯且此处无值
                cur->Element=r;
                g=0;
                flag=1;
            }
            //开始回溯,若没有赋值则不回溯
            if(flag==0&&g==0){
                cur=cur->father;
                g=1;
            }
            
            else if(cur!=NULL&&cur->left==NULL&&cur->right==NULL){   //只有叶节点被赋值需要一层回溯
                cur=cur->father;
                g=1;
            }
            else
                ;
            
            while(cur!=NULL&&(cur->left!=NULL&&cur->right!=NULL)){
                if(cur->Element==0)
                    break;            //向上回溯到一个空的树节点或根或NULL
                cur=cur->father;
                g=1;
            }
            if(flag==0){
                if(cur!=NULL&&cur->Element==0)
                    cur->Element=r;
                g=0;
                while(cur!=NULL&&(cur->left!=NULL&&cur->right!=NULL)){
                    if(cur->Element==0)
                        break;            //向上回溯到一个空的树节点或根或NULL
                    cur=cur->father;
                    g=1;
                }
            }
        }
        else;
        
    }
    return tree[0];
}

void Postorder(Tree T,int N)
{
    static int count=1;
    if(T==NULL)
        return;
    Postorder(T->left,N);
    Postorder(T->right,N);
    if(count==N)
        printf("%d\n",T->Element);
    else{
        printf("%d ",T->Element);
        count++;
    }
    return;
}

