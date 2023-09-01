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

	puts("\n\nThe inOrder traversal is:");
	inOrder(rootPtr);

	puts("\n\nThe postOrder traversal is:");
	postOrder(rootPtr);
	puts("");
	puts("");

	printf("Depth of tree is: %d\n", treeDepth(rootPtr));

	return 0;
}
