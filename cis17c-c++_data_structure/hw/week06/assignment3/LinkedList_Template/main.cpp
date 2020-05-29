/*
    Author: Jiwon Yoo
    File: main.cpp
    March 6, 2016, ( BEGIN: 11:05 AM  
                     END :  11:26 AM)
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
	cout << "INTEGER" << endl;
	SimpleVector<int> obj(n--);
	while( n>0 ) obj.push_back(n--);
	while( n++<10 ) cout << obj.pop_back() << ' ';
	cout << endl;
	
	cout << "\nFLOAT" << endl;
	n = SIZE;
	SimpleVector<float> obj2((n--)/7.0f);
	while( n>0 ) obj2.push_back((n--)/7.0f);
	while( n++<10 ) cout << obj2.pop_back() << ' ';
	cout << endl;

	cout << "\nCHARACTER" << endl;
	n = SIZE;
	SimpleVector<char> obj3((--n)+48);
	while( n>0 ) obj3.push_back((--n)+48);
	while( n++<10 ) cout << obj3.pop_back() << ' ';
	cout << endl;

	cout << "\nBOOLEAN" << endl;
	n = SIZE;
	SimpleVector<bool> obj4((n--)%2);
	while( n>0 ) obj4.push_back((n--)%2);
	while( n++<10 ) cout << obj4.pop_back() << ' ';
	cout << endl; 
	return 0;
}
