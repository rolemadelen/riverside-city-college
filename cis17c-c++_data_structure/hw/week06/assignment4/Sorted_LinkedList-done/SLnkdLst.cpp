/*
	Author: Jiwon Yoo
	Data: March 30, 2016
	Implementation file for the Sorted Linked List
*/

// System Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

// User Libraries
#include "SLnkdLst.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
SLnkdLst::SLnkdLst( int data ) {
	nItems = 1;
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
SLnkdLst::~SLnkdLst() {
	tail = NULL;
	while( head->next!=NULL ) {
		Node *temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	delete tail;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : head node exists
// POST-CONDITION: A node added
// PURPOSE       : Sorts the list as insert a node
//////////////////////////////////////////////////////////////////////
void SLnkdLst::push( int data ) {
	Node *temp = new Node;
	temp->data = data;
	
	// check if a new data is greater than the tail->data
	if( tail->data<=data ) {
		temp->next = NULL; // new tail
		temp->prev = tail; 
		tail->next = temp;
		tail = temp; return;
	}
	// check if a new data is less than the current pointing node 
	if( head->data>=data ) {
		temp->next = head;
		temp->prev = NULL;	// new head
		head->prev = temp;
		head = temp; return;
	}

	Node *temphead = new Node;
	temphead = head;
	bool done = false;
	while( !done ) {
		// if new data is between (X < data < Y), where X is 
		// current node->data and Y is current->next node data, insert new node
		if( temphead->data<=temp->data&&temphead->next->data>=temp->data ) {
			temp->prev = temphead;
			temp->next = temphead->next;
			temphead->next = temp;
			temphead->next->prev = temp;		
			done = true; continue;
		}
		temphead = temphead->next;
	}
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : at least one node exists
// POST-CONDITION: A node removed
// PURPOSE       : removes a node located at the tail of the list
//////////////////////////////////////////////////////////////////////
int SLnkdLst::pop_back() {
	return -1;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : at least one node exists
// POST-CONDITION: a node removed
// PURPOSE       : removes a node located at the head of the list
//////////////////////////////////////////////////////////////////////
int SLnkdLst::pop_front() {
	int data = head->data;
	if( head->next==NULL ) return data;
	
	Node *temp = new Node;
	temp = head;
	head = head->next;
	delete temp;
	head->prev = NULL;
	return data;
}
//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : -
// POST-CONDITION: displayed all data
// PURPOSE       : print all data in the list
//////////////////////////////////////////////////////////////////////
void SLnkdLst::print() {
	Node *temp = new Node;
	temp = head;
	while(temp->next!=NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
		cout << temp->data << endl;
}

