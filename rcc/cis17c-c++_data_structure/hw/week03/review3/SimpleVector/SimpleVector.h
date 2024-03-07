/*
    Author: Jiwon Yoo
    File: SimpleVector.h
    March 6, 2016, ( BEGIN: 13:02 PM  
                     END :  13:41 PM)
*/

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>		// bad_alloc
#include <cstdlib>	// exit 
using namespace std;

template <class T>
class SimpleVector{
	private:
		T *aptr;			// To point to the allocated array
		int arrSize;		// Number of elements in the array
		int nItems;			// Number of items in the array
		void memError();	// Handles memory allocation errors
		void subError();	// Handles subscripts out of range

	public:
		// Default Constructor
		SimpleVector() 
			{ aptr=0; arrSize=nItems=0; }
		
		// Constructor declaration
		SimpleVector( int );		

		// Constructor declaration
		SimpleVector( const SimpleVector & );
		
		// Destructor declaration	
		~SimpleVector();
	
		// Accessor to return the array size
		int size() const
			{ return arrSize; }
		
		// Accessor to return a specific element
		T getElAt( int );

		// Overloaded [] operator declaration
		T &operator[]( const int & );

		// Add one new value to the array
		void push_back(T);
	
		// Subctract one value from the array
		void pop_off();
};

/////////////////////////////////////////////////////////////////////
// Constructor for SimpleVector class. Sets the size of the array
// and allocates memory for it
/////////////////////////////////////////////////////////////////////
template <class T>
SimpleVector<T>::SimpleVector(int s) {
	arrSize=s;
	nItems=s;
	// Allocate memory for the array.
	try {
		aptr = new T[s];
	} catch( bad_alloc ) {
		memError();
	}

	// Initialzie the array.
	for( int count=0;count<arrSize;++count ) 
		*( aptr+count )=0;
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for SimpleVector class. 
/////////////////////////////////////////////////////////////////////
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
	// Copy the array size
	arrSize = obj.arrSize;
	nItems = obj.nItems;

	// Allocate memory for the array
	aptr = new T [arrSize];
	if(aptr == 0)
		memError();
	
	// Copy the elements of obj's array
	for(int count=0; count<arrSize; ++count)
		*(aptr + count) = *(obj.aptr + count);
}

/////////////////////////////////////////////////////////////////////
// Destructor for SimpleVector class
/////////////////////////////////////////////////////////////////////
template <class T>
SimpleVector<T>::~SimpleVector() {
	if( arrSize>0 )
		delete [] aptr;
}

/////////////////////////////////////////////////////////////////////
// memError function. Displays an error messasge and terminates
// the program when memory allocation fails
/////////////////////////////////////////////////////////////////////
template <class T>
void SimpleVector<T>::memError() {
	cout << "ERROR:Cannot alllocate memory.\n";
	exit(EXIT_FAILURE);
}

/////////////////////////////////////////////////////////////////////
// subError function. Displays an error message and terminate
// the program when a subscript is out of range.
/////////////////////////////////////////////////////////////////////
template <class T>
void SimpleVector<T>::subError() {
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

/////////////////////////////////////////////////////////////////////
// getElAt function. The argument is a subscript.  The function
// returns the value stored at the subscript in the array
/////////////////////////////////////////////////////////////////////
template <class T>
T SimpleVector<T>::getElAt( int sub ) {
	if( sub<0||sub>arrSize )
		subError();

	return aptr[sub];
}

/////////////////////////////////////////////////////////////////////
// Overloaded [] operator. The argument is a subscript.
// This function returns a reference to the element
// in the array indexed by the subscript.
/////////////////////////////////////////////////////////////////////
template <class T>
T &SimpleVector<T>::operator[]( const int &sub ) {
	if( sub<0||sub>arrSize )
		subError();
	
	return aptr[sub];
}

//////////////////////////////////////////////////////////////////////
// Add one new value to the array.
// And double the size of the array
//////////////////////////////////////////////////////////////////////
template <class T>
void SimpleVector<T>::push_back(T val) {
	if(nItems<arrSize)
		aptr[nItems++] = val;
	else {
		try {
			if(arrSize==0) aptr = new T[++arrSize];
			T *temp = new T[arrSize*2];
			for(int i=0;i<arrSize;++i)
				*( temp+i ) = *( aptr+i );
			temp[nItems++] = val;
			arrSize*=2;
			delete [] aptr;
			aptr=temp;
		} catch (bad_alloc) {
			memError();
		}
	}
}
	
//////////////////////////////////////////////////////////////////////
// Remove the last element in the array.
// And halve the size of the array if needed
//////////////////////////////////////////////////////////////////////
template <class T>
void SimpleVector<T>::pop_off() {	
	aptr[--nItems] = 0;
	if( nItems<=arrSize/2 ) {
		try {
			arrSize/=2;
			T *temp = new T[arrSize];
			for(int i=0;i<arrSize;++i)
				*( temp+i ) = *( aptr+i );
			delete [] aptr;
			aptr=temp;
		} catch (bad_alloc) {
			memError();
		}
	}
}
#endif
