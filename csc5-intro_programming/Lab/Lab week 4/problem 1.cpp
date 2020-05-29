/*
Jiwon Yoo
Professor Ung
CSC5 - C++ Programming
Week 4 Lab Part 1 - #1
*/

// Write a program that will let the user enter a grade, and the program
// will output what number they should expect with that grade. e.g. if I
// were to enter C-, the computer will tell me "1.7". Use the following 
// list as a grading scale. Assume that the user will only enter numbers 
// the grades ranging from B- to a+. You must use nested statements and 
// switch cases. You cannot use (if string == "A+") The + or - must be
// read separately from the letter.
// grading scale:
/*
	A+ = 4.0
	A = 4.0
	A- = 3.7
	B+ = 3.3
	B = 3.0
	B- = 2.7
*/

#include <iostream>

using namespace std;

int main()
{
	const double APLUS = 4.0, A = 4.0, AMINUS = 3.7;
	const double BPLUS = 3.3, B = 3.0, BMINUS = 2.7;
	
	while(true)
	{
		char grade, character;

		//get a grade from the user	
		cout << "Enter a grade between B- to A+ : ";
		cin.get(grade);
		cin.get(character);
	
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(1);

		//output a number that corresponds to the grade
		if((grade == 'a' || grade == 'A'))
		{
			switch(character)
			{
				case '+':
					cout << APLUS << endl;
					fflush(stdin);
					break;
				case '-':
					cout << AMINUS << endl;
					fflush(stdin);
					break;
				default:
					cout << A << endl;
			}

		}
		else if((grade == 'b' || grade == 'B'))
		{
			switch(character)
			{
				case '+':
					cout << BPLUS << endl;
					fflush(stdin);
					break;
				case '-':
					cout << BMINUS << endl;
					fflush(stdin);
					break;
				default:
					cout << B << endl;
			}

		}
		else
		{
			cout << "I said between B- to A+ !!\a\n";
			cout << "Try again.\n\n";
		}
	
	}
}
