#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push:
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject:
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}


Deque CreateDeque()
{
  PtrToNode header = (PtrToNode)malloc(sizeof(struct Node));
  Deque D = (Deque)malloc(sizeof(struct DequeRecord));
  header->Next=NULL;
  header->Last=NULL;
  D->Front=header;
  D->Rear=header;
  return D;
}

int Push( ElementType X, Deque D )
{
  PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
  if(temp==NULL)
  return 0;
  else;
  temp-> Element=X;
  temp->Last=D->Front;
  if(D->Rear==D->Front){
  temp->Next=NULL;
  D->Rear=temp;
  D->Front->Next=temp;
}
  else{
    temp->Next=D->Front->Next;
    temp->Next->Last=temp;
    D->Front->Next=temp;
  }
  return 1;
}

ElementType Pop( Deque D )
{
  if(D->Front==D->Rear)
  return ERROR;
  else;
  ElementType r;
  PtrToNode temp = D->Front->Next;
  r=temp->Element;
  if(D->Front->Next==D->Rear){
    D->Rear=D->Front;
    D->Rear->Next=NULL;
    free(temp);
    return r;
  }
  else{
  D->Front->Next=temp->Next;
  temp->Next->Last=D->Front;
  free(temp);
  return r;
  }

}

int Inject( ElementType X, Deque D )
{
  PtrToNode temp = (PtrToNode)malloc(sizeof(struct Node));
  if(temp==NULL)
  return 0;
  else;
  temp-> Element=X;
  temp->Last=D->Rear;
  temp->Next=NULL;
  D->Rear->Next=temp;
  D->Rear=temp;
  return 1;
}

ElementType Eject( Deque D )
{
  if(D->Front==D->Rear)
  return ERROR;
  else;
  ElementType r;
  PtrToNode temp = D->Rear;
  r= temp->Element;
  D->Rear=D->Rear->Last;
  D->Rear->Next=NULL;
  free(temp);
  return r;
}
