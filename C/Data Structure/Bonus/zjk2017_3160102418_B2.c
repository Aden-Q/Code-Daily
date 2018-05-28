/* Author: Qian Zecheng; ID: 3160102418; No.02 */ 

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int compare(const void *a,const void *b);
int CalLength(int data[],int N,unsigned long long int p);
int BinarySearch(int Left,int Right,int data[],unsigned long long int flag);

int main(void)
{
	int N;
	unsigned long long int p;				//the case that flag equal to 10^18 may occure 
	int data[MAXN];
	int i;
	scanf("%d %d",&N,&p);					//read from input
	for(i=0;i<N;i++)
		scanf("%d",data+i);					//read from input
	qsort(data,N,sizeof(int),compare);		//using quick sort method to sort the sequence in ascending order
	printf("%d",CalLength(data,N,p));
	return 0;
} 

int compare(const void *a,const void *b)  	//custom define the function for comparision
{  
    return (*(int*)a-*(int*)b);				//return postive value if *a>*b, thus the sorted sequence is ascending
}

int CalLength(int data[],int N,unsigned long long int p)
{
	int i,j;
	int Left,Right;
	int maxlength=1;
	unsigned long long int flag;
	int curlength;
	for(i=0;i<N;i++){					//consider each case with different position of i(left)
		flag=data[i]*p;
		if(flag>=data[N-1]){		//if the last element's index 'N-1' satisfies the requirement,then no need to consider other i
			curlength=N-i;
			if(curlength>maxlength)
				maxlength=curlength;
			break;
		}
		Left=i;							//find M,m from data[Left] to data[Right]
		Right=N-1;
		j = BinarySearch(Left,Right,data,flag);		//find the most right postion with element not larger than data[i]*p
		curlength=j-i+1;				//current length of sequence
		if(curlength>maxlength)			//make sure if maxlength needs to update or not
			maxlength=curlength;		
	}
	return maxlength;
}

int BinarySearch(int Left,int Right,int data[],unsigned long long int flag)		//use binary search to find the best postion for right
{
	int mid=(Left+Right)/2;							//use binary search method to get the best position for M(the right one)
	if(data[mid]<=flag){				//maybe M can be larger
		if(mid+1<=Right&&data[mid+1]>flag||mid+1>Right)				//if mid+1 can be a better choice
			return mid;
		else{
			return BinarySearch(mid+1,Right,data,flag);
		}
	}
	else if(data[mid]>flag){			//M needs to be smaller
		if(mid-1>=Left)					//to avoid the case that left>right
			return BinarySearch(Left,mid-1,data,flag);
		else{
			return mid;
		}
	}
}
