#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;     //every time  L-> head
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}

int FactorialSum(List L){
  int item=1;
  int i;
  int sum=0;
  while(L!=NULL){
    item=1;
    for (i=1;i<=L->Data;i++)
      item*=i;
    sum+=item;
    L=L->Next;
  }
  return sum;
}
