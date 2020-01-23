/*
    Author: Jiwon Yoo
    File: main.cpp
    March 2, 2016, ( BEGIN: 8:30 PM  
                         END  : 9:00 PM )

	Specification file for the Abstract Table Class
*/

#ifndef ABSTAB_H
#define ABSTAB_H

// User Libraries
#include "RowAry.h"

template <class T>
class AbsTab {
	protected:
		int i_rowSz;
		int i_colSz;
		RowAry<T> **Cp_columns;
	public:
		// Pure virtual functions
		virtual int getRowSz() const = 0;
		virtual int getColSz() const = 0;
		virtual T getData(int,int) const = 0;
};

#endif
