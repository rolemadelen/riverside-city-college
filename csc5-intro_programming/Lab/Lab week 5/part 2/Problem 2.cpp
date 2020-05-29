/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 2 - problem 2
*/

// Write a simple program that compares the
// value of two numbers, and determines which
// one is the largest. Hardcode at least 10
// values to be compared amongst each other,
// and output to the user the values, and which
// one of those are the largest.

#include <iostream>
using namespace std;

int compare(int num1, int num2);
int main()
{
	int number;
	int hold = 0; // holds previous number and compare;
	
	cout << "This program compares and output\n"
		 << "the largest number.\n\n";
	
	cout << "Enter 10 numbers.\n1) ";
	cin >> number;
	hold = number;
	for(int i = 1; i < 10; i ++)
	{	
		cout << i+1 << ") ";
		cin >> number;
		hold = compare(number, hold);
	}
	
	cout << "The largest number is : " << hold << endl;
	
	return 0;
}

int compare(int num1, int num2)
{
	if(num1 > num2)
	{
		num2 = num1;
	}
	
	return num2;
}