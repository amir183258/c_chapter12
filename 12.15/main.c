#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./queue.h"

#define SIMULATION_TIME 720

int main() {
	QueueNodePtr headPtr, tailPtr;
	headPtr = NULL;
	tailPtr = NULL;

	srand(time(NULL));

	int nextCustomerArrivalTime = rand() % 3 + 1;

	int i = 0;
	int customerMax = 0;
	int longestWaitTime = 0;
	int sum = 0;
	QueueNodePtr currentNode;

	while (i < SIMULATION_TIME) {
		if (nextCustomerArrivalTime == 0) {
			enqueue(&headPtr, &tailPtr, rand() % 4 + 1);
			puts("Next customer arrived!");

			nextCustomerArrivalTime = rand() % 3 + 1;
		}

		if (headPtr != NULL && headPtr->data == 0) {
			dequeue(&headPtr, &tailPtr);
			puts("First customer has been serviced.");
		}

		if (headPtr != NULL)
			headPtr->data = --(headPtr->data);

		--nextCustomerArrivalTime;
		++i;

		// Questions
		printQueue(headPtr);
		printf("%d\n", i);
		customerMax = queueSize(headPtr) > customerMax ? queueSize(headPtr) : customerMax;
		currentNode = headPtr;
		sum = 0;
		while (currentNode != NULL) {
			sum += currentNode->data;
			currentNode = currentNode->nextPtr;
		}
		longestWaitTime = sum > longestWaitTime ? sum : longestWaitTime;
	}

	puts("__________________________________");
	printf("Max customers: %d\n", customerMax);
	printf("Longest Wait Time: %d\n", longestWaitTime);

	return 0;
}
