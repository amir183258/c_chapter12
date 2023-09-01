#include <stdio.h>
#include <stdlib.h>
#include "./postfix.h"
#include "./stack.h"

void convertToPostfix(char infix[], char postfix[]) {
	StackNodePtr stack;
	stack = NULL;

	push(&stack, '(');

	int i = 0;
	while (infix[i] != '\0')
		++i;
	infix[i] = ')';
	infix[++i] = '\0';

	i = 0;
	int j = 0;
	while (!isEmpty(stack) && i < 40) {
		
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j] = infix[i];
			++j;
			
			if (infix[i + 1] < '0' || infix[i + 1] > '9') {
				postfix[j] = ' ';
				++j;
			}
		}
		else if (infix[i] == '(') 
			push(&stack, infix[i]);
		else if (isOperator(infix[i])) {
			while (isOperator(stackTop(stack)) && precedence(stackTop(stack),
						infix[i]) >= 0) {
				postfix[j] = pop(&stack);
				++j;
			}

			push(&stack, infix[i]);
		}
		else if (infix[i] == ')') {
			while (stackTop(stack) != '(') {
				postfix[j] = pop(&stack);
				++j;
			}

			pop(&stack);
		}

		++i;
	}
	postfix[j] = '\0';
}

int isOperator(char c) {
	for (int i = 0; i < OPERATORS_COUNT; ++i)
		if (c == OPERATORS[i])
			return 1;
			
	return 0;
}

int precedence(char operator1, char operator2) {
	enum precedence op1, op2;
	for (int i = 0; HIGHEST_PRECEDENCE[i] != '\0'; ++i) {
		if (operator1 == HIGHEST_PRECEDENCE[i])
			op1 = HIGHEST;
		if (operator2 == HIGHEST_PRECEDENCE[i])
			op2 = HIGHEST;
	}

	for (int i = 0; HIGH_PRECEDENCE[i] != '\0'; ++i) {
		if (operator1 == HIGH_PRECEDENCE[i])
			op1 = HIGH;
		if (operator2 == HIGH_PRECEDENCE[i])
			op2 = HIGH;
	}

	for (int i = 0; LOW_PRECEDENCE[i] != '\0'; ++i) {
		if (operator1 == LOW_PRECEDENCE[i])
			op1 = LOW;
		if (operator2 == LOW_PRECEDENCE[i])
			op2 = LOW;
	}

	// Higher
	if ((op1 == HIGHEST && (op2 == HIGH || op2 == LOW)) ||
	    (op1 == HIGH && op2 == LOW))
		return 1;

	// Equal
	if (op1 == op2)
		return 0;

	// Lower
	if ((op1 == LOW && (op2 == HIGHEST || op2 == HIGH)) ||
	    (op1 == HIGH && op2 == HIGHEST))
		return -1;
}
