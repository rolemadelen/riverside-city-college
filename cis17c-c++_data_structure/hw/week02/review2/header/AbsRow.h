/*
    Author: Jiwon Yoo
    File: AbsRow.h
    February 26, 2016, ( BEGIN: 16:10 PM  
                         END  : 18:23 PM )
	
	Specification file for the Abstract Row Array class
*/

#ifndef ABSROW_H
#define ABSROW_H

// User define types
typedef unsigned int uint;

class AbsRow {
	protected:
		int i_size;
		int *ip_rowData;	
	public:
		// Pure virtual functions
		virtual int getSize() const = 0;
		virtual int getData(int) const = 0;
};

#endif
