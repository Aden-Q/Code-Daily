#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(link)

int main(void) {
	typedef struct node {
		int grade;
		struct node *next;
	}link;
	link *head, *p1, *p2, *p;          //头节点/后一个节点/前一个节点/当前节点
	
	head = NULL;            //空链
	int grade;              //从键盘读取学生成绩
	scanf("%d",&grade);
	while (grade!=-1) {                 //输入-1结束
		p = (link*)malloc(LEN);
		p->grade = grade;
		if (head == NULL) {
			head = p;
			p->next = NULL;
		}
		else {                            //寻找要插入的位置,从头开始找
			p1 = head;
			while (p->grade > p1->grade && p1->next != NULL) {
				p2 = p1;
				p1 = p1->next;
			}
			if (p->grade <= p1->grade) {           //找到插入点
				if (p1 == head) {                 //插入点再表头
					head = p;
					p->next = p1;
				}
				else {                        //如果不在表头
					p2->next = p;
					p->next = p1;
				}
			}

		}
		scanf("%d",&grade);
	}
	p = head;                   //打印链表
	while (p) {
		printf("%-4d", p->grade);
		p = p->next;
	}
	printf("\n");



	return 1;
}