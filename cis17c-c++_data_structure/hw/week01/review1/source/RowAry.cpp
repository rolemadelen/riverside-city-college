/* Implementation file for the RowAry class */

// System Libraries
#include <iostream>
#include <cstdlib>	// srand
using namespace std;

// User Libraries
#include "../header/RowAry.h"

//////////////////////////////////////////////////////////////////////
// Contstructor for RowAry class.
// PURPOSE   : Sets the size and allocates memory of the array
//////////////////////////////////////////////////////////////////////
RowAry::RowAry( int sz ) {
	i_rowSz = sz;
	
	// allocate and initialize the array
	init(sz);
}

//////////////////////////////////////////////////////////////////////
// Destructor for RowAry class.
// PURPOSE   : Free the dynamically allocated memory.
//////////////////////////////////////////////////////////////////////
RowAry::~RowAry() {
	delete [] ip_row;
}

//////////////////////////////////////////////////////////////////////
// Fill Array 
// RETURN   : void
// PURPOSE  : fill array with 2 digit random number.
//////////////////////////////////////////////////////////////////////
void RowAry::fillAry(void) {
	// fill array w/ random 2 digit numbers
	for(int i=0; i<i_rowSz; ++i) 
		ip_row[i] = rand()%90 + 10;
}

//////////////////////////////////////////////////////////////////////
// Print Array 
// RETURN   : void
// PARAMETER: int numData
// PURPOSE  : display all the elements in the array.
//			  print n data per line
//////////////////////////////////////////////////////////////////////
void RowAry::prntAry(int n) {
	for(int i=0; i<i_rowSz; ++i)  {
		cout << *(ip_row+i) << ' ';
		if((i+1)%n==0) cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////
// Print Array 2
// RETURN   : void
// PURPOSE  : display all the elements in the array
//////////////////////////////////////////////////////////////////////
void RowAry::prntAry(void) {
	for(int i=0; i<i_rowSz; ++i) 
		cout << *(ip_row+i) << ' ';
	cout << endl;
}

//////////////////////////////////////////////////////////////////////
// Mutator: setSize
// RETURN   : void
// PARAMETER: int size
// PURPOSE  : sets the row size to sz
//////////////////////////////////////////////////////////////////////
void RowAry::setSize(int sz) {
	i_rowSz = sz;

	// deallocate the memory
	delete [] ip_row;

	// re-allocate and re-initialize the array
	init(sz);
}

//////////////////////////////////////////////////////////////////////
// Initialize 
// RETURN   : void
// PARAMETER: int size
// PURPOSE  : allocate memory for the array and initialize the data
//////////////////////////////////////////////////////////////////////
void RowAry::init(int sz) {
	// alloc memory for the array
	ip_row = new int[sz];
	
	// initialize the array
	for(int i=0; i<sz; ++i)
		*(ip_row+i) = 0;
}
