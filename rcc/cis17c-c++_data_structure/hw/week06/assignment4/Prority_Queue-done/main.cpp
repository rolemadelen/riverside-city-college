/*
	Author: Jiwon Yoo
	Data: April 2, 2016
*/

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "PQueue.h"

// Execution begins here
int main( int argc, char **argv ) {
	const int SIZE = 10;
	int n = SIZE;
	PQueue q(n--);
	
	while(n>0) q.push_front(n--);

	for(int i=0;i<=SIZE;++i) {
		if( q.find(i) ) {
			cout << i << " is Found" << endl;
		} else {
			cout << i << " is Not-Found" << endl;
		}
		q.print();
		cout << endl;
	}
	return 0;
}
