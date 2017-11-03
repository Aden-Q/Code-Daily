#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber(const int N){
   int i, j;
   int test;
   int flag=0;
   test = sqrt(N);
   static int a[10];
   int s = N;
   i=0;
   while(s!=0){
     a[i]=s%10;
     s=s/10;
     i++;
   }
   a[i]=-1;    //flag ofend

     for(j=1;a[j]!=-1;j++){
       if(a[0]==a[j]){
         flag=1;
         break;
       }
     }

   for(i=1;a[i]!=-1;i++){
     for(j=i+1;a[j]!=-1;j++){
       if(a[i]==a[j]){
         flag=1;
         break;
       }
     }
   }
   if(flag==0)
   return 0;
   else;

   for(i=test-1;i<=test+1;i++){
     if(i*i==N)
     return 1;
   }
   return 0;
}
