/*
* Jiwon Yoo
* Student ID : 2485776
* October 11, 2013
* Homework : 6
* Problem : 1
* I certify this is my own work and code!
*/

// Write an overloaded function max that takes either
// two or three parameters of type double and returns
// the largest of them.

#include <iostream>
using namespace std;

// The function 'Max' is an overloading function.
// It compares two to three number
// and returns the largest value.
// Return type is double and takes in
// has two to three double type parameters.
double max(double num1, double num2);
double max(double num1, double num2, double double3);

int main()
{
	double x,y,z;
	cout << "Enter three random numbers.\n> ";
	cin >> x >> y >> z;
	
	cout << "X : " << x <<  "  Y : " << y 
		 << "  Z : " << z << endl << endl;
	cout << "Between X and Y : " << max(x,y) << " is larger.\n";
	cout << "Between X, Y, and Z : " << max(x,y,z) << " is larger.\n";
		 
	return 0;
}

double max(double num1, double num2)
{
	if(num1 > num2)
		return num1;
	else
		return num2;
}

double max(double num1, double num2, double num3)
{
	if(num1 >= num2 && num1 >= num3)
		return num1;
	else if(num2 >= num1 && num2 >= num3)
		return num2;
	else
		return num3;
}