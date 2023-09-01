#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int data) {
	QueueNodePtr newPtr;
	newPtr = malloc(sizeof(QueueNode));

	if (newPtr != NULL) {
		newPtr->data = data;
		newPtr->nextPtr = NULL;

		// If queue was empty.
		if ((*headPtr) == NULL) {
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

int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	if ((headPtr != NULL)) {
		QueueNodePtr tempPtr;
		tempPtr = (*headPtr);

		if ((*headPtr) == (*tailPtr)) {
			(*headPtr) = NULL;
			(*tailPtr) = NULL;
		}
		else
			(*headPtr) = (*headPtr)->nextPtr;

		free(tempPtr);
	}
	else
		return 0;
}

void printQueue(QueueNodePtr headPtr) {
	QueueNodePtr currentNode;
	currentNode = headPtr;
	
	while (currentNode != NULL) {
		printf("%d --> ", currentNode->data);
		currentNode = currentNode->nextPtr;
	}
	puts("NULL");
}

int queueSize(QueueNodePtr headPtr) {
	QueueNodePtr currentPtr;
	currentPtr = headPtr;

	int size = 0;

	while (currentPtr != NULL) {
		++size;
		currentPtr = currentPtr->nextPtr;
	}

	return size;
}
