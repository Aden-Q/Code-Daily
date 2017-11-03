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
	static int in[MAXLENGTH];       //输入
    static int r[MAXLENGTH];        //结果
	q = r;
	for (i = 0; i < n; i++) {
		scanf("%d", in + i);
		r[j++] = in[i];      //复制
	}
	for(i=0;i<n;i++)
	cal(in,r,i,n);

	for (j = 0; j < n; j++) {	           //冒泡
		for (k = 0; k<n - j; k++)
			if (*(q + k + 1) > *(q + k)) {
				change = *(q + k + 1);
				*(q + k + 1) = *(q + k);
				*(q + k) = change;
			}
	}

	for (i = 0; r[i] != 0; i++) num++;      //统计个数
	if (num == 0);
	else {
		for(i=0;i<num-1;i++)
		printf("%d ", r[i]);       //带空格
		printf("%d", r[i]);        //不带空格
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