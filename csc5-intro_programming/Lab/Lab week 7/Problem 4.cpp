//Jiwon Yoo
//Professor Ung
//CSC5 - C++ Programming
//Lab Week7 - problem 4

/*
Write a function that determines if a year is a leap year.
Invoke the function created, and allow the user to enter
as many years as they wish.
*/

#include <iostream>

using namespace std;

//this function checks whether an year is leap year or not.
//parameter is integer value 'year'.
//return type is boolean.
bool checkLeap(int year);
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

        if(checkLeap(year))
             cout << "year " << year << " is a leap year." << endl;
		else
            cout << "year " << year << " is not a leap year.\n";
    }while(year > 0);
    return 0;
}

bool checkLeap(int year)
{
	bool check = (year % 4 == 0);
    //if year is divisible by 4 or 400 than its leap year

    return((year % 100 == 0) && (year % 400 == 0)
		    ||(check==true && year % 100 != 0));

}