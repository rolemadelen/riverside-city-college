/*
    Author: Jiwon Yoo
    File: RowAry.h
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )

	Specification file for the RowAry class
*/

#ifndef ROWARY_H
#define ROWARY_H

#include <iostream>
using namespace std;

// User Libraries
#include "AbsRow.h"

class RowAry : public AbsRow {
	private:
	public:
		// Constructor
		RowAry(uint);
		
		// Destrucor
		virtual ~RowAry();

		// Accessor
		int getSize() const 
			{ return i_size; }
		int getData(int i) const 
			{ return ((i>=0&&i<i_size) ? ip_rowData[i] : 0); }
		
		// Mutator
		void setData(int,int);
};

#endif
