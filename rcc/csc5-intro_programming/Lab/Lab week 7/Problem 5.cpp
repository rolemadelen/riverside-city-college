/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Lab Week 7 - problem 5
*/

// Write a function which finds the factorial of a number
// entered by the user. Check for all types of conditions.

#include <iostream>
using namespace std;

// this function computes the factorial of a number
// and outputs the decimal value to hundreth.
// return type is integer.
// reads in one integer number
long factorial(int num);

int main()
{

    int num = 0;
    cout << "factorial of n is : n * (n-1) * (n-2) * ...\n\n";
    cout << "Enter 0 or negative number to quit.\n";

    do
    {
    cout << "Enter n : ";
    cin >> num;

    cout << "factorial of " << num << " is "
         << factorial(num) << endl << endl;
    }while(num > 0);

    return 0;
}

long factorial(int num)
{
    if(num <= -1)
    {
        cout << "QUIT.\n";
        return 0;
    }
    while(num > 12)
    {
        cout << "input must beless than 13\n";
        cout << "Enter n : ";
        cin >> num;
    }

    int temp = num;

    for(int i = 1 ; i < temp; i ++)
    {
        num = num * i;
    }

    return num;
}
