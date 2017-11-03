#include <stdio.h>
#include <math.h>
int prime(int n);
int main(void) {
	int count;
	int row;
	int i, k, n, m;
	int flag;
	scanf("%d%d", &n, &m);
	i = 0;
	count = 0;
	flag = 1;
	for (k = 2;; k++) {
		if (prime(k) == 1) {
			count++;
			if (flag >= 1 && flag <= 9 && count >= n && count < m) {
				printf("%d ", k);
				flag++;
			}
			else if (flag == 10 && count >= n && count < m) {
				printf("%d\n", k);
				flag = 1;
			}
		}
		else;
		if (count == m)
			break;
		else;
	}
	printf("%d", k);
	return 0;
}
int prime(int n) {
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
		else;
	}
	return 1;
}

