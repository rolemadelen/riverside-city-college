/*
	Author: Jiwon Yoo
	File: main.cpp
	February 26, 2016, ( BEGIN: 16:10 PM  
						 END  : 18:23 PM )
	Purpose: Dynamic Object Arrays
*/

// System Libraries
#include <iostream>
#include <cstdlib>	// random
#include <ctime>	// time
#include <iomanip>	// setw
using namespace std;

// User Libraries
#include "../header/PlusTab.h"

// Function Prototypes
void prntTab(const Table &);

// Execution begins here
int main(int argc, char **argv) {
	// Initialize the random seed
	srand(static_cast<uint>(time(0)));
	
	// Declare variables
	int i_rows, i_cols;
	i_rows = i_cols = 0;
	
	// Prompt the user for Rows and Cols
	cout << "Enter i_rows and i_cols: ";
	cin >> i_rows >> i_cols;
	
	// Test out the Tables
	PlusTab C_tab1(i_rows, i_cols);
	PlusTab C_tab2(C_tab1);
	PlusTab C_tab3=C_tab1+C_tab2;
	
	// Print the Tables;
	cout << "Abstracted and Polymorpihc Print Table 1 size is [row,col] = ["
		 << i_rows << ',' << i_cols << "]";
	prntTab(C_tab1);
	cout << "Copy Constructed Table 2 size is [row,col] = [" 
		 << i_rows << ',' << i_cols << "]";
	prntTab(C_tab2);
	cout << "Operator Overloaded Table3 size is [row,col] = ["
		 << i_rows << ',' << i_cols << "]";
	prntTab(C_tab3);
	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : const Table object
// PURPOSE   : display Table
//////////////////////////////////////////////////////////////////////
void prntTab(const Table &a) {
	cout << endl;
	for(int r=0;r<a.getRowSz();++r) {
		for(int c=0;c<a.getColSz();++c) {
			cout << setw(4) << a.getData(r,c);
		}
		cout << endl;
	}
	cout << endl;
}
