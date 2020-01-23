/*
	Author: Jiwon Yoo
	Data: March 30, 2016
	Specification file for the Circular Single Linked List Class
*/

#ifndef CLNKDLST_H
#define CLNKDLST_H

#include "Node.h"

class CLnkdLst {
	private:
		Node *head;
		Node *lastNode;
	public:
		// Constructor
		CLnkdLst( int );
	
		// Destructor
		~CLnkdLst();

		// Member Function
		void push_back( int );
		int pop_back();
};

#endif
