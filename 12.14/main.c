#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./stack.h"
#include "./postfix.h"

int main() {
	char expression[] = "6 2 + 5 * 18 3 / -";
	printf("Result of %s: %d\n", expression, evaluatePostfixExpression(expression));

	return 0;
}
