#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./queue.h"

int main() {
	QueueNodePtr headPtr, tailPtr;
	headPtr = NULL;
	tailPtr = NULL;

	srand(time(NULL));
	
	for (int i = 0; i < 10; ++i)
		enqueue(&headPtr, &tailPtr, i);

	printQueue(headPtr);

	printf("%d is released.\n", dequeue(&headPtr, &tailPtr));
	printQueue(headPtr);

	return 0;
}
