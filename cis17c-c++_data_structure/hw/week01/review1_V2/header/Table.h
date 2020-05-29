/*
    CIS 17C C++ - Homework: Review 1 
    By  : Jiwon Yoo
    Date: February 22, 2016

    Implementation file for the Table class
*/

#ifndef TABLE_H
#define TABLE_H

// User Libraies
#include "RowAry.h"

class Table {
	private:
		int i_szRow;
		int i_szCol;
		RowAry **Cp_columns;

	public:
		// Constructor
		Table(int,int);
		// Destructor
		~Table();
		// Member Functions
		int getSzRow() {return i_szRow;}
		int getSzCol() {return i_szCol;}
		int getData(int,int);
};

#endif
