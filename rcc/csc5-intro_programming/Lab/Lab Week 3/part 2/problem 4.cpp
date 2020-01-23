/*
* Jiwon Yoo
* Sept 13, 2013.
* CSC5 - C++ Programming
*Lab Week 3 Part 2 #3
*/

// Using the for loop, create a program that will take in 10 points from the user,
// outputting all 10 points on the screen after they have all been received.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string value;
	string total = " ";

	cout << "Enter 10 numbers.\n";

	for(int i = 1; i <= 10; i ++)
	{
		cin >> value;
		total = total + value + " ";
	}
	cout << total << endl;

	return 0;
}