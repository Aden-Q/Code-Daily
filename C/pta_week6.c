//
//  main.c
//  6
//
//  Created by 钱泽诚 on 2017/11/8.
//  Copyright © 2017年 钱泽诚. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H )
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H )
{
    ElementType MinElement;
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement;
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;
    
    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
            case 1:
                scanf("%d", &X);
                Insert(X, H);
                break;
            case 0:
                printf("%d ", DeleteMin(H));
                break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}


PriorityQueue Initialize( int MaxElements ){
    PriorityQueue H;
    
    H=malloc(sizeof(struct HeapStruct));
    H->Elements=malloc(100*sizeof(ElementType));
    H->Capacity=100;
    H->Size=0;
    H->Elements[0]=MinData;
    
    return H;
    
}
void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void PercolateUp(int p, PriorityQueue H)
{
    int ik;
    int key=H->Elements[p];
    for(ik=p;H->Elements[ik/2]>key;ik=ik/2)
        H->Elements[ik]=H->Elements[ik/2];
    H->Elements[ik]=key;        //overwrite
}

void PercolateDown(int p, PriorityQueue H)
{
    int ik;
    int sml;
    int key=H->Elements[p];
    for(ik=p;ik*2<=H->Size;){
        if(ik*2+1<=H->Size){
            if(H->Elements[ik*2+1]<H->Elements[ik*2])
                sml=ik*2+1;
            else
                sml=ik*2;
            if(H->Elements[sml]>key)
                break;
            else
                H->Elements[ik]=H->Elements[sml];
            ik=sml;
            }
        else{
            if(H->Elements[ik*2]>=key)
                break;
            else{
                H->Elements[ik]=H->Elements[ik*2];
                ik=ik*2;
            }
        }
    }
    H->Elements[ik]=key;
}
