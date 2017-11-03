// One node of the double-linked list
typedef struct node_s{
	int data;//Useful data of node
	struct node_s* prev;//Address of the next node
	struct node_s* next;//Address of the next node
} node;
