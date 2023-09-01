#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../bin_tree/bin_tree.h"
#include "./queue.h"

int main() {
	srand(time(NULL));

	TreeNodePtr rootPtr;
	rootPtr = NULL;

	int data;
	for (int i = 0; i < 20; ++i) {
		data = rand() % 100;
		printf("%d ", data);
		insertNode(&rootPtr, data);
	}
	puts("");

	inOrder(rootPtr);
	puts("");

	QueueNodePtr headPtr;
	QueueNodePtr tailPtr;
	headPtr = NULL;
	tailPtr = NULL;

	TreeNodePtr currentTreeNode;
	currentTreeNode = rootPtr;

	while (currentTreeNode != NULL) {
		enqueue(&headPtr, &tailPtr, *currentTreeNode);
		currentTreeNode = currentTreeNode->leftPtr;
	}
	printQueue(headPtr);

	printf("%d is dequeued.\n", (dequeue(&headPtr, &tailPtr)).data);
	printQueue(headPtr);

	return 0;
}
