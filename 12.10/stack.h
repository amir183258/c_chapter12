struct stackNode {
	char data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, char value);
void printStack(StackNodePtr);
char pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
