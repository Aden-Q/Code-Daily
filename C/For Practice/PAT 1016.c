#include <stdio.h>
#include <string.h>
#define MAXLENGTH 12


int main(void) {
	char A[MAXLENGTH];
	char B[MAXLENGTH];
	char DA, DB;
	int i;
	int rea, reb, res;
	rea = 0;
	reb = 0;
	scanf("%s", A);
	getchar();
	DA = getchar();
	getchar();
	scanf("%s", B);
	getchar();
	DB = getchar();
	for (i = 0;; i++) {
		if (A[i] == '\0')
			break;
		else;
		if (A[i] == DA)
			rea = rea * 10 + DA - '0';
		else;
	}
	for (i = 0;; i++) {
		if (B[i] == '\0')
			break;
		else;
		if (B[i] == DB)
			reb = reb * 10 + DB - '0';
		else;
	}
	res = rea + reb;
	printf("%d", res);
	return 0;
}