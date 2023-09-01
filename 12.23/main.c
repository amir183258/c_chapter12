#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./bin_tree/bin_tree.h"
#include "./queue/queue.h"

int main() {
	srand(time(NULL));

	TreeNodePtr rootPtr;
	rootPtr = NULL;

	int data;
	puts("Data: ");
	for (int i = 0; i < 20; ++i) {
		data = rand() % 100;
		printf("%3d", data);
		insertNode(&rootPtr, data);
	}
	puts("");

	puts("Inorder: ");
	inOrder(rootPtr);
	puts("");

	puts("Level Order: ");
	levelOrder(rootPtr);
	puts("");

	return 0;
}
