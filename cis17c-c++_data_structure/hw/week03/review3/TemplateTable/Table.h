/*
    Author: Jiwon Yoo
    File: Table.h
    March 6, 2016, ( BEGIN: 12:22 PM  
                     END :  12:44 PM)
	
	Specification file for the Table class
*/

#ifndef TABLE_H
#define TABLE_H

// User Libraries
#include "RowAry.h"

template <class T>
class Table {
	protected:
		int i_rowSz;
		int i_colSz;
		RowAry<T> **Cp_columns;
	public:
		// Constructor
		Table(uint, uint);
		
		// Copy Constructor
		Table(const Table &);
	
		// Destructor
		virtual ~Table();
		
		// Accessor
		int getRowSz() const 
			{ return this->i_rowSz; }
		int getColSz() const
			{ return this->i_colSz; }
		T getData(int, int) const;
	
		// Mutator
		void setData(int,int,T);

		//Operator  Overloading functions
		Table<T> operator+(const Table<T> &);
};
#endif

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
template <class T>
Table<T>::Table(uint r, uint c) {
	this->i_rowSz = r;
	this->i_colSz = c;

	this->Cp_columns = new RowAry<T>*[r];
	for(int i=0;i<r;++i)
		*(this->Cp_columns+i) = new RowAry<T>(c);
}

//////////////////////////////////////////////////////////////////////
//	Copy Constructor
//////////////////////////////////////////////////////////////////////
template <class T>
Table<T>::Table(const Table &right) {
	this->i_rowSz = right.getRowSz();
	this->i_colSz = right.getColSz();

	this->Cp_columns = new RowAry<T>*[this->i_rowSz];
	for(int i=0;i<this->i_rowSz;++i)
		*(this->Cp_columns+i) = new RowAry<T>(this->i_colSz);

	for(int i=0;i<this->i_rowSz;++i) 
		for(int j=0;j<this->i_colSz;++j) 
			setData(i,j,right.getData(i,j));
}

//////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////
template <class T>
Table<T> :: ~Table() {
	for(int i=0;i<this->i_rowSz;++i)
		delete this->Cp_columns[i];
	delete [] this->Cp_columns;  
}

//////////////////////////////////////////////////////////////////////
// RETURN    : T
// PARAMETER : int row, int col
// PURPOSE   : return the data at [row,col]
//////////////////////////////////////////////////////////////////////
template <class T>
T Table<T> :: getData(int r, int c) const {
	return this->Cp_columns[r]->getData(c);
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : int row, int col, T value
// PURPOSE   : Set [row,col] data to 'value'
//////////////////////////////////////////////////////////////////////
template <class T>
void Table<T> :: setData(int r,int c,T val) {
	this->Cp_columns[r]->setData(c,val);
}

//////////////////////////////////////////////////////////////////////
// RETURN    : Table<T>
// PARAMETER : const Table<T>
// PURPOSE   : Add two tables rows & cols data and return the Table
//////////////////////////////////////////////////////////////////////
template <class T>
Table<T> Table<T> :: operator+(const Table<T> &right) {
	Table<T> temp(i_rowSz, i_colSz);
	for(int i=0;i<i_rowSz;++i) {
		for(int j=0;j<i_colSz;++j) {
			temp.setData(i,j, this->getData(i,j) + right.getData(i,j));
		}
	}
	return temp;
}
