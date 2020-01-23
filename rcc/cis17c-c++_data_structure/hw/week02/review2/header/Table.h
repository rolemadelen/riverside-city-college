/*
    Author: Jiwon Yoo
    File: Table.h
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )
	
	Specification file for the Table class
*/

#ifndef TABLE_H
#define TABLE_H

// User Libraries
#include "AbsTab.h"

class Table : public AbsTab {
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
			{ return i_rowSz; }
		int getColSz() const
			{ return i_colSz; }
		int getData(int, int) const;
	
		// Mutator
		void setData(int,int,int);
};
#endif
