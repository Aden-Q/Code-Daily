#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000
int main(void) {
	char s[MAXLENGTH];
	int r[MAXLENGTH];
	int num;
	int i, n;
	static int flag;
	scanf("%s%d", s, &num);
	n = strlen(s);
	for (i = 0; i < n; i++) {
		s[i] = s[i] - '0';
	}

		for (i = 0; i < n; i++) {
			r[i] = (flag * 10 + s[i]) / num;
			flag = (flag * 10 + s[i]) % num;
		}
		i = 0;
		while (r[i] == 0) {
			i++;
			if (i >= n)
				break;
		}
		if (i < n) {
			for (; i < n; i++) {
				printf("%d", r[i]);
			}
			printf(" %d", flag);
		}
		else {
			printf("0 %d",flag);
		}

	return 0;
}