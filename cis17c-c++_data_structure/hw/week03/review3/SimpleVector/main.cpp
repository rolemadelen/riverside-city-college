/*
    Author: Jiwon Yoo
    File: main.cpp
    March 6, 2016, ( BEGIN: 13:02 PM  
                     END :  13:41 PM)
*/

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "SimpleVector.h"

// Function Prototypes
template <class T>
void print(T &, int);

// Execution begins here
int main(int argc, char **argv) {
	int const SIZE = 5;
	SimpleVector<int> obj(SIZE);
	
	// Initialize the array
	for(int i=0;i<obj.size();++i) {
		obj[i] = (1+i)*2;
	}

	cout << endl << "SimpleVector Object w/ size 5";
	print(obj, 5);
	cout << endl;

	cout << "Push_back data";
	obj.push_back(9);
	obj.push_back(2);
	obj.push_back(3);
	obj.push_back(12);
	obj.push_back(1);
	obj.push_back(100);
	
	// Print data
	print(obj,5);

	// Remove and print data
	cout << "Pop_back: Removed 1 element";
	obj.pop_off();
	print(obj,5);

	// Remove and print data
	cout << "Pop_back: Removed 3 elements";
	for(int i=0;i<3;++i)
		obj.pop_off();
	print(obj,5);

	// Remove and print data
	cout << "Pop_back 2 elements";
	for(int i=0;i<2;++i)
		obj.pop_off();
	print(obj,5);

	// Test Default Constructor of size 0
	SimpleVector<int> obj2;
	cout<< "new SimpleVector created w/ size 0";
	print(obj2,5);

	cout << "Push_back a value";
	obj2.push_back(5);
	print(obj2,5);
	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : T obj, int num
// PURPOSE   : display all elements in the object;
//////////////////////////////////////////////////////////////////////
template <class T>
void print(T &obj, int perLine) {
	cout << endl;
	for(int i=0;i<obj.size();++i) {
		cout << obj[i] << ' ';
		if((i+1)%perLine==0) cout << endl;
	}
	cout << endl;
}
