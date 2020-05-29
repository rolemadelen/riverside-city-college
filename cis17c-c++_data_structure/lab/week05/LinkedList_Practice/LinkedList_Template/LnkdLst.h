/*
	Author: Jiwon Yoo
	Linked List Practice
	Specification file for the Linked List Class
*/

#ifndef LNKDLST_H
#define LNKDLST_H

// System Libraries
#include <iostream>
#include <cstdlib>

// User Libraries
#include "Node.h"

template <class T>
class LnkdLst {	
	private:
		Node<T> *front;
	public:
		// Constructor
		LnkdLst( T );
		// Destrutor
		~LnkdLst();
		// Member Functions
		void push( T );
		T pop();
		bool isNull( Node<T> * );
};

template <class T>
LnkdLst<T>::LnkdLst( T data ) {
	front = new Node<T>;
	front->data = data;
	front->ptr = NULL;
}

template <class T>
LnkdLst<T>::~LnkdLst() {
	// delete each nodes
	while(front->ptr!=NULL) {
		Node<T> *temp = front;
		front = front->ptr;
		delete temp;
	}
	// delete the last node
	delete front;
}

template <class T>
void LnkdLst<T>::push( T data ) {
	using namespace std;
	// new node
	Node<T> *next = new Node<T>;
	next->data = data;
	next->ptr=NULL;

	Node<T> *end = front;

	// locate the end of the node
	while(end->ptr!=NULL)
		end = end->ptr;
	// add the node at the end
	end->ptr = next; 
}

template <class T>
T LnkdLst<T>::pop() {
	// pop from the back
	T data = front->data;
	Node<T> *end = front;
	Node<T> *prevEnd;

	// make sure we don't delete the first node
	if(front->ptr==NULL)
		return data;
	// locate the last node
	while(end->ptr!=NULL)  {
		if( isNull(end->ptr) ) prevEnd = end;
		end = end->ptr;
	}
	data = end->data;
	delete end; 	// delete the last node
	prevEnd->ptr = NULL;

	return data;
}

template <class T>
bool LnkdLst<T>::isNull( Node<T> *p ) {
	return (p->ptr==NULL) ? true : false;
}
#endif
