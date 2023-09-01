#include <stdio.h>
#include <stdlib.h>
#include "../bin_tree/bin_tree.h"
#include "./queue.h"

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNode node) {
	QueueNodePtr newPtr;
	newPtr = malloc(sizeof(QueueNode));

	if (newPtr != NULL) {
		newPtr->node = node;

		// If queue was empty.
		if ((*headPtr) == NULL) {
			newPtr->nextPtr = NULL;

			(*headPtr) = newPtr;
			(*tailPtr) = newPtr;
		}
		else {
			(*tailPtr)->nextPtr = newPtr;
			(*tailPtr) = newPtr;
		}
	}
	else
		puts("Can't enqueue %d. Not enough memory!");

}

TreeNode dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	if ((headPtr != NULL)) {
		TreeNode node;
		node = (*headPtr)->node;

		QueueNodePtr tempPtr;
		tempPtr = (*headPtr);

		if ((*headPtr) == (*tailPtr)) {
			(*headPtr) = NULL;
			(*tailPtr) = NULL;
		}
		else
			(*headPtr) = (*headPtr)->nextPtr;

		free(tempPtr);

		return node;
	}
	else
		puts("The queue is empty!");
}

void printQueue(QueueNodePtr headPtr) {
	QueueNodePtr currentNode;
	currentNode = headPtr;
	
	while (currentNode != NULL) {
		printf("%d --> ", (currentNode->node).data);
		currentNode = currentNode->nextPtr;
	}
	puts("NULL");
}
