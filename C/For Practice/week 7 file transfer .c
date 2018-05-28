#include <stdio.h>
#define MAXSIZE 10020
int Find(int *a,int x);
int main(int argc, const char * argv[]) {
    int a[MAXSIZE];
    int N,i,count;
    int size1,size2;
    char s;
    int o1,o2;
    scanf("%d",&N);
    for(i=1;i<=N;i++)               //初始化数组
        a[i]=-1;                    //按大小
    while(1){
        getchar();
        scanf("%c",&s);
        if(s=='S')
            break;
        scanf("%d %d",&o1,&o2);
        if(s=='C'){
            if(Find(a,o2)==Find(a,o1)){
                printf("yes\n");
                continue;
            }
            else{
                printf("no\n");
                continue;
            }
        }
        else if(s=='I'){
            size1 = Find(a,o1);
            size2 = Find(a,o2);
            if(a[size1]<=a[size2]){
                a[size1]+=a[size2];
                a[size2]=size1;
            }
            else{
                a[size2]-=a[size1];
                a[size1]=size2;
            }
        }
    }
    count = 0;
    for(i=1;i<=N;i++){
        if(a[i]<0)             //根节点数
            count++;
    }
    if(count==1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n",count);
    
    return 0;
}


int Find(int *a,int x){         //找x的根（类）
    if(a[x]<0)
        return x;
    else
        return Find(a, a[x]);
}
