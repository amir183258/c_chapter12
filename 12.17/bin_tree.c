#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_tree.h"

void insertNode(TreeNodePtr *treePtr, char *value) {
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));

		if (*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
			printf("%s not inserted."
					"No memory available.\n",
					value);
	}
	else {
		if (strcmp(value, (*treePtr)->data) <= 0)
			insertNode(&((*treePtr)->leftPtr), value);
		else
			insertNode(&((*treePtr)->rightPtr), value);
	}
}

void inOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%s ", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		printf("%s", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%s", treePtr->data);
	}
}
