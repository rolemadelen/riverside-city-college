/*
    Author: Jiwon Yoo
    File: PlusTab.cpp
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )

    Implementation file for the PlusTab class
*/

// User Libraries
#include "../header/PlusTab.h"

//////////////////////////////////////////////////////////////////////
// Overoladed operator+ function
// PURPOSE : Sum two tables' value and return the object
//////////////////////////////////////////////////////////////////////
PlusTab PlusTab::operator+(const PlusTab &right) {
	PlusTab temp(this->i_rowSz, this->i_colSz);
	for(int r=0;r<this->i_rowSz;++r)
		for(int c=0;c<this->i_colSz;++c) 
			temp.setData(r,c, this->getData(r,c)+right.getData(r,c));
	return temp;
}
