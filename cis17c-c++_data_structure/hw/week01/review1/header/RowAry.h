/* Specification file for the RowAry class */
#ifndef ROWARY_H
#define ROWARY_H

class RowAry {
	private:
		int *ip_row;
		int i_rowSz;	// row sizz
		
	public:
		// Defalut Constructor
		RowAry() 
			{ip_row=0; i_rowSz=0; }

		// Constructor
		RowAry( int );
		
		// Destrucor
		~RowAry();
	
		// Mutator
		void setSize(int);

		// Accessor
		int getSize()
			{ return i_rowSz; }

		// Member functions
		void fillAry(void);
		void prntAry(void);
		void prntAry(int);
		void init(int);
};

#endif
