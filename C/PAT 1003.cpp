#include <stdio.h>
#define MAXLENGTH 100
void cal(char *p);
int count = 0;
int count_P;
int count_T;                 //��P��T��λ��
int count_left_A;
int count_middle_A;
int count_right_A = 0;
int main(void)
{
	int n;
	char c;
	char string[MAXLENGTH];
	int i;
	int j;
	scanf("%d", &n);
	getchar();
	for (j = 0; j < n; j++) {
		i = 0;
		count = 0;
		count_P = 0;
		count_T = 0;                 //��P��T��λ��
		count_left_A = 0;
		count_middle_A = 0;
		count_right_A = 0;
		while ((c = getchar()) != '\n') {
			if (c != ' ') string[i++] = c;
			else;
		}
		string[i] = '\0';
		cal(string);
	}
	return 0;
}

void cal(char *p) {
	char *p_origin = p;
	int flag = 0;
	while (*p) {                      //Ѱ�Ұ�ǰ��˳��ΪPAT�Ķ���,�ҵ���count��Ϊ3
		if (count == 0) {
			if (*p == 'P') 	count++;
			p++;
			continue;
		}
		else if (count == 1) {
			if (*p == 'A') 	count++;
			else goto done;                //���P������ӵĲ���A�Ļ����˳���countͣ�������ﱣ֤��ֻ��һ��P�Һ�����ӵ���A
			p++;
			continue;
		}
		else if (count == 2) {
			if (*p == 'A') {          //��P�������е�A����
				p++;
				continue;
			}
			if (*p == 'T') {
				count++;
				p++;
				break;
			}
		}
		else goto done;
	}
	if (count == 3) {
		while (*p) {
			if (*p != 'A') { flag = 0; goto done; }              //��֤��ֻ��һ��P��һ��T
			else p++;
		}
		flag = 1;                          //û���������ѭ�������ߣ���˵������Ķ���A����ַ���
	}


	if (flag == 1) {                    //�ҵ�������¼�����֤�Ƿ����,�����ַ���־��ͳ��λ��
		p = p_origin;
		while (*p != 'P') {             //�õ�P���±�
			count_P++;
			p++;
		}
		p = p_origin;
		while (*p != 'T') {             //�õ�T���±�
			count_T++;
			p++;
		}
		count_left_A = count_P;
		count_middle_A = count_T - count_P - 1;
		p = p_origin + count_T;
		while (*p) {
			if (*p == 'A') count_right_A++;
			else;
			p++;
		}
		if (count_middle_A == 1 && count_left_A == count_right_A);
		else if (count_right_A == count_left_A*count_middle_A);
		else flag = 0;
	}




done:

	if (flag == 0) printf("NO\n");
	else printf("YES\n");
	return;
}
