//#include <iostream>
#include "queue.h"

//using namespace std;

int main(){
	queue queue_int;
	init(&queue_int);
	push(&queue_int, 3);
	push(&queue_int, 7);
	push(&queue_int, 12);
	push(&queue_int, 5);
	int i;
	int result = pop(&queue_int, &i);
	result = pop(&queue_int, &i);
	result = pop(&queue_int, &i);
	clear(&queue_int);
	return 0;
}
