#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit(const int N, const int D){
  int a[20];
  int s;
  if(N<0)
  s=-N;
  else
  s=N;
  int i=0;
  int D_count = 0;
  if (N==0){
    if(D==0)
    D_count++;
    else;
  }
  else;
  while(s!=0){
    a[i]=s%10;
    s=s/10;
    i++;
  }
  a[i]=-1;
  for(i=0;a[i]!=-1;i++){
    if(a[i]==D)
    D_count++;
    else;
  }
  return D_count;
}
