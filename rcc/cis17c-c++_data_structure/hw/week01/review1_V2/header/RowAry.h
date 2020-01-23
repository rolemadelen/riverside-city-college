/*
    CIS 17C C++ - Homework: Review 1 
    By  : Jiwon Yoo
    Date: February 22, 2016

	Specification file for the RowAry class
*/


#ifndef ROWARY_H
#define ROWARY_H

class RowAry {
	private:
		int i_size;
		int *ip_rowData;
	public:
		// Construtor
		RowAry(int);
		// Destructor
		~RowAry();
		// Member Functions
		int getSize(void) { return i_size; }
		int getData(int i) { return ip_rowData[i]; }	
		void fillAry(void);
};

#endif
