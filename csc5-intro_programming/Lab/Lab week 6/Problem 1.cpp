/*
* Jiwon Yoo
* Professor Ung
* Lab 6 - problem 1
*/

// Write a function that takes a single value
// and returns three times the value;

#include <iostream>
using namespace std;

double multThree(double num)
{
	return num * num * num;
}

int main()
{
	double num;
	
	cout << "This program reads in a value\n"
		 << "and output three times the value.\n\n";
	
	cout << "Enter a value : ";
	cin >> num;
	
	cout << "The value was " << num << endl;
	cout << "Now the value is : " << multThree(num) << endl;
	
	return 0;
	
}