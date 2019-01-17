/*
	Author: Jiwon Yoo
	Date: March 29, 2016
	Implementation file for the Circular Linked List Class
*/

// System Libraries
#include <cstdlib>	// NULL
#include <iostream>
using namespace std;

// User Libraries
#include "CLnkdLst.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
CLnkdLst::CLnkdLst( int data ) {
	head = new Node;
	tail = new Node;
	head->data = data;
	head->next = NULL;
	head->prev = NULL;
	tail = head;
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
CLnkdLst::~CLnkdLst() { 
	// delete each nodes
	while(head->next!=NULL) {
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}

	// delete last two nodes
	tail = NULL;
	delete tail;
	delete head;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITON  :
// POST-CONDITION: new node(tail) is added
// PURPOSE       : add a node at the tail of the list
//////////////////////////////////////////////////////////////////////
void CLnkdLst::push_back( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;	// (new) tail points to the head
	temp->prev = tail;	// (old) tail points to the new tail
	tail->next = temp;
	tail = temp;	// set new tail
	//head->next = temp;
	head->prev = tail;	// head prev points to the tail
	//cout << head->prev->data << ' ' << head->next->data << endl;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITON  :
// POST-CONDITION: new node (head) is added
// PURPOSE       : add a node at the head of the list
//////////////////////////////////////////////////////////////////////
void CLnkdLst::push_front( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = head;
	temp->prev = tail; // (new)head prev points to the tail
	head->prev = temp; // (old)head prev points to the new head
	head = temp;	// set new head
	//cout << head->prev->data << ' ' << head->data << endl;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITON  : list contains at least one data
// POST-CONDITION: the last node is removed
// PURPOSE       : remove one node located at the tail of the list
//////////////////////////////////////////////////////////////////////
int CLnkdLst::pop_back() {
	int data = tail->data;
	// because this list is circular, head->next is never equal to NULL
	// end the circle and make head->next = NULL
	if(head->next==tail) {
		head->next=NULL;
		delete tail;
		tail=head;
		return data;
	}
	if(head->next==NULL) return data;

	Node *end = new Node;
	end = tail->prev;
	delete tail;
	tail=end;
	tail->next = head; // make sure new tail next points to the head
	//head->prev = tail;
	return data;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITON  : list contains at least one data
// POST-CONDITION: the front node is removed
// PURPOSE       : remove one node located at the head of the list
//////////////////////////////////////////////////////////////////////
int CLnkdLst::pop_front() {
	int data = head->data;
	// because this list is circular, head->next is never equal to NULL
	// end the circle and make head->next = NULL
	if( head->next==tail ) {
		tail = head;
		head = head->next;
		head->next = NULL;
		delete tail;
		return data;
	 }
	if(head->next==NULL) return data;

	Node *temp = new Node;
	temp = head;
	head = head->next; // set new head
	delete temp;	// delete old head
	head->prev = tail; // make sure new head prev points to the tail
	return data;
}
