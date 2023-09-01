struct listNode {
	char data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *topPtr, char value);
void printList(ListNodePtr topPtr);
char delete(ListNodePtr *topPtr, char value);
int isEmpty(ListNodePtr topPtr);

// Question 12.6
ListNodePtr concatenate(ListNodePtr firstList, ListNodePtr secondList);
