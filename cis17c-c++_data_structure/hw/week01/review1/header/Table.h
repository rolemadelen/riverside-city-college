/* Specification file for the Table class */

#ifndef TABLE_H
#define TABLE_H

// User Libraries
#include "RowAry.h"

class Table{
	private:
		RowAry *Cp_row;
		int i_rowSz;	// row size
		int i_colSz;	// column size
	public:
		// Constructor
		Table(int,int);

		// Destructor
		~Table();

		// Accessor
		int getRowSz()
			{ return i_rowSz; }
		int getColSz() 
			{ return i_colSz; }

		// Member Functions
		void fillAry(void);
		void prntAry(void);
};
#endif
