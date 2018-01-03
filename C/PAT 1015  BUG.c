#include <stdio.h>
#include <stdlib.h>
#define FIRST 1                 //德才兼备
#define SECOND 2                //德分过线的德胜才
#define THIRD 3                 //才德兼亡的德胜才
#define FORTH 4                 //其他类
#define OUT 5                   //输出之后改其属性为OUT
int main(void) {
	int N, L, H;                //考生总数、最低分数线、优先分数线
	int i, j;
	int sum;
	static int count;
	struct inf_student {
		int num;
		int v;              //德
		int t;              //才
		int flag;
		int key;
		struct inf_student *next;
	}*head, *p, *q, *tail;
	p = NULL;
	tail = NULL;
	head = (struct inf_student*)malloc(sizeof(struct inf_student));
	head->next = NULL;
	scanf("%d%d%d", &N, &L, &H);
	for (i = 0; i < N; i++) {                                   //建立空头链表
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
	for (i = 1;; i++) {                       //先找完FIRST属性的,每次都访问第一个属性为FIRST的单元
		if (p->flag == FIRST) {               //找到则输出
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //找第一类中的最大节点
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
			p->flag = OUT;                     //改属性
			p = head->next;                    //回到头
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	p = head->next;
	for (i = 1;; i++) {                       //先找完FIRST属性的,每次都访问第一个属性为FIRST的单元
		if (p->flag == SECOND) {               //找到则输出
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //找第一类中的最大节点
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
			p->flag = OUT;                     //改属性
			p = head->next;                    //回到头
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	p = head->next;
	for (i = 1;; i++) {                       //先找完FIRST属性的,每次都访问第一个属性为FIRST的单元
		if (p->flag == THIRD) {               //找到则输出
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //找第一类中的最大节点
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
			p->flag = OUT;                     //改属性
			p = head->next;                    //回到头
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	p = head->next;
	for (i = 1;; i++) {                       //先找完FIRST属性的,每次都访问第一个属性为FIRST的单元
		if (p->flag == FORTH) {               //找到则输出
			sum = p->t + p->v;
			q = p->next;
			while (q != NULL) {                //找第一类中的最大节点
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
			p->flag = OUT;                     //改属性
			p = head->next;                    //回到头
		}
		else
			p = p->next;
		if (p == NULL)
			break;
		else;
	}

	return 0;
}