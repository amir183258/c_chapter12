#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bin_tree.h"

int main() {
	TreeNodePtr rootPtr;
	rootPtr = NULL;

	srand(time(NULL));

	char str[80] = "Hi this is Amir Hossein Ebrahimi from KNTU.";
	char del[2] = " ";

	char *token;
	token = strtok(str, del);
	while (token != NULL) {
		insertNode(&rootPtr, token);

		token = strtok(NULL, del);
	}

	inOrder(rootPtr);
	puts("");

	return 0;
}
