/*
	Author: Jiwon Yoo
	Date: March 30, 2016
	Implementation file for the Circular Single Linked List Class
*/

// System Libraries
#include <iostream>
#include <cstdlib>	// NULL
using namespace std;

// User Libraries
#include "CLnkdLst.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
CLnkdLst::CLnkdLst(int data ) {
	head = new Node;
	lastNode = new Node;
	head->data = data;
	head->ptr = NULL;	
	lastNode = head;
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
CLnkdLst::~CLnkdLst() {
	lastNode = NULL;
	while( head->ptr!=NULL ) {
		Node *temp = new Node;
		temp = head;
		head = head->ptr;
		delete temp;
	}
	delete head;
	delete lastNode;
		
}

//////////////////////////////////////////////////////////////////////
// RETURN        : void
// PRE-CONDITION : head node exists
// POST-CONDITION: a node added
// PURPOSE       : Insert a node at the back of the list
//////////////////////////////////////////////////////////////////////
void CLnkdLst::push_back( int data ) {
	Node *temp = new Node;
	temp->data = data;
	temp->ptr = head;	// last node poitns to the head
	lastNode->ptr = temp;
	lastNode = temp;	// update the last node
//	cout << ' ' << head->ptr->data << ' '
//		 << lastNode->data << ' ' << lastNode->ptr->data << endl;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : list size > 0
// POST-CONDITION: a node removed
// PURPOSE       : Remove one node located at the back of the list 
//////////////////////////////////////////////////////////////////////
int CLnkdLst::pop_back() {
	int data = lastNode->data;

	// Circular linked list, head never = NULL
	// disconnect the circularity and let head = NULL
	if(head->ptr==lastNode) {
		head->ptr = NULL;
		delete lastNode;
		lastNode = head;
		return data;
	}
	if(head->ptr==NULL) return data;
	
	// delete each nodes
	Node *end = new Node;
	end = head;
	while(end->ptr!=lastNode)  
		end = end->ptr;
	
	// delete one previous the last node
	lastNode = end;
	end = end->ptr;
	delete end;
	lastNode->ptr = head;

	return data;
}
