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
	printList(topPtr);

	char ch;
	printf("%s", "Enter a character to search: ");
	scanf("%c", &ch);


	ListNodePtr searchedNode = searchList(topPtr, ch);
	if (searchedNode != NULL)
		printf("%c is found!\n", searchedNode->data);
	else
		puts("It's not found!");

	return 0;
}
