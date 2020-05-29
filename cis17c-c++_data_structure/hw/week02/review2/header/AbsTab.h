/*
    Author: Jiwon Yoo
    File: main.cpp
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )

	Specification file for the Abstract Table Class
*/

#ifndef ABSTAB_H
#define ABSTAB_H

// User Libraries
#include "RowAry.h"

class AbsTab {
	protected:
		int i_rowSz;
		int i_colSz;
		RowAry **Cp_columns;
	public:
		// Pure virtual functions
		virtual int getRowSz() const = 0;
		virtual int getColSz() const = 0;
		virtual int getData(int,int) const = 0;
};

#endif
