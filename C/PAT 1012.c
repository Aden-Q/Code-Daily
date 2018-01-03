#include <stdio.h>
#include <math.h>
#define MAXLENGTH 1000
int main(void) {
	int num[MAXLENGTH];
	int i, n;
	static int count;
	int flag = 0;
	static int key;
	static int A[6];
	double r;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", num + i);
	}
	for (i = 0; i < n; i++) {
		if (num[i] % 10 == 0)
			A[1] += num[i];
		else;
	}
	for (i = 0; i < n; i++) {
		if (num[i] % 5 == 1) {
			A[2] += num[i] * pow(-1, flag);
			flag++;
		}
		else;
	}
	for (i = 0; i < n; i++) {
		if (num[i] % 5 == 2)
			A[3]++;
		else;
	}
	for (i = 0; i < n; i++) {
		if (num[i] % 5 == 3) {
			A[4] += num[i];
			count++;
		}
		else;
	}
	r = (double)A[4] / count;
	for (i = 0; i < n; i++) {
		if (num[i] % 5 == 4 && num[i] >= key)
			key = num[i];
		else;
	}

	if (A[1] == 0)
		printf("N ");
	else
		printf("%d ", A[1]);
	if (flag == 0)
		printf("N ");
	else
		printf("%d ", A[2]);
	if (A[3] == 0)
		printf("N ");
	else
		printf("%d ", A[3]);
	if (A[4] == 0)
		printf("N ");
	else
		printf("%.1f ", r);
	if (key == 0)
		printf("N");
	else
		printf("%d", key);
	return 0;
}

