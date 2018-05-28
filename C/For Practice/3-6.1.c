#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

ElementType EvalPostfix( char *expr );

int main()
{
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix( expr );
    if ( v < Infinity )
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

ElementType EvalPostfix(char *expr)
{
	int i = 0;
	int j;
  char flag;
	ElementType op1, op2;
	int sign_flag;
	int num_flag;
	struct stack {
		int topstack;
		ElementType array[Max_Expr];
	};
	struct stack S;
	S.topstack = 0;

	for (; expr[i] != '\0';) {
		if (expr[i] == ' ') {    //skip the blank space
			i++;
			continue;
		}
		else;

		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
			if (expr[i + 1] != ' '&&expr[i + 1] != '\0')
				num_flag = 1;
			else
				num_flag = 0;

			if (S.topstack <= 1 && num_flag == 0)
				return Infinity;
			else;           //complete the operation later
		}

		if (expr[i] == '+' && num_flag == 0) {
			op1 = S.array[S.topstack];
			op2 = S.array[S.topstack - 1];
			op1 = op1 + op2;
			S.array[--S.topstack] = op1;
			i++;
			continue;
		}
		else if (expr[i] == '-'&&num_flag == 0) {
			op1 = S.array[S.topstack];
			op2 = S.array[S.topstack - 1];
			op1 = op2 - op1;
			S.array[--S.topstack] = op1;
			i++;
			continue;
		}
		else if (expr[i] == '*'&&num_flag == 0) {
			op1 = S.array[S.topstack];
			op2 = S.array[S.topstack - 1];
			op1 = op1*op2;
			S.array[--S.topstack] = op1;
			i++;
			continue;
		}
		else if (expr[i] == '/'&&num_flag == 0) {
			op1 = S.array[S.topstack];
			op2 = S.array[S.topstack - 1];
			if (op1 == 0)
				return Infinity;
			else;
			op1 = op2 / op1;
			S.array[--S.topstack] = op1;
			i++;
			continue;
		}

		if (expr[i] == '-') {
			sign_flag = -1;
			i++;
		}
		else
			sign_flag = 1;
		j = i;
		for (; expr[j] != ' '&&expr[j] != '\0'; j++);
    flag = expr[j];
		expr[j] = '\0';
		S.array[++S.topstack] = (double)atof(expr+i) * sign_flag;     //insert
    if(flag==' '){
    i=j+1;
    }
    else
    i=j;

	}

	if (S.topstack == 1)
		return S.array[S.topstack];
	else return Infinity;


}
