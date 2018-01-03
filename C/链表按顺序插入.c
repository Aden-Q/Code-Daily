#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(link)

int main(void) {
	typedef struct node {
		int grade;
		struct node *next;
	}link;
	link *head, *p1, *p2, *p;          //ͷ�ڵ�/��һ���ڵ�/ǰһ���ڵ�/��ǰ�ڵ�
	
	head = NULL;            //����
	int grade;              //�Ӽ��̶�ȡѧ���ɼ�
	scanf("%d",&grade);
	while (grade!=-1) {                 //����-1����
		p = (link*)malloc(LEN);
		p->grade = grade;
		if (head == NULL) {
			head = p;
			p->next = NULL;
		}
		else {                            //Ѱ��Ҫ�����λ��,��ͷ��ʼ��
			p1 = head;
			while (p->grade > p1->grade && p1->next != NULL) {
				p2 = p1;
				p1 = p1->next;
			}
			if (p->grade <= p1->grade) {           //�ҵ������
				if (p1 == head) {                 //������ٱ�ͷ
					head = p;
					p->next = p1;
				}
				else {                        //������ڱ�ͷ
					p2->next = p;
					p->next = p1;
				}
			}

		}
		scanf("%d",&grade);
	}
	p = head;                   //��ӡ����
	while (p) {
		printf("%-4d", p->grade);
		p = p->next;
	}
	printf("\n");



	return 1;
}