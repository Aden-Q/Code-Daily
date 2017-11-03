#include <stdio.h>
#include <string.h>
#define MAXLENGTH 80
int main(void) {
	int j = 0;
	int i;
	int t = 0;
    char string[MAXLENGTH][MAXLENGTH];                  //最大行数(最大单词数)
	char c;
	while (1) {
		c = getchar();
		if (c != ' '&&c != '\n') {
			string[j][t++] = c;
			continue;
		}
		else if (c == ' ') {
			string[j][t] = '\0';
			j++;
			t = 0;
			continue;
		}
		else {
			string[j][t] = '\0';
			break;
		}
	}
	for (i = j; i > 0; i--)
		printf("%s ", string[i]);
	printf("%s", string[0]);



	return 0;
}

