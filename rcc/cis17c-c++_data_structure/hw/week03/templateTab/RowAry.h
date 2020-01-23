/*
    Author: Jiwon Yoo
    File: RowAry.h
    March 2, 2016, ( BEGIN: 8:30 PM  
                         END  : 9:00 PM )

	Specification file for the RowAry class
*/

#ifndef ROWARY_H
#define ROWARY_H

#include <iostream>
#include <cstdlib>	// rand
using namespace std;

// User Libraries
#include "AbsRow.h"

template <class T>
class RowAry : public AbsRow<T> {
	private:
	public:
		// Constructor
		RowAry(uint);
		
		// Destrucor
		virtual ~RowAry();

		// Accessor
		virtual int getSize() const 
			{ return this->i_size; }
		virtual T getData(int i) const 
			{ return ((i>=0&&i<this->i_size) ?
					 this->Tp_rowData[i] : 0); }
		
		// Mutator
		void setData(int,T);
};

template <class T>
RowAry<T> :: RowAry(uint r) {
	this->i_size = r;
	this->Tp_rowData = new T[r];
	for(int i=0; i<this->i_size; ++i)
		this->Tp_rowData[i] = rand() % 90 + 10;
}

template <class T>
void RowAry<T> :: setData(int r, T val) {
	this->Tp_rowData[r] = val;
}

template <class T>
RowAry<T> :: ~RowAry() {
	delete [] this->Tp_rowData;
}
#endif
