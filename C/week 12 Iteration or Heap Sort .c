#include <stdio.h>

#define ElementType int
#define MAXN 101

void InsertionSort(ElementType B[],int N,int p);
void HeapSort(ElementType B[],int N,int p);

int main()
{
    int N, i,j;
    ElementType A[MAXN];
    ElementType B[MAXN];            //第三行数据
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    for (i=0; i<N; i++) scanf("%d", &B[i]);
    for(i=0;i<N-1;i++)
        if(A[i]>A[i+1])
            break;
    for(j=0;j<N-1;j++)
        if(B[j]>B[j+1])
            break;
    if(j>i||(i==j&&i>=1)){                 //是插入排序
        InsertionSort(B, N, j);
        printf("Insertion Sort\n");
        printf("%d",B[0]);
        for (i=1; i<N; i++) printf(" %d", B[i]);
        printf("\n");
    }
    else{
        for(j=N-1;j>0;j--)
            if(B[j]<B[j-1])
                break;
        HeapSort(B, N, j);
        printf("Heap Sort\n");
        printf("%d",B[0]);
        for (i=1; i<N; i++) printf(" %d", B[i]);
        printf("\n");
    }
    
    
    return 0;
}

void InsertionSort(ElementType B[],int N,int p)
{
    int i;
    int tmp=B[p+1];
    for (i=p+1;i>0&&B[i-1]>tmp;i--)
        B[i]=B[i-1];
    B[i]=tmp;
}

void HeapSort(ElementType B[],int N,int p)
{
    int i;
    int bigson;
    int tmp=B[p];
    B[p]=B[0];
    B[0]=tmp;
    for(i=0;i*2+1<=p-1;i=bigson){
        bigson=i*2+1;
        if(bigson+1<=p-1&&B[bigson+1]>B[bigson])
            bigson=bigson+1;
        if(tmp<B[bigson])
            B[i]=B[bigson];
    }
    B[i]=tmp;
}


