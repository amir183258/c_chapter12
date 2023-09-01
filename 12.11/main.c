#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./stack.h"

int main() {
	StackNodePtr stack;
	stack = NULL;

	srand(time(NULL));

	char str[10];
	int i = 0;
	
	char ch;
	while ((ch = getchar()) != '\n')
		if (ch != ' ' &&
				ch != ',' &&
				ch != '.' &&
				ch != ';' &&
				ch != ':') {
			push(&stack, ch);
			str[i] = ch;
			++i;
		}
	str[i] = '\0';


	printStack(stack);

	puts("Main:");
	printf("%s\n", str);

	int palindrome = 1;
	i = 0;

	puts("Reverse:");
	while (ch = pop(&stack)) {
		if (ch != str[i])
			palindrome = 0;
		printf("%c", ch);
		++i;
	}
	puts("");

	if (palindrome)
		puts("Yes");
	else
		puts("No");

	return 0;
}
