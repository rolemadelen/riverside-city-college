/* Implementation file for the Table class */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "../header/Table.h"

///////////////////////////////////////////////////////////////////////
// Constructor
// PURPOSE   : sets row size and create a dynamic array;
//////////////////////////////////////////////////////////////////////
Table::Table(int r, int c) {
	i_colSz = c;
	i_rowSz = r;
	Cp_row = new RowAry[r];

	for(int i=0; i<r; ++i)
		(&Cp_row[i])->setSize(c);
}

//////////////////////////////////////////////////////////////////////
// Destructor
// PURPOSE   : Deallocate the memory 
//////////////////////////////////////////////////////////////////////
Table::~Table() {
	delete [] Cp_row;
}

//////////////////////////////////////////////////////////////////////
// Fill Array
// RETURN   : void
// PURPOSE  : Fill array with random 2 digit numbers
//////////////////////////////////////////////////////////////////////
void Table::fillAry(void) {
	for(int i=0; i<i_rowSz; ++i)  
		(&Cp_row[i])->fillAry();
}

//////////////////////////////////////////////////////////////////////
// Print Array
// RETURN   : void
// PURPOSE  : Print every elements in the array
//////////////////////////////////////////////////////////////////////
void Table::prntAry(void) {
	for(int i=0; i<i_rowSz; ++i)
		(&Cp_row[i])->prntAry();
}