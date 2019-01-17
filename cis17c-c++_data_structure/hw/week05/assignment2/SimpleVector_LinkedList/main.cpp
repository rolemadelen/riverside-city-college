/*
    Author: Jiwon Yoo
    File: main.cpp
    March 6, 2016, ( BEGIN: 08:28 AM  
                     END :  10:28 AM)
*/

// System Libraries
#include <iostream>
using namespace std;

// User Libraries
#include "SimpleVector.h"

// Execution begins here
int main(int argc, char **argv) {
	const int SIZE = 10;
	int n = SIZE;
	SimpleVector<int> obj(n--);
	while( n>0 ) obj.push_back(n--);
	//while( n++<10 ) cout << obj.pop_back() << endl;
	
	for(int i=SIZE-1;i>=0;--i)
		cout << obj.getElAt(i)<< endl;
	cout << obj[3] + obj[4] << endl;

	// copy LinkedList obj to obj2
	SimpleVector<int> obj2 = obj;
	for(int i=SIZE-1;i>=0;--i)
		cout << obj2[i] << endl;
	cout << obj2[3] + obj2[4] << endl;
	
	obj[5] = 12;

	for(int i=SIZE-1;i>=0;--i)
		cout << obj.getElAt(i)<< endl;
	cout << obj[3] + obj[4] << endl;

	for(int i=SIZE-1;i>=0;--i)
		cout << obj2.getElAt(i)<< endl;
	cout << obj2[3] + obj2[4] << endl;


	SimpleVector<int> obj3;
	SimpleVector<int> obj4 = obj3;
	obj4.push_back(5);
	cout << "HERE " << obj4[0] << endl;
	return 0;
}
