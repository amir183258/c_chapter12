#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main() {
	ListNodePtr firstList = NULL;
	ListNodePtr secondList = NULL;
	size_t firstListSize;
	size_t secondListSize;

	srand(time(NULL));

	firstListSize = rand() % 10;
	secondListSize = rand() % 10;

	for (int i = 0; i < firstListSize; ++i)
		insert(&firstList, 65 + rand() % 26);

	puts("First List: ");
	printList(firstList);

	for (int i = 0; i < secondListSize; ++i)
		insert(&secondList, 65 + rand() % 26);

	puts("Second List: ");
	printList(secondList);

	puts("Concatenated Lists (insertion is alphabetical):");
	ListNodePtr catList = concatenate(firstList, secondList);
	printList(catList);

	return 0;
}
