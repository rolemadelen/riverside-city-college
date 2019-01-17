
#include <cstdlib>
#include <iostream>
#include "LnkdLst.h"

LnkdLst::LnkdLst( int data ) {
	front = new Node;
	front->data = data;
	front->ptr = NULL;
}

LnkdLst::~LnkdLst() {
	// delete each nodes
	while(front->ptr!=NULL) {
		Node *temp = front;
		front = front->ptr;
		delete temp;
	}
	// delete the last node
	delete front;
}

void LnkdLst::push( int data ) {
	// new node
	Node *next = new Node;
	next->data = data;
	next->ptr=NULL;
	
	Node *end = front;

	// locate the end of the node
	while(end->ptr!=NULL)
		end = end->ptr;
	// add the node at the end
	end->ptr = next; 
}

int LnkdLst::pop() {
	// pop from the back
	int data = front->data;
	Node *end = front;
	Node *prevEnd;

	// make sure we don't delete all nodes
	if(front->ptr==NULL)
		return data;
	// locate the end of last node
	while(end->ptr!=NULL)  {
		if( isNull(end->ptr) ) prevEnd = end;
		end = end->ptr;
	}
	data = end->data;
	delete end;
	prevEnd->ptr = NULL;

	return data;
	
} 

bool LnkdLst::isNull( Node *p ) {
	return (p->ptr==NULL )? true : false;
}
