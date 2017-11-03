#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode *Tree;
struct Treenode{
    Tree sun[100];
    Tree father;
    int child;
};

int main(void)
{
    int N,M;
    int i,j,r;
    int ID;
    int K;
    int s[110];
    int flag1,flag2;
    int flag;
    static int stack[100];
    int topofstack=-1;
    int count=0;
    Tree T[110];
    scanf("%d %d",&N,&M);
    while(N!=0){
        flag1=0;
        flag2=0;
        if(M>=N){
            scanf("%d %d",&N,&M);
            continue;
        }
        if(N==1){
            count=1;
            printf("%d\n",count);
            scanf("%d %d",&N,&M);
            continue;
        }
        
        for(i=1;i<=M;i++){   //读M行
            scanf("%d %d",&ID,&K);
            for(r=0;r<N;r++){
                if(stack[r]==0)
                    break;
                if(ID==stack[r])
                    break;
            }
            if(ID==stack[r])
                ;
            else{
                stack[++topofstack]=ID;     //压入栈中
                T[ID]=(Tree)malloc(sizeof(struct Treenode));
                for(r=0;r<100;r++)
                    T[ID]->sun[r]=NULL;
            }
            for(j=0;j<K;j++){  //再读K个
                scanf("%d",s+j);
                for(r=0;r<N;r++){
                    if(stack[r]==0)
                        break;
                    if(s[j]==stack[r])
                        break;
                }
                if(s[j]==stack[r])
                    T[ID]->sun[s[j]]=T[s[j]];
                else{
                    stack[++topofstack]=s[j];     //压入栈中
                    T[s[j]]=(Tree)malloc(sizeof(struct Treenode));
                    for(r=0;r<100;r++)
                        T[s[j]]->sun[r]=NULL;
                    T[ID]->sun[s[j]]=T[s[j]];
                }
            }
        }
        
        topofstack=0;
        stack[0]=1;
        while(1){
            flag=0;
            count=0;
           
            flag1=topofstack;
            for(r=flag2;r<=flag1;r++){
                flag=0;
                for(i=0;i<=N;i++){
                    if(T[stack[r]]->sun[i]!=NULL){
                        flag=1;
                        stack[++topofstack]=i;
                    }
                }
                if (flag==0)
                    count++;
            }
            flag2=flag1+1;
            if(flag2>topofstack){
               printf("%d\n",count);
               break;
            }
            else
                printf("%d ",count);
                
            
        }
        
        scanf("%d %d",&N,&M);
    }
    
    return 0;
    
}


