#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int data) {
	QueueNodePtr newPtr;
	newPtr = malloc(sizeof(QueueNode));

	if (newPtr != NULL) {
		newPtr->data = data;

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

int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr) {
	if ((headPtr != NULL)) {
		if ((*headPtr) == (*tailPtr)) {
			(*headPtr) = NULL;
			(*tailPtr) = NULL;
		}
		else {
			QueueNodePtr tempPtr;
			tempPtr = (*headPtr);

			(*headPtr) = (*headPtr)->nextPtr;

			free(tempPtr);
		}
	}
	else
		puts("The queue is empty!");
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
