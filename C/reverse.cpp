#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
	ElementType Element;
	Position Next;
};

List Read(); /* details omitted */
void Print(List L); /* details omitted */
List Reverse(List L);

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

List Reverse(List L) {
	int i, n, temp;
	n = 0;
	i = 0;
	List p, h;
	h = L;
	p = h->Next;
	int a[20];
	while (p != NULL) {
		a[i] = p->Element;
		p = p->Next;
		i++;
	}

	n = i;
	for (i = 0; i < n / 2; i++) {
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = a[i];
	}
	
	p = h->Next;

	if(n == 0)
		return h;
	else {
		for (i = 0; i < n; i++) {
			p->Element = a[i];
			p = p->Next;
		}
		return h;
	}
}