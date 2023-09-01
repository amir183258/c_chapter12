#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bin_tree.h"

int main() {
	unsigned int i;
	int item;
	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));

	int data[] = {49, 28, 83, 18, 40, 71, 97, 11, 19, 32, 44, 69, 72, 92, 99};
	for (int i = 0; i < 15; ++i)
		insertNode(&rootPtr, data[i]);

	/*
	puts("The numbers being placed in the tree are: ");
	for (i = 1; i <= 10; ++i) {
		item = rand() % 15;
		printf("%3d", item);
		insertNode(&rootPtr, item);
	}
	*/

	puts("\n\nThe preOrder traversal is: ");
	preOrder(rootPtr);

	puts("\n\nThe inOrder traversal is:");
	inOrder(rootPtr);

	puts("\n\nThe postOrder traversal is:");
	postOrder(rootPtr);

	puts("\n\nThe Tree is:");
	outputTree(rootPtr, 0);
	puts("");

	return 0;
}
