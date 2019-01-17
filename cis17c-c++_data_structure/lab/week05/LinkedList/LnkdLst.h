/*
	Author: Jiwon Yoo
	Date: March 16, 2016
	Specification file for the LinkedList Class
*/

#ifndef LNKDLST_H
#define LNKDLST_H

// User Libraries
#include "Node.h"

class LnkdLst {
	private:
		Node *front;
	
	public:
		// Consturctor
		LnkdLst( int );

		// Destructor
		~LnkdLst();
			
		// Member Functions
		int pop();	// pull data off the list
		void push( int );	// put data on the list
};
#endif
