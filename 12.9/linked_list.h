struct listNode {
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *topPtr, int value);
void printList(ListNodePtr topPtr);
int delete(ListNodePtr *topPtr, int value);
int isEmpty(ListNodePtr topPtr);

// Question 12.6
ListNodePtr concatenate(ListNodePtr firstList, ListNodePtr secondList);

// Question 12.8
int sumList(ListNodePtr topPtr);
float meanList(ListNodePtr topPtr);

// Question 12.9
void reverseList(ListNodePtr topPtr, ListNodePtr *reversed);
