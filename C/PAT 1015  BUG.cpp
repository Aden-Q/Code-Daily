#include <stdio.h>
#include <stdlib.h>
#define FIRST 1                 //�²ż汸
#define SECOND 2                //�·ֹ��ߵĵ�ʤ��
#define THIRD 3                 //�ŵ¼����ĵ�ʤ��
#define FORTH 4                 //������
#define OUT 5                   //���֮���������ΪOUT
int main(void) {
	int N, L, H;                //������������ͷ����ߡ����ȷ�����
	int i, j;
	int sum;
	static int count;
	struct inf_student {
		int num;
		int v;              //��
		int t;              //��
		int flag;
		int key;
		struct inf_student *next;
	}*head, *p, *q, *tail;
	p = NULL;
	tail = NULL;
	head = (struct inf_student*)malloc(sizeof(struct inf_student));
	head->next = NULL;
	scanf("%d%d%d", &N, &L, &H);
	for (i = 0; i < N; i++) {                                   //������ͷ����
		p = (struct inf_student*)malloc(sizeof(struct inf_student));
		p->next = NULL;
		scanf("%d%d%d", &p->num, &p->v, &p->t);
		if (p->v < L || p->t < L)
			continue;
		else count++;
		if (p->v >= H&&p->t >= H)
			p->flag = FIRST;
		else if (p->v >= H&&p->t < H)
			p->flag = SECOND;
		else if (p->v < H&&p->t < H&&p->v >= p->t)
			p->flag = THIRD;
		else
			p->flag = FORTH;
		if (tail == NULL) {
			tail = p;
			head->next = tail;
		}
		else {
			tail->next = p;
			tail = p;
		}
	}
	printf("%d\n", count);

	p = head->next;
	for (i = 1;; i++) {                       //������FIRST���Ե�,ÿ�ζ����ʵ�һ������ΪFIRST�ĵ�Ԫ
		if (p->flag == FIRST) {               //�ҵ������
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //�ҵ�һ���е����ڵ�
				if (q->flag != FIRST) {
					q = q->next;
					continue;
				}
				else;
				if ((q->t + q->v) > sum) {
					p = q;
					sum = q->t + q->v;
				}
				else if ((q->t + q->v) == sum) {
					if (q->v >= p->v) 
						p = q;
					else;
				}
				else;
				q = q->next;
			}
			printf("%d %d %d\n", p->num, p->v, p->t);
			p->flag = OUT;                     //������
			p = head->next;                    //�ص�ͷ
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	p = head->next;
	for (i = 1;; i++) {                       //������FIRST���Ե�,ÿ�ζ����ʵ�һ������ΪFIRST�ĵ�Ԫ
		if (p->flag == SECOND) {               //�ҵ������
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //�ҵ�һ���е����ڵ�
				if (q->flag != SECOND) {
					q = q->next;
					continue;
				}
				else;
				if ((q->t + q->v) > sum) {
					p = q;
					sum = q->t + q->v;
				}
				else if ((q->t + q->v) == sum) {
					if (q->v >= p->v)
						p = q;
					else;
				}
				else;
				q = q->next;
			}
			printf("%d %d %d\n", p->num, p->v, p->t);
			p->flag = OUT;                     //������
			p = head->next;                    //�ص�ͷ
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	p = head->next;
	for (i = 1;; i++) {                       //������FIRST���Ե�,ÿ�ζ����ʵ�һ������ΪFIRST�ĵ�Ԫ
		if (p->flag == THIRD) {               //�ҵ������
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //�ҵ�һ���е����ڵ�
				if (q->flag != THIRD) {
					q = q->next;
					continue;
				}
				else;
				if ((q->t + q->v) > sum) {
					p = q;
					sum = q->t + q->v;
				}
				else if ((q->t + q->v) == sum) {
					if (q->v >= p->v)
						p = q;
					else;
				}
				else;
				q = q->next;
			}
			printf("%d %d %d\n", p->num, p->v, p->t);
			p->flag = OUT;                     //������
			p = head->next;                    //�ص�ͷ
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	p = head->next;
	for (i = 1;; i++) {                       //������FIRST���Ե�,ÿ�ζ����ʵ�һ������ΪFIRST�ĵ�Ԫ
		if (p->flag == FORTH) {               //�ҵ������
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //�ҵ�һ���е����ڵ�
				if (q->flag != FORTH) {
					q = q->next;
					continue;
				}
				else;
				if ((q->t + q->v) > sum) {
					p = q;
					sum = q->t + q->v;
				}
				else if ((q->t + q->v) == sum) {
					if (q->v >= p->v)
						p = q;
					else;
				}
				else;
				q = q->next;
			}
			printf("%d %d %d\n", p->num, p->v, p->t);
			p->flag = OUT;                     //������
			p = head->next;                    //�ص�ͷ
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	return 0;
}