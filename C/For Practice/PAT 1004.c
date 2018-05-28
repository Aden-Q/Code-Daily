#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
	char name[15];
	char num[15];
	char grade[15];
	int sum;
};
void cal(struct student *p);
int main(void)
{
	int n;
	int i, j;
	int max_index = 0;               //最高和最低成绩学生的下标
	int min_index = 0;
	char string[50];
	struct student *p;
	scanf("%d", &n);
	p = (struct student*)malloc(n * sizeof(struct student));
	for (i = 0; i < n; i++) {
		(p + i)->sum = 0;
		scanf("%s", string);
		strcpy((p + i)->name, string);
		scanf("%s", string);
		strcpy((p + i)->num, string);
		scanf("%s", string);
		strcpy((p + i)->grade, string);
		cal(p + i);                  //成绩转换
	}
	
	for (i = 0; i < n; i++) {
		if ((p + i)->sum > (p + max_index)->sum) max_index = i;
	}
	for (i = 0; i < n; i++) {
		if ((p + i)->sum <(p + min_index)->sum) min_index = i;
	}
	printf("%s %s\n", (p + max_index)->name, (p + max_index)->num);
	printf("%s %s\n", (p + min_index)->name, (p + min_index)->num);



	return 0;
}

void cal(struct student *p) {
	int n=0;
	int i;
	while (p->grade[n]) {
		n++;
	}
	n--;                       //最小的那一位的下标
	for (i = 0; i <=n; i++) {
		p->sum = p->sum * 10 + (p->grade[i] - 48);
	}
	return;

}