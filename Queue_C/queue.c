#include "stddef.h"
#include "queue.h"
#include <stdlib.h>


void init(queue* queue_int){
	queue_int->first = NULL;//Address of the stack's top
	queue_int->last = NULL;//Address of the stack's top
	queue_int->size = 0;//Size of the stack
}
// Deletes the front element, puts its data to ret_data and return 1 on sucess and 0 on fault
int pop(queue* queue_int, int* ret_data){
	if (queue_int->size == 0){//Queue is empty...
		//Element of queue was not deleted - so, return 0
		return 0;
	}
	else{//...or contains only one element
		node* newtop = queue_int->first->next;//Saving next node
		*ret_data = queue_int->first->data;//Saving data of the now front
		free(queue_int->first);//Deleting the now front
		queue_int->size--;//Decreasing the size of the queue
		queue_int->first = newtop;//Setting new front
		return 1;//Returning data
	}
}

// Pushes one element to the queue
void push(queue* queue_int, int data){
	node* newtop = (node*)malloc(sizeof(node));//Allocating memory for a new element
	newtop->data = data;//Adding data
	newtop->next = NULL;
	if (queue_int->size == 0){
		queue_int->last = queue_int->first = newtop;//First and last nodes in 1-element queue are similar
		queue_int->size++;//Incrementing size
	}
	else{
		queue_int->last->next = newtop;//Adding an address to an old top
		queue_int->last = newtop;//Setting new top to stack structure
		queue_int->size++;//Increasing size of stack
	}
	return;
}

// Returns size of the queue
long size(queue* queue_int){
	return queue_int->size;
}
void clear(queue* queue_int){
	for (int i = 0; i < queue_int->size; i++){
		node* deleting = queue_int->first;
		queue_int->first = queue_int->first->next;
		free(deleting);
		queue_int->size--;
	}
	queue_int->last = NULL;
	return;
}