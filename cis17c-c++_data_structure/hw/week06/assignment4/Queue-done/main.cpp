/*
	Author: Jiwon Yoo
	Data: March 29, 2016
*/
#include <iostream>
using namespace std;

#include "Queue.h"

int main( int argc, char **argv ) {
	const int SIZE = 10;
	int n = SIZE;
	Queue q(n--);
	
	while(n>0) q.push_front(n--);
	while(n++<SIZE) cout << q.pop_front() << ' ';
	cout << endl;

	return 0;
}
