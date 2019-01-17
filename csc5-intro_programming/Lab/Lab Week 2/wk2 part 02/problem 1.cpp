//Jiwon Yoo
//Lab 3  week 2 part 2
//Write a statement that will increment whatever the integer variable x is storing by 5.

#include <iostream>
using namespace std;

int main()
{
    //declare x and initialize
    int x = 0;
    
    // get value of x;
    cout << "Enter the value of x.\n:";
    cin >> x;
    
    // output x;
    x += 5;
    cout << "x : " << x << endl;
    return 0;
}