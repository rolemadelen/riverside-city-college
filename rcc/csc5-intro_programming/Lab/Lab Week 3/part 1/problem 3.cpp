/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 10, 2013.
* HW: Lab3 worksheet part 1
* Problem: 3
* I certify this is my own work and code.
*/

// using the code provided in problem 4, create a program
// to output the values of x and y to the console. You may
// select your own values.

#include <iostream>
using namespace std;

int main()
{
    int x = 4;
    int y = 0;
    
    cout << "Enter the value for x (1 ~ 10) : ";
    cin >> x;
    
    if(x == 4)
    {
        y = 4;
    }
    else if(x == 9)
    {
        y = 5;
    }
    else
    {
        y = 6;
    }
    
    cout << "X : " << x << endl;
    cout << "Y : " << y << endl;
    
    return 0;
}