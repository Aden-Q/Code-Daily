#include <stdio.h>
#include <math.h>

#define YES 1
#define NO 0

int judegeprime(int n);

int main(int argc, const char * argv[]) {
    int MSize, N;
    int i,j;
    int Hn;
    int Hp;
    int flag;
    scanf("%d %d",&MSize,&N);
    int TSize=MSize;
    if(judegeprime(TSize)==NO)
        while(1)            //得到最小素数，修改tablesize
        {
            TSize++;
            if(judegeprime(TSize)==YES)
                break;
        }
    int Num[TSize];
    for(i=0;i<TSize;i++)
        Num[i]=-1;          //初始化为-1
    for(i=1;i<=N;i++)       //Hash
    {
        flag=0;         //没找到的标识
        scanf("%d",&Hn);
        Hp=0;
        for(j=0;j<TSize;j++)
        {
            Hp=(Hn+j*j)%TSize;
            if(Num[Hp]==-1){
                Num[Hp]=Hn;            //找到了合适的位置
                flag=1;
                break;
            }
        }
        if(flag==1){
            if(i==1)
                printf("%d",Hp);
            else
                printf(" %d",Hp);
        }
        else{
            if(i==1)
                printf("-");
            else
                printf(" -");
        }
    }
    
    return 0;
}

int judegeprime(int n)
{
    int i;
    if(n==1)
        return NO;
    if(n==2)
        return YES;
    int flag=sqrt(n);
    for(i=2;i<=flag;i++)
        if(n%i==0)
            return NO;
    return YES;
}
