#include <stdio.h>

#define MAXN 100000

int search(int D[],int p,int N);

int main(void)
{
	int D[MAXN];
	int i;
	int N;
	int count=0;
	int p;
	int temp;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",D+i);
	p=1;	
	p=search(D,p,N);
	while(p!=0){			//还有数没在正确的位置上 
		if(D[0]!=0){
			temp=D[0];
			D[0]=D[temp];
			D[temp]=temp;	//逆交换 
			count++;
		}
		else{		//0在D[0]处但仍在存在未在正确位置上的数，索引值为p
			D[0]=D[p];
			D[p]=0;
			count++;
		}
		p=search(D,p,N);
	}
	printf("%d\n",count);
	
	
	return 0;
}

int search(int D[],int p,int N)
{
	int i=0;
	for(i=p;i<N;i++)
		if(D[i]!=i)
			return i;
	return 0;
}

