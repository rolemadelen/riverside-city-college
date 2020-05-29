/*
 *Jiwon Yoo
 *Sept 13, 2013.
 * CSC5 - C++ programming
 * Lab3 Worksheet part2
 * problem 1  - b
 */

// create a program that will determine the grade of a given
// value. The user will enter a number between 1 and 100,
// and the console whould spit out the grade. e.g. If I were
// to enter 89, the console would tell me 'B'. The value you
// get from the user should be of type int.

#include <iostream>
using namespace std;

int main()
{
	//declare score;
	int score;

	//get score
	cout << "Enter a number between 1 and 100.\n> ";
	cin >> score;

	while(score > 100 || score < 0)
	{
		cout << "Invalid value was inputted.\a\n";
		cout << "Enter a number BETWEEN 1 and 100 :D.\n> ";
		cin >> score;
	}
	score /= 10;

	cout << "Your grade is : ";
	switch(score)
	{
	case 10:
	case 9:
		cout << " A" << endl;
		break;
	case 8:
		cout << " B" << endl;
		break;
	case 7:
		cout << " C"<< endl;
		break;
	case 6:
		cout << " D" << endl;
		break;
	default:
		cout << " F" << endl;
	}

	return 0;

}
