#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./stack.h"

int main() {
	StackNodePtr stack;
	stack = NULL;

	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
		push(&stack, i); //rand() % 100);
				 //
	printStack(stack);
	printf("%d is poped.\n", pop(&stack));
	printStack(stack);

	return 0;
}
