/*
	Author: Jiwon Yoo
	Linked List Practice
	Specification file for the Linked List Class
*/

#ifndef LNKDLST_H
#define LNKDLST_H

// User Libraries
#include "Node.h"

class LnkdLst {	
	private:
		Node *front;
	public:
		// Constructor
		LnkdLst( int );
		// Destrutor
		~LnkdLst();
		// Member Functions
		void push( int );
		int pop();
		bool isNull( Node * );
};

#endif
