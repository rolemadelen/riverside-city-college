/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 10, 2013.
* HW: Lab3 worksheet part 1
* Problem: 2
* I certify this is my own work and code.
*/

// write a program that receives two numbers less than 1000 from 
// the user and switches the value of those two nubmers. Then, output
// the values in the following foramt.

//X = 6   Y = 19
//--------------------------------------------------------
//Y = 19  X = 6

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     // declare two integer type variable
     // declare place holder variable
    int x = 0, y = 0;
    int temp = 0;
    
    cout << "Enter two numbers less than 1000." << endl;
    
     // get number 1
    cout << "Enter the first number : ";
    cin >> x;
    
     // get number 2
    cout << "Enter the second number : ";
    cin >> y;
    cout << endl;
    
    if(x > 1000 || y > 1000)
    {
        cout << "Inputted wrong value for either 'x' or 'y'.\n";
        cout << "Program terminates.\n";
        return 0;
    }
    // outputs the value that is swapped and aligned.
    cout << "X = " << left << setw(5) << x << "Y = " << setw(5) << y << endl;
    cout << setfill('-')<<  setw(80) << "" << endl;
    
    temp = x;
    x = y;
    y = temp;
    
    
    cout << setfill(' ') <<  "X = " << setw(5) << x << "Y = " << setw(5) << y << endl;
  
}
