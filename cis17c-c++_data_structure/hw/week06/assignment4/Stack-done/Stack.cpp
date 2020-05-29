/*
    Author: Jiwon Yoo
    Date: March 28, 2016
    Implementation file for the Stack (LIFO) class
*/

#include <iostream>
#include "Stack.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
Stack::Stack( int data ) {
	front = new Node;
	front->data = data;
	front->ptr = NULL;
	lastNode = front;
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
Stack::~Stack() {
	// delete each node
	lastNode = NULL;
	while( front->ptr!=NULL ) {
		Node *temp = front;
		front = front->ptr;
		delete temp;
	}
	// delet the last node
	delete front;
	delete lastNode;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : -
// POST-CONDITION: add data at the end of the list
// PURPOSE       : push Node at the end of the list
//////////////////////////////////////////////////////////////////////
void Stack::push_back( int data ) {
	// Create a new node
	Node *temp = new Node;
	temp->data = data;
	temp->ptr = NULL;

	// Since I remembered the lastNode let lastNode points to the temp
	// and now temp becomes the lastNode
	lastNode->ptr=temp;
	lastNode=temp;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : list size > 0
// POST-CONDITION: last data is removed
// PURPOSE       : pop data from the end of the list
//////////////////////////////////////////////////////////////////////
int Stack::pop_back() {
	int data = lastNode->data;
	if(front->ptr==NULL) return data;

	// locate the one previous to the last Node
	Node *end = new Node;
	end = front;
	while(end->ptr->ptr!=NULL)
		end=end->ptr;
	
	// let one previous to the last one be the lastNode
	lastNode = end;

	// delete the last node
	end = end->ptr;
	delete end;
		
	// lastNode points to empty Node	
	lastNode->ptr = NULL;

	return data;
}
