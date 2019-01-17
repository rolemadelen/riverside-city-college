//Jiwon Yoo
//Professor Ung
//CSC5 - C++ Programming
//Lab Week4 Problem 4

/*
A year with 366 days is called a leap year. A year is a 
leap year if it is divisible by 4 (for example, 1980), 
except that it is not a leap year if it is divisible 
by 100 (for example, 1900). However, a leap year is
divisible by 400, (for example, 2000). Write a program 
that asks the user for a year and computes whether 
that year is a leap year. 
*/

#include <iostream>

using namespace std;

int main()
{
        // declare year, leapyr_test
        int year;
        
        cout << "This program computes whether the year is a leap year." << endl;
        cout << "enter negative number to quit." << endl << endl;
        
        do
        {
	       	 // get year
	        cout << "Enter a year : ";
	        cin >> year;

			bool check = year % 4 == 0;

	        //if year is divisible by 4 or 400 than its leap year
			if((year % 100 == 0) && (year % 400 == 0) ||
				(check==true && year % 100 != 0))
	        {
				cout << "year " << year << " is a leap year." << endl;
	        }
			else
	        {
	       		cout << "year " << year << " is not a leap year.\n";
	        }
				
        
        }while(year > 0);
        return 0;
}
