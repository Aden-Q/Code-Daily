#include <stdio.h>

int main(void) {
	int count = 0;
	int origin_coe[20];
	int origin_exp[20];
	static int re_coe[20];
	static int re_exp[20];
	int i;
	int temp;
	char c;

	while (1) {
		scanf("%d", origin_coe + count);
		scanf("%d", origin_exp + count);
		count++;
		c = getchar();
		if (c == '\n') break;
		else continue;
	}
	for (i = 0; i < count; i++) {
		if (origin_exp[i] != 0) {
			re_coe[i] = origin_coe[i] * origin_exp[i];
			re_exp[i] = origin_exp[i] - 1;
		}
		else {
			re_coe[i] = 0;
			re_exp[i] = 0;
		}
	}
	for (i = 0; i < count; i++)
		if (re_coe[i] == 0 && re_coe[i+1] == 0) break;
	temp = i - 1;
	for (i = 0; i < temp ; i++)
		printf("%d %d ", re_coe[i], re_exp[i]);
	 printf("%d %d", re_coe[i], re_exp[i]);
	return 0;
}

