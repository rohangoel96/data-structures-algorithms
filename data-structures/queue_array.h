#define Type int

struct Queue{
	Type* array;
	int size, head, tail;
};

Type deQueue(Queue* q);
void enQueue(Queue *q, Type ele);
Queue* makeQueue(int size);
void printQueue(Queue* q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);