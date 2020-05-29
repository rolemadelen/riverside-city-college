/*
    CIS 17C C++ - Homework: Review 1 
    By  : Jiwon Yoo
    Date: February 22, 2016

	Implementation file for the Table class
*/

#include <iostream>
using namespace std;

#include "../header/Table.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
Table::Table(int r, int c) {
	i_szCol = c;
	i_szRow = r;
	Cp_columns = new RowAry *[r];
	for(int i=0; i<r; ++i)
		*(Cp_columns+i) = new RowAry(c);
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
Table::~Table() {
	for(int i=0; i<i_szRow; ++i)
		delete Cp_columns[i];
	delete [] Cp_columns;
	Cp_columns = NULL;
}

////11111111222222233333344444445555556666666777777778888888999999999
//// RETURN    : int data
//// PARAMETER : int row, int column
//// PURPOSE   : return data at position[row][col]
//////////////////////////////////////////////////////////////////////
int Table::getData(int r, int c) {
	return Cp_columns[r]->getData(c);
}
