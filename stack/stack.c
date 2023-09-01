#include <stdio.h>
#include <stdlib.h>
#include "./stack.h"

void push(StackNodePtr *topPtr, int value) {
	StackNodePtr newPtr;
	newPtr = malloc(sizeof(StackNode));

	if (newPtr != NULL) {

		newPtr->data = value;
		newPtr->nextPtr = (*topPtr);

		(*topPtr) = newPtr;
	}
	else
		puts("Could not insert. Not enough memory!");

}

void printStack(StackNodePtr topPtr) {
	StackNodePtr currentNode;
	currentNode = topPtr;

	while (currentNode != NULL) {
		printf("%d --> ", currentNode->data);
		currentNode = currentNode->nextPtr;
	}
	printf("%s\n", "NULL");
}

int pop(StackNodePtr *topPtr) {
	StackNodePtr tempPtr;
	tempPtr = (*topPtr);

	if (tempPtr != NULL) {
		int data = tempPtr->data;
		(*topPtr) = (*topPtr)->nextPtr;

		free(tempPtr);

		return data;
	}
	return 0;
}

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}
