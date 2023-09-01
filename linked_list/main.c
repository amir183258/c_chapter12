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
		printList(topPtr);
	}

	char ch;
	printf("%s", "Enter a character to delete: ");
	scanf("%c", &ch);

	delete(&topPtr, ch);

	printList(topPtr);

	return 0;
}
