/*
* Jiwon Yoo
* Professor Ung
* Lab 6 - problem 2
*/

// Write a function that takes a single value
// and returns square of the value;

#include <iostream>
using namespace std;

double square(double num)
{
	return num * num;
}

int main()
{
	double num;
	
	cout << "This program returns the square of a value.\n";
	cout << "Enter a number : ";
	cin >> num;
	
	cout << "The sqaure of " << num
		 << " is " << square(num) << endl;
		 
	return 0;
}