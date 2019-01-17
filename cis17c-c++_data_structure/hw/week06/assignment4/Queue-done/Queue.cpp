/* 
	Author: Jiwon Yoo
	Date: March 29, 2016
	Implementation file for the Queue class 
*/
#include <iostream>
using namespace std;

// User Libraries
#include "Queue.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
Queue::Queue( int data ) {
	head = new Node;
	head->data = data;
	head->ptr = NULL;	
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
Queue::~Queue() {
	while( head->ptr!=NULL ) {
		Node *temp = new Node;
		temp = head;
		head = head->ptr;
		delete temp;
	}
	delete head;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION :
// POST-CONDITION:
// PURPOSE       : add one data to the front of the Queue
//////////////////////////////////////////////////////////////////////
void Queue::push_front( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->ptr = head;
	head = temp;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : Queue size > 1
// POST-CONDITION: one data removed
// PURPOSE       : Remove one data from the front of the Queue
//////////////////////////////////////////////////////////////////////
int Queue::pop_front() { 
	int data = head->data;
	if( head->ptr==NULL ) return data;

	Node *temp = new Node;
	temp = head;
	head = head->ptr;
	delete temp;	

	return data;
}
