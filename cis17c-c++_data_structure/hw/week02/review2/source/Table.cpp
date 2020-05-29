/*
    Author: Jiwon Yoo
    File: main.cpp
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )

	Implementation file for the Table class
*/

// User Libraries
#include "../header/Table.h"

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
Table::Table(uint r, uint c) {
	i_rowSz = r;	
	i_colSz = c;
	Cp_columns = new RowAry *[r];
	for(int i=0;i<r;++i)
		Cp_columns[i] = new RowAry(c);
}

//////////////////////////////////////////////////////////////////////
// Copy Constructor
//////////////////////////////////////////////////////////////////////
Table::Table(const Table &right) {
	this->i_rowSz = right.getRowSz();
	this->i_colSz = right.getColSz();

	// initialize this->Cp_columns
	this->Cp_columns = new RowAry *[this->i_rowSz];
	for(int i=0;i<this->i_rowSz;++i)
		this->Cp_columns[i] = new RowAry(this->i_colSz);

	// Copy data 
	for(int r=0;r<this->i_rowSz;++r)
		for(int c=0;c<this->i_colSz;++c)
			this->setData(r,c,right.getData(r,c));
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
Table::~Table() {
	for(int i=0;i<i_rowSz;++i) {
		delete Cp_columns[i];
	}
	delete [] Cp_columns;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : int value
// PARAMETER : int row, int col
// PURPOSE   : return the value of Table located at (row,col)
//////////////////////////////////////////////////////////////////////
int Table::getData(int r, int c) const {
	return Cp_columns[r]->getData(c);
}

//////////////////////////////////////////////////////////////////////
// RETURN    : int value
// PARAMETER : int row, int col, int value
// PURPOSE   : change the value of Table at (row,col) to value
//////////////////////////////////////////////////////////////////////
void Table::setData(int r, int c, int val) {
	Cp_columns[r]->setData(c,val);
}
