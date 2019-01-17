/*
	Author: Jiwon Yoo
	Date: March 29, 2016
	Implementation file for the Doubly LinkedList class
*/

#include <cstdlib> // NULL
#include <iostream>
using namespace std;

#include "DLnkdLst.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
DLnkdLst::DLnkdLst( int data ) {
	head = new Node;
	tail = new Node;
	head->prev=NULL;
	head->next=NULL;
	head->data=data;
	tail = head;
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
DLnkdLst::~DLnkdLst() {
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
// PRE-CONDITION : -
// POST-CONDITION: A node is added to the list
// PURPOSE       : Add a node at the end of the list
//////////////////////////////////////////////////////////////////////
void DLnkdLst::push_back( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : 
// POST-CONDITION: A node is added to the list
// PURPOSE       : Add a node to the front of the list
//////////////////////////////////////////////////////////////////////
void DLnkdLst::push_front( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : List contains at least one data
// POST-CONDITION: Last node removed
// PURPOSE       : Remove one node located at tail of the list
//////////////////////////////////////////////////////////////////////
int DLnkdLst::pop_back() {
	int data = tail->data;
	if( head->next==NULL ) return data;
	
	Node *end = new Node;
	end = tail->prev;
	delete tail;
	tail = end;
	tail->next = NULL;

	return data;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : List contains at least one data
// POST-CONDITION: Front node removed
// PURPOSE       : Remove one node located at head of the list
//////////////////////////////////////////////////////////////////////
int DLnkdLst::pop_front() {
	int data = head->data;
	if( head->next==NULL ) return data;
	
	Node *temp = new Node;
	temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp; 

	return data;
}
