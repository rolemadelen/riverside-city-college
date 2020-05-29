/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Lab Week 7 - problem 1
*/

// Write a power function that takes a number
// to a specific power. The function should have
// two parameters, an int and a double. The
// function should return the comptued value;

#include <iostream>
#include <cmath>
using namespace std;

// reads in a number and exponent
// and output the computed value.
double numPwr(double num, int exp);

int main()
{
	int num, exp;
	
	cout << "Enter a number : ";
	cin >> num;
	cout << "Enter the exponent of a number : ";
	cin >> exp;
	
	cout << num << "^" << exp << " is "
		 << numPwr(num,exp) << endl;
	return 0;
}

double numPwr(double num, int exp)
{
	double result = pow(num,exp);
	return result;
}