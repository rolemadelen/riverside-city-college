/*
	Author: Jiwon Yoo
	Date: March 30, 2016
	Specification file for the Sorted Linked List Class
*/

#ifndef SLNKDLST_H
#define SLNKDLST_H

// User Libraries
#include "Node.h"

class SLnkdLst {
	private:
		Node *head;
		Node *tail;
		int nItems;
	public:
		// Constructor
		SLnkdLst( int );
	
		// Destructor
		~SLnkdLst();

		// Member Function
		void push( int );
		int pop_back();
		int pop_front();
		void print();
};

#endif
