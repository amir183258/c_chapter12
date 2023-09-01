struct stackNode {
	int data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int value);
void printStack(StackNodePtr);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
