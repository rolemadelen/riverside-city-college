/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Lab Week 7 - problem 3
*/

// Adjust problem 1 to include the default
// value of 1 for the exponential parameter

#include <iostream>
#include <cmath>
using namespace std;

// reads in a number and exponent
// and output the computed value.
// return type is void.
// paramter : selection of a program(1 or 2)
void numPwr(int num);

int main()
{
    int num;

    cout << "This program computes an exponent of a value.\n";
    cout << "Select : \n"
         << "1. input number & exponents.\n"
         << "2. input number only.\n\n> ";

    cin >> num;

    while(num != 1 && num != 2)
    {
        cout << "> ";
        cin >> num;
    }

    switch(num)
    {
    case 1: numPwr(1); break;
    case 2: numPwr(2);
    }

}

void numPwr(int num)
{
    int number;
    double expo;
    if(num == 1)
    {
        cout << "number : ";
        cin >> number;
        cout << "exponents : ";
        cin >> expo;

        cout << number << "^" << expo
             << " is " << pow(number,expo)
             << endl << endl;
    }
    else
    {
        expo = 1;
        cout << "number : ";
        cin >> number;

        cout << number << "^" << expo
             << " is " << pow(number,expo)
             << endl << endl;
    }
}
