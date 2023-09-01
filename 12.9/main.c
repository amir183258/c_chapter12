#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main() {
	ListNodePtr list = NULL;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
		insert(&list, rand() % 100);

	puts("List: ");
	printList(list);

	ListNodePtr reversed = NULL;
	reverseList(list, &reversed);

	puts("Reversed List: ");
	printList(reversed);

	return 0;
}
