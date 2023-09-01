#include <stdlib.h>
#include "./stack.h"
#include "./postfix.h"

int evaluatePostfixExpression(char *expr) {
	StackNodePtr stack = NULL;

	int i = 0;
	while (expr[i] != '\0') {
		if (expr[i] >= '0' && expr[i] <= '9') {
			int sum = 0;
			int j = i;
			while (expr[j] >= '0' && expr[j] <= '9') {
				sum = 10 * sum + (expr[j] - '0');
				++j;
			}
			push(&stack, sum);

			i = j - 1;
		}
		else if (isOperator(expr[i])) {
			int x = pop(&stack);
			int y = pop(&stack);

			push(&stack, calculate(y, x, expr[i]));
		}
		++i;
	}

	return pop(&stack);
}

int calculate(int op1, int op2, char operator) {
	switch (operator) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		case '%':
			return op1 % op2;
		case '^':
			int prob = 1;
			for (int i = 0; i < op2; ++i)
				prob *= op1;
			return prob;
	}
}

int isOperator(char ch) {
	int i = 0;
	while (OPERATORS[i] != '\0') {
		if (ch == OPERATORS[i])
			return 1;
		++i;
	}
	return 0;
}
