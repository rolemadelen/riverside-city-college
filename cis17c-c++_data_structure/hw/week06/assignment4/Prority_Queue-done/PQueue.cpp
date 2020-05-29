/* 
	Author: Jiwon Yoo
	Date: April 2, 2016
	Implementation file for the Prority PQueue class 
*/
#include <iostream>
using namespace std;

// User Libraries
#include "PQueue.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
PQueue::PQueue( int data ) {
	head = new Node;
	head->data = data;
	head->ptr = NULL;	
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
PQueue::~PQueue() {
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
// PURPOSE       : add one data to the front of the PQueue
//////////////////////////////////////////////////////////////////////
void PQueue::push_front( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->ptr = head;
	head = temp;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : PQueue size > 1
// POST-CONDITION: one data removed
// PURPOSE       : Remove one data from the front of the PQueue
//////////////////////////////////////////////////////////////////////
int PQueue::pop_front() { 
	int data = head->data;
	if( head->ptr==NULL ) return data;

	Node *temp = new Node;
	temp = head;
	head = head->ptr;
	delete temp;	

	return data;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : bool
// PRE-CONDITION : at least one data exists
// POST-CONDITION: return boolean value
// PURPOSE       : find a data in the list;
//				   the most recent lookep up data moves to the head
//////////////////////////////////////////////////////////////////////
bool PQueue::find( int data ) {
	Node *temphead = new Node;
	temphead = head;
	// find the data
	while( temphead->data!=data&&temphead->ptr!=NULL ) {
		temphead = temphead->ptr;
	}
		
	// data not found
	if( temphead->data!=data&&temphead->ptr==NULL ) return false;
	// data found
	else { 
		// remove found data 
		remove( data );
		//create a new node with the same data and push_front
		push_front( data );
		return true;
	}
} 

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : --
// POST-CONDITION: Node removed
// PURPOSE       : remove a data found in the list
//////////////////////////////////////////////////////////////////////
void PQueue::remove( int data ) {
	// if data is located at the head
	if( head->data==data ) {
		head = head->ptr;
		return;
	}

	Node *tempHead = new Node;
	tempHead = head;

	//  data is located in btween
	while( tempHead->ptr->data!=data&&tempHead->ptr!=NULL ) {
		tempHead = tempHead->ptr;
	}
	
	// data not found return, else delete node
	if( tempHead->ptr==NULL ) return;
	else tempHead->ptr = tempHead->ptr->ptr;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : -
// POST-CONDITION: displayed all data
// PURPOSE       : print all data in the list
//////////////////////////////////////////////////////////////////////
void PQueue::print() {
	Node *temp = new Node;
	temp = head;
	while(temp->ptr!=NULL) {
		cout << temp->data << ' ';
		temp = temp->ptr;
	}
	cout << temp->data << endl;
}
