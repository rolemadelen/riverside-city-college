/*
	Author: Jiwon Yoo
	Date: March 30, 2016
*/

// System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// User Libraries
#include "SLnkdLst.h"

int main( int argc, char **argv ) {
	unsigned seed = time(0);
	srand( seed );
	SLnkdLst lst(rand()%100);
	for(int i=0;i<100;++i) {
		//lst.print();
		lst.push(rand()%100);
	}
	lst.print();
	return 0; 
}
