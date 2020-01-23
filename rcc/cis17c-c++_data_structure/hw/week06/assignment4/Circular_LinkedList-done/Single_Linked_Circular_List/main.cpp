/*
	Author: Jiwon Yoo
	Date: March 30, 2016
*/

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "CLnkdLst.h"

int main(int argc, char **argv) {
	const int SIZE = 10;
	int n = SIZE;
	CLnkdLst lst(n--);
	
	while(n>0) lst.push_back(n--);
	while(n++<SIZE) cout << lst.pop_back() << ' ';
	cout << endl;

	return 0;
}
