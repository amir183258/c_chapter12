#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

void insertNode(TreeNodePtr *treePtr, int value) {
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));

		if (*treePtr != NULL) {
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else
			printf("%d not inserted."
					"No memory available.\n",
					value);
	}
	else {
		if (value < (*treePtr)->data)
			insertNode(&((*treePtr)->leftPtr), value);
		else if (value > (*treePtr)->data)
			insertNode(&((*treePtr)->rightPtr), value);
	}
}

void inOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		printf("%3d", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%3d", treePtr->data);
	}
}

TreeNodePtr binaryTreeSearch(TreeNodePtr treePtr, int value) {
	if (treePtr == NULL)
		return NULL;

	if (treePtr->data == value)
		return treePtr;

	if (value < treePtr->data)
		binaryTreeSearch(treePtr->leftPtr, value);
	else
		binaryTreeSearch(treePtr->rightPtr, value);
}

