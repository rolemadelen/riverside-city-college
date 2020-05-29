/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 4 - Problem 3
* I certify this is my own work and code
*/

// Write a program that calculates the total grade
// for N classroom exercises as a percentage. The
// user should input the value for N followed by
// each of the N scores and totals. Calculate the
// overall percentage and output it as a percentage..

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int howManyClass;
    double totalEarn = 0, totalPossible = 0;
    double score, totalScore;
    double percentage;

    cout << "How many classes to input? : ";
    cin >> howManyClass;
    cout << endl;

    for(int n = 0; n < howManyClass; n++)
    {
        cout << "Score received for exercise "
                    << n+1 << ": ";
        cin >> score;
        cout << "Total points possible for exercise "
             << n+1 << ": ";
        cin >> totalScore;
                
        totalEarn += score;
        totalPossible += totalScore;
        cout << endl;
    }
        
    percentage = (totalEarn / totalPossible) * 100;

    cout << "Your total is " << totalEarn
         << " out of " << totalPossible
         << ", or " << fixed << showpoint << setprecision(2)
         << percentage << "%" << endl;
    return 0;
}
