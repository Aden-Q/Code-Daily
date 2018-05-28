#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t start,stop;
double Ticks;
double Duration;
int seqsearch_iteration(int* a,int n,int m);
int seqsearch_recursion(int* a,int m);
int binsearch_iteration(int* a,int n,int m);
int binsearch_recursion(int* a,int high,int low,int m);


int main()
{
	int repeat,ri;
	int choice;
	int m,n,i,k;
	int result; 
	int *a;
	
	printf(" Choose the fuction\n");                            //suggest users to choose a fuction to test
	printf("1-seqsearch_iteration 2-seqsearch_recursion\n");   //4 functions to choose
	printf("3-binsearch_iteration 4-binsearch_recursion\n");
	scanf("%d",&choice);
	
	printf("\nInput testing times:\n");                             //suggest users to input testing times
	scanf("%d",&repeat);
	
	for(ri=1;ri<=repeat;ri++){
		printf("\nInput size of the array:\n");                   //suggest users to input size of the array
		scanf("%d",&n);
		a=(int*)malloc((n+1)*sizeof(int*));
		for(i=0;i<n;i++){
			a[i]=i;                                             //given a list of ordered n integers, numbered from 0 to n-1
		}
		a[i]=-1;                                                //assign a[i] a negative value to end recursion
		printf("\nInput the number you want to search:\n");       //suggest users to input the nunber to be searched
		scanf("%d",&m);                                         //input the number to be searched
		printf("\nInput cycle times of calling function:\n");     //suggest users to input the cycle times
		scanf("%d",&k);                                         //repeat the function calls for k times to obtain a total run time
		start=clock();                                          //records the ticks at the beginning of the function call 
		
		for(i=0;i<k;i++){
			switch (choice){
				case 1:result=seqsearch_iteration(a,n,m);break;
				case 2:result=seqsearch_recursion(a,m);break;
				case 3:result=binsearch_iteration(a,n,m);break;
				case 4:result=binsearch_recursion(a,n-1,0,m);break;
			} 
		}                                                       //call for function
		
		stop=clock();                                           //records the ticks at the end of the function call
		
		if(result==-1)
		printf("\nNOT FOUND\n");                                  //m is not in the list
		else
		printf("\n%d\n",result);                                  //m is in the list
		
		free(a);
		a=NULL;
		Ticks=(double)(stop-start);
		Duration=Ticks/CLK_TCK;
		printf("Ticks = %f\n",Ticks);
		printf("Duration = %f\n",Duration);
	}
} 





//iterative version of sequential search
int seqsearch_iteration(int* a,int n,int m)
{
	int i;
	
	for(i=0;i<n;i++){                                           //iterate through the list
		if(a[i]==m){
			return i;
			break;                                              //once m is founded in the list, the loop terminates
		}
	}
	if(i==n)
	return -1;                                                  //m is not founded in the list
}


//recursive version of sequential search
int seqsearch_recursion(int* a,int m)
{
	static int result=-1;                                       //if m is not founded, result will remain -1
	
	if(*a==m)
	result=*a;
	else{
		while(*(a+1)>=0){                                       //*(a+1) is in the ordered n integers
			result=seqsearch_recursion(++a,m);                  //check the next integer
			break;
		}
	}
	return result;
}


//interative version of binary search
int binsearch_iteration(int* a,int n,int m)
{
	int high,low,mid;
	
	low=0;
	high=n-1;
	while(low<=high){
		mid=(high+low)/2;                                       //divide the list into two parts 
		if(a[mid]==m)
		break;                                                  //once m is founded in the list, the loop terminates
		else if(a[mid]<m)
		low=mid+1;                                              //search the latter part
		else
		high=mid-1;	                                            //search the fisrt part
	}
	return low>high?-1:mid;                                     //if low>high, m is not founded in the list
}


//recursive version of binary search
int binsearch_recursion(int* a,int high,int low,int m)
{
	int mid;
	
	while(low<=high){
		mid=(high+low)/2;                                       //divide the list into two parts
		if(a[mid]==m)
		break;                                                  //once m is founded in the list, the loop terminates
		else if(a[mid]<m)
		return binsearch_recursion(a,high,mid+1,m);             //search the latter part
		else
		return binsearch_recursion(a,mid-1,low,m);              //search the fisrt part
	}
	return low>high?-1:mid;                                     //if low>high, m is not founded in the list
}
