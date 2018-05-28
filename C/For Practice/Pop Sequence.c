#include <stdio.h>
#define MAX_SIZE 1500

int main(void)
{
  int M, N, K;
  int i, j, t, s;
  int temp;
  int count;

  scanf("%d %d %d", &M, &N, &K);
  int Mat[MAX_SIZE];
  int S1[MAX_SIZE], S2[MAX_SIZE];
  int top1,top2;
  for(i=0;i<N;i++)
  S1[i]=N-i;

  for(t=0;t<K;t++){
    for(j=0;j<N;j++)
    scanf("%d", &Mat[j]);
    top1=N-1;
    top2=-1;
    for(s=0;s<N;s++){
      temp=Mat[s];
      count=0;
      if(top2>=0){
      if(S2[top2]==temp){
      top2--;
      continue;
    }
  }
      if(top1<=-1);
      else{
        while(S1[top1]<=temp&&top1!=-1&&count<M){
        S2[++top2]=S1[top1];
        count++;
        top1--;
        if(S1[top1+1]==temp)
        break;
        else;
      }
    }
      if(top2<0){
        printf("NO\n");
        break;
      }
      else;

      if(S2[top2]==temp){
      top2--;
      if(top2<-1){
        printf("NO\n");
        break;
      }
      else
      continue;
    }
      else{
        printf("NO\n");
        break;
      }
    }
    if(s==N)
    printf("YES\n");

  }

  return 0;

}
