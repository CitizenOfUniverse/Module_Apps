#include "node.h"
#include "stddef.h"

// Queue descriptor
typedef struct queue_s{
	node* first;// = NULL;//Address of the stack's top
	node* last;// = NULL;//Address of the stack's top
	long size;// = 0;//Size of the stack
} queue;
void init(queue* queue_int);
int pop(queue* queue_int, int* ret_data);//Deletes the top element and returns its data
void push(queue* queue_int, int data);//Pushes one element to the queue
long size(queue* queue_int);//Returns size of the queue
void clear(queue* queue_int);
