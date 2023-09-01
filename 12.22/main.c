#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bin_tree.h"

int main() {
	unsigned int i;
	int item;
	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));

	puts("The numbers being placed in the tree are: ");
	for (i = 1; i <= 10; ++i) {
		item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}

	puts("\n\nThe preOrder traversal is: ");
	preOrder(rootPtr);
	puts("");

	int key;
	printf("%s", "Please enter a key to search: ");
	scanf("%d", &key);

	TreeNodePtr result;
	result = binaryTreeSearch(rootPtr, key);
	if (result != NULL)
		printf("%d is found in tree!\n", result->data);
	else
		puts("The key is not found in the tree!");

	return 0;
}
