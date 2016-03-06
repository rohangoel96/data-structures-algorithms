#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include "queue_array.h"

#define Type int

Queue* makeQueue(int size){
	Queue *q;
	q = (Queue*) malloc(sizeof(Queue));

	if (q)
	{
		q->array = (Type*) malloc(size * sizeof(Type));
		if (q->array)
		{
			q->size = size + 1; // for mod q->size to work properly
			q->head = -1; //points to present starting of queue
			q->tail = -1;//points to ending element of the queue
			return q;
		}
		else{
			cout << "[Error] queue->array could not be allocated memory" <<endl;
		}
	}
	else{
		cout << "[Error] Queue ould not be allocated memory" <<endl;
	}

}


Type deQueue(Queue *q){
	if (!isEmpty(q))
	{
		Type removedElement = q->array[q->head];
		q->head = (q->head + 1) % (q->size); //mod as goes in a circle
		
		if (q->head == q->tail)
		{
			//queue has become empty, revert to initial values
			q->head = -1; 
			q->tail = -1;
		}
		printQueue(q);
		return removedElement;		
	}
	else{
		cout << "[Error] Queue empty. Can't deQueue" <<endl;
	}
}

void enQueue(Queue *q, Type ele){

	//first enque
	if (isEmpty(q))
	{
		q->head = 0;
		q->tail = 0;
	}

	if (!isFull(q))
	{	
		q->tail = (q->tail + 1) % (q->size);	//mod as goes in a circle
		q->array[q->tail] = ele;
		printQueue(q);
	}
	else{
		cout << "[Error] Queue full. Can't enQueue" <<endl;
	}
}

void printQueue(Queue* q){
	if (!isEmpty(q))
	{
		int i = q->head + 1;
		while(i < q->size  && i <= q->tail)
		{
			cout << q->array[i] << " ";
			i++;
		}
	}
	else{
		cout<< "[Warning] Can't print an empty Queue";
	}
	cout << endl;
}

bool isEmpty(Queue *q){
	return (q->head ==-1 && q->tail == -1);
}

bool isFull(Queue *q){
	return q->head == (q->tail + 1) % q->size;
}

int main(int argc, char const *argv[])
{
	
	cout << "Make a Queue of 5 integers"<<endl;
	Queue* q = makeQueue(5);
	
	// enQueue(q,1);
	// enQueue(q,2);
	// enQueue(q,3);
	// enQueue(q,4);
	// enQueue(q,5);
	// enQueue(q,6);

	// deQueue(q);
	// deQueue(q);
	// deQueue(q);
	// deQueue(q);
	// deQueue(q);
	// deQueue(q);

	//doesn't work for circular :(

	enQueue(q,1);
	enQueue(q,2);
	deQueue(q);
	enQueue(q,3);
	enQueue(q,4);
	enQueue(q,5);
	deQueue(q);
	enQueue(q,6);
	enQueue(q,7);

	return 0;
}
