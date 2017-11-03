#include "dl_list.h"

int main(){
	dl_list dl_list_int;
	init(&dl_list_int);
	push_begin(&dl_list_int, 3);
	push_end(&dl_list_int, 7);
	push_end(&dl_list_int, 12);
	push_begin(&dl_list_int, 5);
	int i;
	int result = remove(&dl_list_int, 14);
	result = remove(&dl_list_int, 7);
	result = remove(&dl_list_int, 5);
	result = remove(&dl_list_int, 12);
	clear(&dl_list_int);
	return 0;
}
