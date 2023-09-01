struct queueNode {
	TreeNode node;
	struct queueNode *nextPtr;
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, TreeNode node);
TreeNode dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void printQueue(QueueNodePtr headPtr);
