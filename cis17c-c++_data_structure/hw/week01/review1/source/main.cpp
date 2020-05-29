/* Implementation file for the RowAry class */

// System Libraries
#include <iostream>
#include <cstdlib>	// srand
#include <ctime>	// time
using namespace std;

// User Libraries
#include "../header/Table.h"

// Execution begins
int main() {
	// Initialize the random seed
	unsigned seed;
	srand(seed);

	// Declare variables
	int i_row, i_col, n;
	i_row = i_col = n = 0;
	
	// Prompt the user for the size of row
	cout << "\n========================\n";
	cout << "      RowAry Class\n";
	cout << "========================\n";
	cout << "Row Size: ";
	cin >> i_row;
	cout << "How many data per line: ";
	cin >> n;
	
	// create a RowAry class, fill, and display the array
	RowAry C_row(i_row);
	C_row.fillAry();
	C_row.prntAry(n);

	// Prompt the user for the size of row and col
	cout << "\n========================\n";
	cout << "      Table Class\n";
	cout << "========================\n";
	cout << "Row size: ";
	cin >> i_row;
	cout << "Col size: ";
	cin >> i_col;

	// create a Table class, fill, and display the array
	Table C_tbl(i_row, i_col);
	C_tbl.fillAry();
	C_tbl.prntAry();
	return 0;	
}
