#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./stack.h"
#include "./postfix.h"

void test(void);

int main() {
	StackNodePtr stack;
	stack = NULL;

	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
		push(&stack, i + 65); //rand() % 100);
				 //
	printStack(stack);
	printf("%c is poped.\n", pop(&stack));
	printStack(stack);

	puts("\n\n");

	char infix[] = "(62 + 2) * 5 - 8 / 4";
	char postfix[30];

	convertToPostfix(infix, postfix);
	printf("Postfix of %s: %s\n", infix, postfix);

	return 0;
}

void test(void) {
	for (int i = 0; i < OPERATORS_COUNT; ++i)
		for (int j = 0; j < OPERATORS_COUNT; ++j)
			printf("%c and %c: %2d\n", OPERATORS[i], OPERATORS[j],
					precedence(OPERATORS[i], OPERATORS[j]));
}
