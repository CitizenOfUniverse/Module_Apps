/*
* stack.h - Contains descriptor of the class stack
*/

// Preventing double including of file "node.h"

#include "node.h"

// Descriptor of the class stack - main of the project
class stack{
private:
	node* top;//Pointer to the top node
	int size;//Size of the stack
public:
	stack();//Class constructor. Initialises both private fields
	~stack();//Class destructor
	bool pop(int* ret_data);///Method needed to delete the top of stack and return its currents useful data. Returns true on success and false on empty stack
	void push(int);// Method needed to add ("push") data to the top of stack. If there was an error in allocating memory, method throws an exeption (type of it is C-string).
	int get_size();//Returns size of the stack
	bool is_empty();//Returns true, if stack is empty, and false otherwise
};
