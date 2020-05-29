/*
    Author: Jiwon Yoo
    File: PlusTab.h
 	March 2, 2016, ( BEGIN: 8:30 PM  
                         END  : 9:00 PM )

    Specification file for the PlusTab class
*/

#ifndef PLUSTAB_H
#define PLUSTAB_H

// User Libraries
#include "Table.h"

template <class T>
class PlusTab : public Table<T> {
	private:
	public:
		// Constructor
		PlusTab (uint r, uint c) : Table<T>(r, c) {;}

		// Overloaded operator functions
		PlusTab operator+(const PlusTab &);
};

template <class T>
PlusTab<T> PlusTab<T>::operator+(const PlusTab &right) {
    PlusTab<T> temp(this->i_rowSz, this->i_colSz);
    for(int r=0;r<this->i_rowSz;++r)
        for(int c=0;c<this->i_colSz;++c) 
            temp.setData(r,c, this->getData(r,c)+right.getData(r,c));
    return temp;
}
#endif
