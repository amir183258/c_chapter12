#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void insert(ListNodePtr *topPtr, int value) {
	ListNodePtr newPtr;
	ListNodePtr currentPtr, previousPtr;

	newPtr = malloc(sizeof(ListNode));

	if (newPtr != NULL) {
		newPtr->data = value;

		currentPtr = *topPtr;
		previousPtr = NULL;

		while (currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = currentPtr;
			(*topPtr) = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else
		puts("Could not create node. Not enough memory!");
}

void printList(ListNodePtr topPtr) {
	ListNodePtr currentPtr;
	currentPtr = topPtr;

	while (currentPtr != NULL) {
		printf("%d --> ", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	puts("NULL");
}

int delete(ListNodePtr *topPtr, int value) {
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	if ((*topPtr)->data == value) {
		tempPtr = (*topPtr);
		(*topPtr) = (*topPtr)->nextPtr;
		free(tempPtr);
		return value;
	}
	else {
		previousPtr = (*topPtr);
		currentPtr = (*topPtr)->nextPtr;

		while (currentPtr != NULL && currentPtr->data != value) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

int isEmpty(ListNodePtr topPtr) {
	return topPtr == NULL;
}

// Question 12.6
ListNodePtr concatenate(ListNodePtr firstList, ListNodePtr secondList) {
	ListNodePtr concatenated = NULL;
	ListNodePtr currentNode = secondList;

	while (currentNode != NULL) {
		insert(&concatenated, currentNode->data);
		currentNode = currentNode->nextPtr;
	}

	currentNode = firstList;
	while (currentNode != NULL) {
		insert(&concatenated, currentNode->data);
		currentNode = currentNode->nextPtr;
	}

	return concatenated;
}

// Question 12.8
int sumList(ListNodePtr topPtr) {
	int sum = 0;
	while (topPtr != NULL) {
		sum += topPtr->data;
		topPtr = topPtr->nextPtr;
	}

	return sum;
}

float meanList(ListNodePtr topPtr) {
	int sum = 0;
	int i = 0;
	while (topPtr != NULL) {
		sum += topPtr->data;
		topPtr = topPtr->nextPtr;
		++i;
	}

	return (float)(sum) / i;
}
