#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) {
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
}


int main()
{
    int N, i;
    ElementType A[MAXN];
    
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);
    
    return 0;
}

void merge_pass( ElementType list[], ElementType sorted[], int N, int length )
{
    int i,j,k,l;
    l=0;
    for(i=0;i+length<N;i=i+2*length){
        j=i;
        k=i+length;
        while(j<=i+length-1&&k<=i+2*length-1&&k<N){
            if(list[j]<=list[k])
                sorted[l++]=list[j++];
            else if(list[j]>list[k])
                sorted[l++]=list[k++];
        }
        for(;j<=i+length-1;j++)
            sorted[l++]=list[j];
        for(;k<=i+2*length-1&&k<N;k++)
            sorted[l++]=list[k];
    }
    for(;i<N;i++)
        sorted[l++]=list[i];
}
