#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif
#include <stdio.h>
#include <conio.h>

#include <stdlib.h>


#include "error_handler.h"


void init(stack* int_stack){
	int_stack->size = 0;
	int_stack->top = NULL;
}
// Deletes the top element and returns its data 
int pop(stack* stack_int, int* top_element){
	if (stack_int->size == 0){//Stack is empty...
		return 0;
	}
	else{//...or contains only one element
		node* newtop = stack_int->top->prev;//Saving previous node
		*top_element = stack_int->top->data;//Saving data of the now top
		free(stack_int->top);//Deleting the now top
		stack_int->size--;//Decreasing the size of the stack
		stack_int->top = newtop;//
		return 1;//Returning data
	}
}

// Pushes one element to the stack
void push(stack* stack_int, int data){
	node* newtop = (node*)malloc(sizeof(node));//Allocating memory for a new top
	if (newtop == NULL){
		error_handler_stack(ERR_ALLOC_MEM, stack_int);
	}
	newtop->data = data;//Adding data
	newtop->prev = stack_int->top;//Adding an address to an old top
	stack_int->top = newtop;//Setting new top to stack structure
	stack_int->size++;//Increasing size of stack
	return;
}

// Returns size of the stack
long size(stack* stack_int){
	return stack_int->size;
}
// Deletes all elements of the stack
void clear(stack* stack_int){
	while (stack_int->size > 0){
		node* now_node = stack_int->top;
		stack_int->top = stack_int->top->prev;
		free(now_node);
		stack_int->size--;
	}
}
//node* generate_test_data() {
//    node* item = (node*) malloc(sizeof(node));
//
//    item->data = 8888;
//    item->junk.mem_chunk = MEM_CHUNK_TEST_VALUE;
//    item->junk.ratio = RATIO_TEST_VALUE;
//    strncpy(item->junk.chunk_dump, CHUNK_DUMP_TEST_VALUE, DUMP_MAX_SIZE);
//    item->prev = NULL;
//
//    return item;
//}
//
//
//void delete_test_data(node *data) {
//    free(data);
//}
