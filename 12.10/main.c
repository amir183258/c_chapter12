#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./stack.h"

int main() {
	StackNodePtr stack;
	stack = NULL;

	srand(time(NULL));

	char ch;
	while ((ch = getchar()) != '\n')
		push(&stack, ch);

	printStack(stack);

	puts("Reverse:");
	while (ch = pop(&stack))
		printf("%c", ch);
	puts("");

	return 0;
}
