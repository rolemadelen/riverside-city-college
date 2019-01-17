/*
	CIS 17C C++ - Homework: Review 1 
	By  : Jiwon Yoo
	Date: February 22, 2016
*/

// System Libraries
#include <cstdlib>	// srand
#include <ctime>	// time
#include <iostream>
using namespace std;

// User Libraries
#include "../header/Table.h"

// Function Prototypes
void prntRow(RowAry *, int);
void prntTbl(Table *);

// Execution begins here!
int main(int argc, char **argv) {
	// Initialize the random seed
	unsigned seed = time(0);
	srand(seed);

	// Declare Variables
	int rows=15, cols=8, perLine=5;

	// Test out the RowAry
	RowAry row(rows);

	// Print the RowAry
	cout << "The Row Array size = " << row.getSize()
		 << " printed " << perLine << " per Line";
	prntRow(&row, perLine);
	
	// Test out the Table
	Table tbl(rows,cols);
	
	//Print the table
	cout << "The table size is [row, col] = ["<<rows<<","<<cols<<"]";
	prntTbl(&tbl);

	return 0;
}

////11111112222222233333334444444455555556666666667777777888888889999
//// RETURN    : void
//// PARAMETER : RowAry obj, int perLine
//// PURPOSE   : Display every elements in RowAry object row 
/////////////////////////////////////////////////////////////////////
void prntRow(RowAry *a, int perLine) {
	cout << endl;
	for(int i=0; i<a->getSize(); i++)  {
		cout << a->getData(i)<<" ";
		if(i%perLine==(perLine-1)) cout << endl;
	}
	cout << endl;
}

////11111112222222233333334444444455555556666666667777777888888889999
//// RETURN    : void
//// PARAMETER : printTbl obj
//// PURPOSE   : Display rows and columns in Table object
/////////////////////////////////////////////////////////////////////
void prntTbl(Table *a) {
	cout << endl;
	for(int row=0; row<a->getSzRow(); row++){
		for(int col=0; col<a->getSzCol(); col++)
			cout << a->getData(row,col)<<" ";
		cout << endl;
	}
	cout << endl;
}
