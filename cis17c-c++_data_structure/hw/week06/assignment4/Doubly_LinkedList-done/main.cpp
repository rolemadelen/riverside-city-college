/*
	Author: Jiwon Yoo
	Date: March 29, 2016
*/

#include <iostream>
using namespace std;

#include "DLnkdLst.h"

int main( int argc, char **argv ) {
	const int SIZE = 10;
	int n = SIZE;
	DLnkdLst list(n--);

	while(n>5) list.push_back(n--);
	while(n>0) list.push_front(n--);
	//while(n>0) list.push_back(n--);

	while(n++<SIZE) cout << list.pop_front() << ' ';
//	while(n++<SIZE) cout << list.pop_back() << ' ';
	cout << endl;
	return 0;
}
