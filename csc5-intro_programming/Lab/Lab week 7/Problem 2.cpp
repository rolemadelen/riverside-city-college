/*
* Jiwon Yoo
* Professor Ung
* CSC5 - Lab 7 problem 2
*/

// Create an overloaded function of Problem 1,
// where the data type of the exponent can be an
// integer instead of a double

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//this function use pow() function to
//compute value of number^exponents.
//parameters : integer base, and double type
//exponents.
//return type is double.
double numPow(int num, double expo);

//this function use loop to compute value
//of number^exponents.
//parameters : integer base, and double type
//exponents.
//return type is double.
double numPow(int num, int expo);

int main()
{
	cout << numPow(2,16.0) << endl;
	return 0;	
}

double numPow(int num, double expo)
{
	return pow(num,expo);
}
double numPow(int num, int expo)
{
	int base = num;
	for(int i = 1; i < expo ; i ++)
	{
		base *= num;
	}
	return base;
	cout << "expo is integer\n";
	//return pow(num,expo);
}