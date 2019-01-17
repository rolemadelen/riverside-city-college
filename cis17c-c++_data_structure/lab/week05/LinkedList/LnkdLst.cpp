/*
    Author: Jiwon Yoo
    Date: March 16, 2016
    Implementation file for the LinkedList Class
*/

// System Libraries
#include <cstdlib>	// NULL
#include <assert.h>

// User Libraries
#include "LnkdLst.h"

//////////////////////////////////////////////////////////////////////
//		 Consturctor
//////////////////////////////////////////////////////////////////////
LnkdLst::LnkdLst( int data ) {
	front = new Node;	// creation of the first node
	front->data = data;
	front->ptr = NULL;
}

//////////////////////////////////////////////////////////////////////
//		 Destructor
//////////////////////////////////////////////////////////////////////
LnkdLst::~LnkdLst() {
	// Start at the beginning and delete from the front to the end
	while( front->ptr!=NULL ) {
		Node *temp = front;
		front = front->ptr;
		delete temp;
	}
	// delete the last element
	delete front;
}

//////////////////////////////////////////////////////////////////////
// RETURN		  : int
// PRE-CONDITON	  :
// POST-CONDITION :
// PURPOSE		  : pull data off the list
//////////////////////////////////////////////////////////////////////
int LnkdLst::pop() {
	int data = front->data;
	if(front->ptr!=NULL) {
		Node *temp = front;
		front = front->ptr;
		delete temp;
	}

	return data;
}  

//////////////////////////////////////////////////////////////////////
// RETURN		  : void
// PRE-CONDITON	  :
// POST-CONDITION :
// PURPOSE		  : put data on the list
//////////////////////////////////////////////////////////////////////
void LnkdLst::push( int data ) {
	// Create a node fill it with data
	Node *next = new Node;
	next->data = data;
	next->ptr = NULL;	
	// Find the end of the linked list
	Node *end = front;
	
	while( end->ptr!=NULL )
		end = end->ptr;

	end->ptr = next;	
}
