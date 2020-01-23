/*
    Author: Jiwon Yoo
    File: RowAry.h
 	March 6, 2016, ( BEGIN: 12:22 PM 
                     END  : 12:44 PM )

	Specification file for the RowAry class
*/

#ifndef ROWARY_H
#define ROWARY_H

#include <iostream>
#include <cstdlib>	// rand
using namespace std;

// User defined types
typedef unsigned int uint;

template <class T>
class RowAry {
	protected:
		int i_size;
		T *Tp_rowData;
	public:
		// Constructor
		RowAry(uint);
		
		// Destrucor
		virtual ~RowAry();

		// Accessor
		int getSize() const 
			{ return this->i_size; }
		T getData(int i) const 
			{ return ((i>=0&&i<this->i_size) ?
					 this->Tp_rowData[i] : 0); }
		
		// Mutator
		void setData(int,T);
};

//////////////////////////////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////////////////////////////
template <class T>
RowAry<T> :: RowAry(uint r) {
	this->i_size = r;
	this->Tp_rowData = new T[r];
	for(int i=0; i<this->i_size; ++i)
		this->Tp_rowData[i] = rand() % 90 + 10;
}

//////////////////////////////////////////////////////////////////////
//	Destructor
//////////////////////////////////////////////////////////////////////
template <class T>
RowAry<T> :: ~RowAry() {
	delete [] this->Tp_rowData;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : int row, T value
// PURPOSE   : return the data of RowAry at [row]
//////////////////////////////////////////////////////////////////////
template <class T>
void RowAry<T> :: setData(int r, T val) {
	this->Tp_rowData[r] = val;
}

#endif
