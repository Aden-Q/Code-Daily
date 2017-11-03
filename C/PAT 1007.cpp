#include <stdio.h>
#include <math.h>
int cal(int n);
int main(void) {
	int N;
	int p;
	int count = 0;
	int flag_1 = 1;
	scanf("%d", &N);
	for (p = 3; p + 2 <= N; p += 2) {
		if (cal(p) == 0 && cal(p + 2) == 0)
			count++;
		else;
	}
	printf("%d", count);
	return 0;
}

int cal(int n) {
	int i;
	int flag = 0;       //偶数标志,假设一开始为素数
	for (i = 3; i <= sqrt(n); i++)
		if (n%i == 0) {
			flag = 1;        //偶数
			break;
		}
	return flag;
}