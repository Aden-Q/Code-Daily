#include <stdio.h>

int main(void) {
	int i, n;
	static int count_1_C, count_2_C;
	static int count_1_J, count_2_J;
	static int count_1_B, count_2_B;
	static int count;
	int num1, num2;
	char player_1, player_2;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		getchar();
		scanf("%c", &player_1);
		getchar();
		scanf("%c", &player_2);
		if (player_1 == 'C'&&player_2 == 'J')
			count_1_C++;
		else if (player_1 == 'C'&&player_2 == 'B')
			count_2_B++;
		else if (player_1 == 'J'&&player_2 == 'B')
			count_1_J++;
		else if (player_1 == 'J'&&player_2 == 'C')
			count_2_C++;
		else if (player_1 == 'B'&&player_2 == 'C')
			count_1_B++;
		else if (player_1 == 'B'&&player_2 == 'J')
			count_2_J++;
		else
			count++;
	}
	num1 = count_1_B + count_1_J + count_1_C;
	num2 = count_2_B + count_2_J + count_2_C;
	printf("%d %d %d\n", num1, count, num2);
	printf("%d %d %d\n", num2, count, num1);
	i = count_1_J > count_1_B ? count_1_J : count_1_B;
	if (count_1_C > i)
		i = count_1_C;
	else if (i == count_1_J && count_1_C == count_1_J)
		i = count_1_C;
	else;
	if (i == count_1_B)
		printf("B ");
	else if (i == count_1_C)
		printf("C ");
	else
		printf("J ");
	n = count_2_J > count_2_B ? count_2_J : count_2_B;
	if (count_2_C > n)
		n = count_2_C;
	else if (n == count_2_J && count_2_C == count_2_J)
		n = count_2_C;
	else;
	if (n == count_2_B)
		printf("B");
	else if (n == count_2_C)
		printf("C");
	else
		printf("J");
	return 0;
}