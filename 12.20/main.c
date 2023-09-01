#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main() {
	ListNodePtr topPtr = NULL;

	srand(time(NULL));

	for (int i = 0; i < 10; ++i) {
		char value = 65 + rand() % 26;
		insert(&topPtr, value);
	}

	puts("Main List:");
	printList(topPtr);

	puts("Reveresed List:");
	printListBackward(topPtr);
	puts("");

	return 0;
}
