#ifndef _ERROR_HANDLER_H_
#define _ERROR_HANDLER_H_
#endif

#include "error_types.h"

#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif

void error_handler_stack(err_type err, stack* stack);
void error_handler(err_type err);
void view_error_message(err_type err);