struct queueNode {
	int data;
	struct queueNode *nextPtr;
};
typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int data);
int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void printQueue(QueueNodePtr headPtr);
int queueSize(QueueNodePtr headPtr);
