#include "node.h"
#include "stddef.h"

// Double-linked (DL) list descriptor
typedef struct dl_list_s{
	node* first;//Address of the list's top
	node* last;//Address of the list's top
	long size;//Size of the list
} dl_list;
void init(dl_list* dl_list_int);
//int pop(dl_list* dl_list_int, int* ret_data);//Deletes the top element and returns its data
void push_begin(dl_list* dl_list_int, int data);//Pushes one element to the queue
void push_end(dl_list* dl_list_int, int data);//Pushes one element to the queue
long size(dl_list* dl_list_int);//Returns size of the queue
void clear(dl_list* dl_list_int);
node* find(dl_list* dl_list_int, int key);
int remove(dl_list* dl_list_int, int key);
