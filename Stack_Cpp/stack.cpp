/*
* stack.cpp - Describes methods of the stack class
*/

//Preventing double including of file "stack.h"
#include "stack.h"
#include "stddef.h"

// stack class constructor. Initialises both private fields with standart constants
stack::stack(){
	size = 0;
	this->top = NULL;
}
// stack class destructor
stack::~stack(){
	//Memory for every node was allocated separately from every other one,
	//so we also need to delete nodes one by one
	for (int i = 0; i < this->size; i++){
		node* old_top = this->top;//Extracting top node from the stack
		this->top = this->top->getPrev();//Setting a new top in a stack
		delete old_top;//Deleting old top
	}
}
// Method needed to add ("push") data to the top of stack
void stack::push(int data){
	this->top = new node(this->top, data);//Allocating memory for a new node and initialising its fields
	if (this->top == NULL){//If memory wasn't allocated, method throws an exeption
		throw "ERROR! Couldn't allocate memory for an element.";
	}
	this->size++;//Incrementing size of the stack
}
// Method needed to delete the top of stack and return its current useful data
//Returns true on success and false on empty stack
bool stack::pop(int* ret_data){
	if (this->size == 0){//If the stack is empty, there is no to return. So, method throws an exeption
		return false;
		//throw "ERROR! The stack is already empty.";
	}
	else{
		*ret_data = this->top->getData();//Saving data of the old top needed to return
		node* old_top = this->top;//Extracting old top from the stack
		this->top = this->top->getPrev();//Setting a new top of the stack
		this->size--;//Decreasing size
		delete old_top;//Deallocating memory for the top node of the stack
		return true;//Returning useful data of the old top
	}
}
int stack::get_size(){
	return this->size;
}
bool stack::is_empty(){
	if (this->size == 0){
		return true;
	}
	else{
		return false;
	}
}