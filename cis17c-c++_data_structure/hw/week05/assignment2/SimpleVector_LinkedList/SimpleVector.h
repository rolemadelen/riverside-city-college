/*
    Author: Jiwon Yoo
    File: SimpleVector.h
    March 22, 2016, ( BEGIN: 08:28 AM  
                     END :   10:28 AM)
*/

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

// System Libraries
#include <iostream>
#include <new>		// bad_alloc
#include <cstdlib>	// exit, NULL
using namespace std;

// User Libraries
#include "Node.h"

template <typename T>
class SimpleVector{
	private:
		Node<T> *front;		// head of the node
		Node<T> *lastNode;	// remembers the last Node
		int nItems;			// Number of items in the list
		void subError() const;	// Handles subscripts out of range

	public:
		// Default Constructor
		SimpleVector() 
			{ lastNode=front=NULL; nItems=0; }
		
		// Constructor declaration
		SimpleVector( T );		

		// Constructor declaration
		SimpleVector( const SimpleVector & );
		
		// Destructor declaration	
		~SimpleVector();
	
		// Accessor to return a specific element
		T getElAt( const int );

		// Overloaded [] operator declaration
		T &operator[]( const int & ) const;

		// Add one new value to the array
		void push_back(T);
	
		// Subctract one value from the array
		T pop_back();

		// get number of items
		int getSize() const
		{ return nItems; }
};

/////////////////////////////////////////////////////////////////////
// Constructor for SimpleVector class. Sets the size of the array
// and allocates memory for it
/////////////////////////////////////////////////////////////////////
template <typename T>
SimpleVector<T>::SimpleVector(T s) {
	nItems=1;
	front = new Node<T>;
	front->data = s;	
	front->ptr = NULL;
	lastNode = front;
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for SimpleVector class. 
/////////////////////////////////////////////////////////////////////
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
	if( obj.getSize()==0 ) {
		nItems=1;
		front = new Node<T>;
		front->data = 0;
		front->ptr = NULL;
		lastNode = front;
	} else {
		nItems=1;
		front = new Node<T>;
		front->data = obj[0];
		front->ptr = NULL;
		lastNode = front;

		// copy data
		for(int i=1;i<obj.getSize();++i)
			push_back( obj[i] );
	}
} 

/////////////////////////////////////////////////////////////////////
// Destructor for SimpleVector class
/////////////////////////////////////////////////////////////////////
template <typename T>
SimpleVector<T>::~SimpleVector() {
	if( nItems==0 ) return;
	// delete each nodes
	while( front->ptr!=NULL ) {
		Node<T> *temp = front;
		front = front->ptr;
		delete temp;
	}
	// delete the last node
	delete front;
}

/////////////////////////////////////////////////////////////////////
// subError function. Displays an error message and terminate
// the program when a subscript is out of range.
/////////////////////////////////////////////////////////////////////
template <typename T>
void SimpleVector<T>::subError() const {
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

/////////////////////////////////////////////////////////////////////
// getElAt function. The argument is a subscript.  The function
// returns the value stored at the subscript in the List
/////////////////////////////////////////////////////////////////////
template <typename T>
T SimpleVector<T>::getElAt( const int sub ) {
	// index error
	if( sub<0||sub>=nItems ) subError();
	
	int count=0;
	Node<T> *temp = front;
	while( count++!=sub ) temp=temp->ptr;

	return temp->data;
}

/////////////////////////////////////////////////////////////////////
// Overloaded [] operator. The argument is a subscript.
// This function returns a reference to the element
// in the array indexed by the subscript.
/////////////////////////////////////////////////////////////////////
template <typename T>
T &SimpleVector<T>::operator[]( const int &sub ) const {
	// index error
	if( sub<0||sub>=nItems ) subError();
	
	int count=0;
	Node<T> *temp = front;
	while( count++!=sub ) temp=temp->ptr;

	return temp->data;
}

//////////////////////////////////////////////////////////////////////
// Add new node at the end of the List
//////////////////////////////////////////////////////////////////////
template <typename T>
void SimpleVector<T>::push_back(T val) {
	// Create a new node
	Node<T> *next = new Node<T>;
	next->data = val;
	next->ptr = NULL;
	++nItems;

	lastNode->ptr = next;
	lastNode = next;
}
	
//////////////////////////////////////////////////////////////////////
// Remove the first Node in the LinkedList
//////////////////////////////////////////////////////////////////////
template <typename T>
T SimpleVector<T>::pop_back() {	
	// save the current data
	T val = front->data;
	// let next node be the head
	if( front->ptr!=NULL ) {
		Node<T> *temp = front;
		front = front->ptr;
		// remove the first node
		delete temp;
	}
	return val;
}
#endif
