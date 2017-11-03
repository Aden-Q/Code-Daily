#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct Node *PtrToNode;
struct Node {
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print(Polynomial p); /* details omitted */
Polynomial Add(Polynomial a, Polynomial b);

int main()
{
	Polynomial a, b, s;
	a = Read();
	b = Read();
	s = Add(a, b);
	Print(s);
	return 0;
}

Polynomial Read() {
	int i, n, coe, exp;
	scanf("%d", &n);
	Polynomial head, p, q;
	head = (Polynomial)malloc(sizeof(Polynomial));
	head->Coefficient = 0;
	head->Exponent = 0;
	head->Next = NULL;
	q = head;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &coe, &exp);
		p = (Polynomial)malloc(sizeof(Polynomial));
		p->Coefficient = coe;
		p->Exponent = exp;
		p->Next = NULL;
		if(q==head)
			head->Next = p;
		else 
			q->Next = p;
		q = p;
	}
	return head;

}

void Print(Polynomial p) {
	Polynomial q;
	q = p->Next;

	if (q == NULL)
		printf("%d %d", p->Coefficient, p->Exponent);
	else;

	while (q != NULL) {
		if (q->Next != NULL)
			printf("%d %d ", q->Coefficient, q->Exponent);
		else
			printf("%d %d", q->Coefficient, q->Exponent);
		q = q->Next;
	}
}

Polynomial Add(Polynomial a, Polynomial b) {
	Polynomial p, q, r, head, t;
	p = a->Next;
	q = b->Next;

	head = (Polynomial)malloc(sizeof(Polynomial));
	head->Coefficient = 0;
	head->Exponent = 0;
	head->Next = NULL;
	r = head;
	while (p != NULL || q != NULL) {
		if (p == NULL) {
			r->Next = q;
			break;
		}
		else if (q == NULL) {
			r->Next = p;
			break;
		}
		else if (p->Exponent > q->Exponent) {
			t = (Polynomial)malloc(sizeof(Polynomial));
			t->Coefficient = p->Coefficient;
			t->Exponent = p->Exponent;
			t->Next = NULL;
			r->Next = t;
			r = t;
			p = p->Next;
		}
		else if (p->Exponent < q->Exponent) {
			t = (Polynomial)malloc(sizeof(Polynomial));
			t->Coefficient = q->Coefficient;
			t->Exponent = q->Exponent;
			t->Next = NULL;
			r->Next = t;
			r = t;
			q = q->Next;
		}
		else if (p->Exponent == q->Exponent) {
			t = (Polynomial)malloc(sizeof(Polynomial));
			t->Coefficient = p->Coefficient + q->Coefficient;
			t->Exponent = p->Exponent;
			t->Next = NULL;
			r->Next = t;
			r = t;
			p = p->Next;
			q = q->Next;
		}

	}

	return head;
}
