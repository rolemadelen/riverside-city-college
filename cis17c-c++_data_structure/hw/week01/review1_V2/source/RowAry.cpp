/*
    CIS 17C C++ - Homework: Review 1 
    By  : Jiwon Yoo
    Date: February 22, 2016

	Implementation file the Table class 
*/

#include <cstdlib>
#include "../header/RowAry.h"

// Constructor
RowAry::RowAry(int sz) {
	i_size = sz;
	ip_rowData = new int[sz];
	fillAry();
}

// Destructor
RowAry::~RowAry(void) {
	delete [] ip_rowData;
}

////11111222222233333333444444444555555566666666777778888888888999999
//// RETURN    : void
//// PARAMETER : NONE
//// PURPOSE   : fill array with random 2 digit numbers
/////////////////////////////////////////////////////////////////////
void RowAry::fillAry(void) {
	for(int i=0; i<i_size; ++i)
		ip_rowData[i] = rand() % 90 + 10;
}
