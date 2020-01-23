/*
	Author: Jiwon Yoo
	Date: March 29, 2016
	Specification file for the Doubly Linked List class
*/

#ifndef DLNKDLIST_H
#define DLNKDLIST_H

#include "Node.h"

class DLnkdLst {
	private:
		Node *head;
		Node *tail;
	public:
		// Constructor
		DLnkdLst( int );
		
		// Destructor
		~DLnkdLst();
	
		// Member Functions
		void push_back( int );
		void push_front( int );
		int pop_back();
		int pop_front();
};

#endif
