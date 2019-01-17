/*
	Author: Jiwon Yoo
	Date: March 28, 2016 
	Specification file for the Stack (LIFO) class
*/

#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include "Node.h"
class Stack {
	private:
		Node *front;
		Node *lastNode;
	public:
		// Constructor
		Stack( int );	

		// Destructor
		~Stack();

		// Member Functions
		void push_back( int );
		int pop_back();
};

#endif
