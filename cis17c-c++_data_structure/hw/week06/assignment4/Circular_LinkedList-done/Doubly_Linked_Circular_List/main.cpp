/*
	Author: Jiwon Yoo
	Date: March 29, 2016
*/

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "CLnkdLst.h"

// Execution begins here
int main( int argc, char **argv ) {
	const int SIZE = 10;
	int n = SIZE;
	CLnkdLst list(n--);

	while( n>5 ) list.push_back(n--);
	while( n>0 ) list.push_front(n--);

	while( n++<SIZE ) cout << list.pop_back() << ' ';
	//while( n++<SIZE ) cout << list.pop_front() << ' ';
	cout << endl;
	return 0;
}
