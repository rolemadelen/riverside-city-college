/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 2 - problem 4
*/

// using function used in problem 3.
// see how much easier it is to just use a function,
// rather than using the same algorithm over and over
// as in problem 2

#include <iostream>
using namespace std;

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
		if(number > hold)
		{
			hold = number;
		}
	}
	
	cout << "The largest number is : " << hold << endl;
	
	return 0;
}
