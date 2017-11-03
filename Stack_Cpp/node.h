/*
* node.h - Contains descriptor of the "helper" class node
*/
#ifndef _NODE_H_
#define _NODE_H_
#endif

// Descriptor of the "helper" class node. One node is one element of the stack
class node{
	node* prev;//Pointer to the previous node
	int data;//Field for useful data of node
public:
	node* getPrev();//"Get" method for "prev" field
	int getData();//"Get" method for "data" field
	node(node*, int);//Class constructor. Initialises both private fields.
};
