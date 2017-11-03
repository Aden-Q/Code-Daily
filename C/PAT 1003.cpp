#include <stdio.h>
#define MAXLENGTH 100
void cal(char *p);
int count = 0;
int count_P;
int count_T;                 //找P和T的位置
int count_left_A;
int count_middle_A;
int count_right_A = 0;
int main(void)
{
	int n;
	char c;
	char string[MAXLENGTH];
	int i;
	int j;
	scanf("%d", &n);
	getchar();
	for (j = 0; j < n; j++) {
		i = 0;
		count = 0;
		count_P = 0;
		count_T = 0;                 //找P和T的位置
		count_left_A = 0;
		count_middle_A = 0;
		count_right_A = 0;
		while ((c = getchar()) != '\n') {
			if (c != ' ') string[i++] = c;
			else;
		}
		string[i] = '\0';
		cal(string);
	}
	return 0;
}

void cal(char *p) {
	char *p_origin = p;
	int flag = 0;
	while (*p) {                      //寻找按前后顺序为PAT的东西,找到则count变为3
		if (count == 0) {
			if (*p == 'P') 	count++;
			p++;
			continue;
		}
		else if (count == 1) {
			if (*p == 'A') 	count++;
			else goto done;                //如果P后面紧接的不是A的话，退出，count停留，这里保证了只有一个P且后面紧接的是A
			p++;
			continue;
		}
		else if (count == 2) {
			if (*p == 'A') {          //把P后面所有的A读完
				p++;
				continue;
			}
			if (*p == 'T') {
				count++;
				p++;
				break;
			}
		}
		else goto done;
	}
	if (count == 3) {
		while (*p) {
			if (*p != 'A') { flag = 0; goto done; }              //保证了只有一个P和一个T
			else p++;
		}
		flag = 1;                          //没有在上面的循环中跳走，则说明后面的都是A或空字符串
	}


	if (flag == 1) {                    //找到的情况下继续验证是否符合,设置字符标志，统计位数
		p = p_origin;
		while (*p != 'P') {             //得到P的下标
			count_P++;
			p++;
		}
		p = p_origin;
		while (*p != 'T') {             //得到T的下标
			count_T++;
			p++;
		}
		count_left_A = count_P;
		count_middle_A = count_T - count_P - 1;
		p = p_origin + count_T;
		while (*p) {
			if (*p == 'A') count_right_A++;
			else;
			p++;
		}
		if (count_middle_A == 1 && count_left_A == count_right_A);
		else if (count_right_A == count_left_A*count_middle_A);
		else flag = 0;
	}




done:

	if (flag == 0) printf("NO\n");
	else printf("YES\n");
	return;
}
