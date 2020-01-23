/*
* Jiwon Yoo
* Student ID :  2485776
* Sept 20, 2013.
* HW 3 Problem 1
* I certify this is my own work and code
*/

// Write a program prompts a user for a telephone number that
// requires only one dash in between and then outputs the 
// telephone without the dash.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string telephone;
	int find;

	// get telephone number
	cout << "Enter a telehpone number with "
		 << "only one dash in between.\n> ";
	cin >> telephone;

	// find hyphen
	// output phone-number
	find = telephone.find("-");
	while(find < 0)
	{
		cout << "Your phone number ...seems wrong?"
			 << " Where is 'dash'?\n";
		cout << "Enter again.\n> ";
		cin >> telephone;
		find = telephone.find("-");
	}
	
	cout << telephone.substr(0,find)
		<< telephone.substr(find+1,15) << endl;

	return 0;
}