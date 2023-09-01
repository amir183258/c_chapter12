#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main() {
	ListNodePtr list = NULL;
	srand(time(NULL));

	for (int i = 0; i < 25; ++i)
		insert(&list, rand() % 100);

	puts("List: ");
	printList(list);

	printf("Sum: %d\n", sumList(list));
	printf("Mean: %f\n", meanList(list));

	return 0;
}
