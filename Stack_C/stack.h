#ifndef _STACK_H_
#define _STACK_H_
#endif

//#ifndef _ERROR_HANDLER_H_
//#define _ERROR_HANDLER_H_
//#include "error_handler.h"
//#endif

#include "stddef.h"

// One node of the stack
typedef struct node_s{
	int data;//Useful data of node
	struct node_s* prev;//Address of the previous node
} node;

// Stack descriptor
typedef struct stack_s{
	node* top;// = NULL;//Address of the stack's top
	long size;// = 0;//Size of the stack
} stack;

//
int pop(stack* int_stack, int* top_element);//Deletes the top element and returns its data
void push(stack* int_stack, int data);//Pushes one element to the stack
long size(stack* int_stack);//Returns size of the stack
void clear(stack* int_stack);//Deletes all elements of the stack
void init(stack* int_stack);