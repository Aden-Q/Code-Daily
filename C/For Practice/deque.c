#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push:
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}


Stack CreateStack( int MaxElements )
{
  Stack S;
  S = (Stack) malloc(sizeof(struct StackRecord));
  if(S==NULL)
  exit(0);
  else;
  S->Array = (ElementType*) malloc(sizeof(ElementType)*(MaxElements+1));
  if(S->Array==NULL)
  exit(0);
  else;
  S->Capacity = MaxElements;
  S->Top1=0;
  S->Top2=0;
  return S;
}

int IsEmpty( Stack S, int Stacknum )
{
  if(Stacknum==1)
  return S->Top1==0;
  else
  return S->Top2==S->Top1;
}

int IsFull( Stack S )
{
  if(S->Top2==S->Capacity)
  return 1;
  else
  return 0;
}

int Push( ElementType X, Stack S, int Stacknum )
{
  int i;
  if(IsFull(S))
  return 0;
  else;
  if(Stacknum==1){
    if(S->Top2==S->Top1)
    S->Top2++;
    else{
      for(i=S->Top2;i>=S->Top1+1;i--){
      S->Array[i+1]=S->Array[i];
      S->Top2++;
    }
    }
    S->Array[++S->Top1]=X;
  }
    else if(Stacknum==2)
      S->Array[++S->Top2]=X;
      else
      return 0;

      return 1;
}

ElementType Top_Pop( Stack S, int Stacknum )
{
  int val;
  int i;
  if(Stacknum==2){
    if(S->Top2==S->Top1)
    return ERROR;
    else;
    S->Top2--;
    return S->Array[S->Top2+1];
  }
  else if(Stacknum==1){
    if(S->Top1==0)
    return ERROR;
    else;
    val = S->Array[S->Top1];
    i=S->Top1;
    S->Top1--;
    for(;i<S->Top2;i++)
    S->Array[i]=S->Array[i+1];
    S->Top2--;
    return val;
  }
  else
  return ERROR;
}
