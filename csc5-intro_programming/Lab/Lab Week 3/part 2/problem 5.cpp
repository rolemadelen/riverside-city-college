/*
* Jiwon Yoo
* Sept 13, 2013.
* CSC5 - C++ Programming
*Lab Week 3 Part 2 #3
*/


// write a program that will let the user enter a grade, 
// and the program will output what number they should expect with that grade. 
// e.g. If I were to enter C-, the computer will tell me ¡°70-73¡±. Use the 
// following list as a grading scale. Assume that the user will only 
// enter numbers the grades ranging from B- to A+.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// declare string variable for + and - symbol
	string grade;
	
	cout << setw(23) << "Grading Scale" << endl;
	cout << setfill('-') << setw(40) << "" << endl << setfill(' ');
	cout << setw(20) << " A+ A  A-" << "	100 - 90" <<endl
		<< setw(20) << " B+ B  B-" << "	89 - 80" << endl
		<< setw(20) << " C+ C  C-" << "	79 - 70 " << endl
		<< setw(20) << "     D+ D  D-" << "	69 - 60 "<< endl
		<< setw(13) << " F" << setw(18) << "59 - 0 " << endl << endl;

	cout << "To quit press 'ctrl + c'" << endl;
	while(true)
	{
		cout << "Enter a letter grade.\n> ";
		cin >> grade;
	
		if(grade == "a+" || grade == "A+")
		{
			cout << "100+" << endl;
		}
		else if(grade == "a" || grade == "A")
		{
			cout << "93 - 100" << endl;
		}
		else if(grade == "a-" || grade == "A-")
		{
			cout << "90 - 92.9" << endl;
		}
		else if(grade == "b+" || grade == "B+")
		{
			cout << "87 - 89.9" << endl;
		}
		else if(grade == "b" || grade == "B")
		{
			cout << "83 - 86.9" << endl;
		}
		else if(grade == "b-" || grade == "B-")
		{
			cout << "80 - 82.9" << endl;
		}
		else if(grade == "c+" || grade == "C+")
		{
			cout << "77 - 79.9" << endl;
		}
		else if(grade == "c" || grade == "c")
		{
			cout << "73 - 76.9" << endl;
		}
		else if(grade == "c-" || grade == "C-")
		{
			cout << "70 - 72.9" << endl;
		}
		else if(grade == "d+" || grade == "D+")
		{
			cout << "67 - 69.9" << endl;
		}
		else if(grade == "d" || grade == "D")
		{
			cout << "63 - 66.9" << endl;
		}
		else if(grade == "d-" || grade == "D-")
		{
			cout << "60 - 62.9" << endl;
		}
		else if(grade == "f" || grade == "F")
		{
			cout << "0 - 59.9" << endl;
		}
		cout << endl;
	}
	return 0;
}



