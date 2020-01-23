/*
    Author: Jiwon Yoo
    File: PlusTab.h
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )

    Specification file for the PlusTab class
*/

#ifndef PLUSTAB_H
#define PLUSTAB_H

// User Libraries
#include "Table.h"

class PlusTab : public Table {
	private:
	public:
		// Constructor
		PlusTab (unsigned int r, unsigned int c) : Table(r, c) {;}

		// Overloaded operator functions
		PlusTab operator+(const PlusTab &);
};
#endif
