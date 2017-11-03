#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	typedef struct node{
		char name[10];
		float salary;
		struct node *next;
	}link;
	int i = 1;
	link *head, *tail, *p;
	head = NULL;
	tail = NULL;
	char name[10];
	float salary;
	printf("Input your name (\"###\" while end):\n");
	scanf("%s", name);
	printf("Input your salary:\n");
	scanf("%f", &salary);
	while (strcmp(name, "###")) {
		p = (link*)malloc(sizeof link);
		strcpy(p->name, name);
		p->salary = salary;
		p->next = NULL;
		if (head == NULL) {
			head = p;
			tail = p;
		}
		else {
			tail->next = p;
		}
		printf("Input your name (\"###\" while end):\n");
		scanf("%s", name);
		printf("Input your salary:\n");
		scanf("%f", &salary);
	}
	printf("End create and start print:\n");
	p = head;
	while (p) {
		printf("The %d worker:\nname:%s\nsalary:%f\n", i, p->name, p->salary);
		i++;
		p = p->next;
	}
	printf("End print!");
	return 1;

}