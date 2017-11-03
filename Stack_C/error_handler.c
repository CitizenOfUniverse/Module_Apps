
#include "stdio.h"

#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif

#include "error_handler.h"

#include <stdlib.h>

void view_error_message(err_type err){
	switch (err){
	case ERR_ALLOC_MEM:
		printf("ERROR! Couldn't allocate memory\n");
		break;
	case ERR_OPEN_FILE:
		printf("ERROR! Couldn't open file\n");
	case ERR_WRITE_FILE:
		printf("ERROR! Couldn't write info to file\n");
	default:
		break;
	}
}
void error_handler_stack(err_type err, stack* stack){
	view_error_message(err);
	clear(stack);
	exit(1);
}
void error_handler(err_type err){
	view_error_message(err);
	exit(1);
}