/*
    Author: Jiwon Yoo
    File: Table.h
    March 2, 2016, ( BEGIN: 8:30 PM  
                         END  : 9:00 PM )
	
	Specification file for the Table class
*/

#ifndef TABLE_H
#define TABLE_H

// User Libraries
#include "AbsTab.h"

template <class T>
class Table : public AbsTab<T> {
	private:
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
};
#endif

template <class T>
Table<T>::Table(uint r, uint c) {
	this->i_rowSz = r;
	this->i_colSz = c;

	this->Cp_columns = new RowAry<T>*[r];
	for(int i=0;i<r;++i)
		*(this->Cp_columns+i) = new RowAry<T>(c);
}

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

template <class T>
Table<T> :: ~Table() {
	for(int i=0;i<this->i_rowSz;++i)
		delete this->Cp_columns[i];
	delete [] this->Cp_columns;  
}

template <class T>
T Table<T> :: getData(int r, int c) const {
	return this->Cp_columns[r]->getData(c);
}

template <class T>
void Table<T> :: setData(int r,int c,T val) {
	this->Cp_columns[r]->setData(c,val);
}
