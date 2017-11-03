#include "stddef.h"
#include "dl_list.h"
#include <stdlib.h>


void init(dl_list* dl_list_int){
	dl_list_int->first = NULL;//Address of the stack's top
	dl_list_int->last = NULL;//Address of the stack's top
	dl_list_int->size = 0;//Size of the stack
}
// Deletes the front element, puts its data to ret_data and return 1 on sucess and 0 on fault
//int pop(dl_list* dl_list_int, int* ret_data){
//	if (dl_list_int->size == 0){//Queue is empty...
//		//Element of queue was not deleted - so, return 0
//		return 0;
//	}
//	else{//...or contains only one element
//		node* newtop = dl_list_int->first->next;//Saving next node
//		*ret_data = dl_list_int->first->data;//Saving data of the now front
//		free(dl_list_int->first);//Deleting the now front
//		dl_list_int->size--;//Decreasing the size of the queue
//		dl_list_int->first = newtop;//Setting new front
//		return 1;//Returning data
//	}
//}
// Pushes one element to the begin of list
void push_begin(dl_list* dl_list_int, int data){
	node* newtop = (node*)malloc(sizeof(node));//Allocating memory for a new element
	newtop->data = data;//Adding data
	newtop->prev = NULL;
	newtop->next = dl_list_int->first;
	if (dl_list_int->size == 0){
		newtop->next = NULL;
		dl_list_int->last = dl_list_int->first = newtop;//First and last nodes in 1-element queue are similar
		dl_list_int->size++;//Incrementing size
	}
	else{
		dl_list_int->first->prev = newtop;//Adding an address to an old top
		newtop->next = dl_list_int->first;
		dl_list_int->first = newtop;//Setting new top to stack structure
		dl_list_int->size++;//Increasing size of stack
	}
	return;
}
// Pushes one element to the end of list
void push_end(dl_list* dl_list_int, int data){
	node* newtop = (node*)malloc(sizeof(node));//Allocating memory for a new element
	newtop->data = data;//Adding data
	newtop->next = NULL;
	newtop->prev = dl_list_int->last;
	if (dl_list_int->size == 0){
		dl_list_int->last = dl_list_int->first = newtop;//First and last nodes in 1-element queue are similar
		dl_list_int->size++;//Incrementing size
	}
	else{
		dl_list_int->last->next = newtop;//Adding an address to an old top
		dl_list_int->last = newtop;//Setting new top to stack structure
		dl_list_int->size++;//Increasing size of stack
	}
	return;
}

// Returns size of the queue
long size(dl_list* dl_list_int){
	return dl_list_int->size;
}
node* find(dl_list* dl_list_int, int key){
	node* now_node = dl_list_int->first;
	for (int i = 0; i < dl_list_int->size; i++){
		if (now_node->data == key){
			break;
		}
		else{
			now_node = now_node->next;
		}
	}
	return now_node;
}
// Removes one element of the DL list. Returns 1 on successful removing and 0 otherwise
int remove(dl_list* dl_list_int, int key){
	node* deleting_node = find(dl_list_int, key);
	if (deleting_node == NULL){
		return 0;
	}
	else{
		deleting_node->prev->next = deleting_node->next;
		deleting_node->next->prev = deleting_node->prev;
		free(deleting_node);
		return 1;
	}
}
// Deallocates memory for all elements of the double-linked list
void clear(dl_list* dl_list_int){
	for (int i = 0; i < dl_list_int->size; i++){
		node* deleting = dl_list_int->first;
		dl_list_int->first = dl_list_int->first->next;
		free(deleting);
		dl_list_int->size--;
	}
	dl_list_int->last = NULL;
	return;
}
