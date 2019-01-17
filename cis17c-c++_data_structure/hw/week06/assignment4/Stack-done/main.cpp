/* 
 	Author: Jiwon Yoo
	Stack Implementation 
*/

// System Libraries
#include <iostream>
using namespace std;

// System Libraries
#include "Stack.h"

// Execution begins here
int main(int argc, char **argv) {
	const int SIZE = 10;
	int n = SIZE;
	Stack stk(n--);

	while(n>0) stk.push_back(n--);
	while(n++<SIZE+5) cout << stk.pop_back() << ' ';
	cout << endl;

	return 0;
}
