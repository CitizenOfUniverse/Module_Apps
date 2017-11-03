//*
//* main.cpp - Main project file. Contains only main function.
//*

//Preventing double including of file "stddef.h". File is needed for NULL constant


#include "stack.h"

#include "stackdbio.h"
#include <conio.h>

//Debug code in C++
////#include <iostream>
//
//using namespace std;


const char *db_file_name = "stack_db_file.bin\0";

int main(){

	DBFile* db = initialize(db_file_name);
	open_db_read(db);
	stack stack_int;
	init(&stack_int);
	load_stack_from_file(db, &stack_int);
	close_db(db);

	//Debug code in C
	int for_add;

	for_add = 1;
	push(&stack_int, for_add);

	for_add = 2;
	push(&stack_int, for_add);

	for_add = 12;
	push(&stack_int, for_add);

	for_add = 7;
	push(&stack_int, for_add);
	open_db_write(db);
	save_stack_to_db(db, &stack_int);//
	clear(&stack_int);
	close_db(db);
	free_db(db);
	_getch();

	return 0;
}

