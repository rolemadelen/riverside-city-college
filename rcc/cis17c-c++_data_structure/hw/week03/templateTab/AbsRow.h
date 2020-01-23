/*
    Author: Jiwon Yoo
    File: AbsRow.h
    March 2, 2016, ( BEGIN: 8:30 PM  
                         END  : 9:00 PM )
	
	Specification file for the Abstract Row Array class
*/

#ifndef ABSROW_H
#define ABSROW_H

// User define types
typedef unsigned int uint;

template <class T>
class AbsRow {
	protected:
		int i_size;
		T *Tp_rowData;	
	public:
		// Pure virtual functions
		virtual int getSize() const = 0;
		virtual T getData(int) const = 0;
};

#endif
