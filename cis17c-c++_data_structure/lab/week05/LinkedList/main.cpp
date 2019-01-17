/*
	Author: Jiwon Yoo
	Date: March 16, 2016
*/

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "LnkdLst.h"

// Execution begins here 
int main(int argc, char **argv) {
	// Declare Variables
	const int SIZE = 10;
	int n = SIZE;
	LnkdLst list(n--);
	
	// Push data into the Linked List
	while( n>0 ) list.push( n-- );

	while(n++<SIZE+10) {
		int data = list.pop();
		cout << data << endl;
	}
	return 0;
}
