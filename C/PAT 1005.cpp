#include <stdio.h>
#define MAXLENGTH 101
void cal(int *, int *,int,int);
int main(void) {
	int n;
	int i,j,k;
	int change;
	int *q;
	int num = 0;
	j = 0;
	scanf("%d", &n);
	static int in[MAXLENGTH];       //����
    static int r[MAXLENGTH];        //���
	q = r;
	for (i = 0; i < n; i++) {
		scanf("%d", in + i);
		r[j++] = in[i];      //����
	}
	for(i=0;i<n;i++)
	cal(in,r,i,n);

	for (j = 0; j < n; j++) {	           //ð��
		for (k = 0; k<n - j; k++)
			if (*(q + k + 1) > *(q + k)) {
				change = *(q + k + 1);
				*(q + k + 1) = *(q + k);
				*(q + k) = change;
			}
	}

	for (i = 0; r[i] != 0; i++) num++;      //ͳ�Ƹ���
	if (num == 0);
	else {
		for(i=0;i<num-1;i++)
		printf("%d ", r[i]);       //���ո�
		printf("%d", r[i]);        //�����ո�
	}
	return 0;

}

void cal(int *p, int *q,int i,int n) {
	int j, k;
	int index;
	int temp = *(p+i);

	while (temp!= 1 && temp != 0) {
		if (i == 0)
			j = 1;
		else j = 0;
		if (temp % 2 == 0) {
			temp /= 2;
			for (; j < n; j++) {
				if (j == i) continue;
				else if (temp == *(q + j))
					*(q + j) = 0;
				else;
			}
		}
		else {
			temp = (3 * temp + 1) / 2;
			for (; j < n; j++) {
				if (j == i) continue;
				else if (temp == *(q + j))
					*(q + j) = 0;
				else;
			}
		}
	}
	return;
}