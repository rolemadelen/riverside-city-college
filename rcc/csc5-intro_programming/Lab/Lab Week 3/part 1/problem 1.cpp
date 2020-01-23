/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 10, 2013.
* HW: Lab3 worksheet part 1
* Problem: 1
* I certify this is my own work and code.
*/

// one can compare hitters in baseball by looking at their 
// slugging percentage. Write a program that calculates a
// hitter's slugging percentage.
// The user should enter the number of singles, doubles,
// triples, home_runs, and at-bats for a player. Each input
// should be a integer. Your program should output the slugging
// percentage as a floating-point value.
// The at-bats should be >= the number of singles, doubles, triples,
// and home_runs combined.
// % = (single + (2*doubles) + (3*triples) + (4*home_runs)) / at_bats;

#include <iostream>
using namespace std;
int main()
{
    //declare integer data type for single, double,triples,home_runs, and at bats.
    //declare float for slugging percentage.
    int single_hit = 0, double_hit = 0, triple_hit = 0,
        homeruns = 0, at_bats = 0;
    
    int total = 0;
    
    float slugging_percentage = 0.0;
    
    // get single hits
    cout << "Enter the number of singles : ";
    cin >> single_hit;
    
    // get double
    cout << "Enter the number of double : ";
    cin >> double_hit;
    
    // get triples
    cout << "Enter the number of triples : ";
    cin >> triple_hit;
    
    // get home_runs
    cout << "Enter the number of home_runs : ";
    cin >> homeruns;
    
    // get at-bats
    cout << "Enter the number of at-bat : ";
    cin >> at_bats;
    
    total = single_hit + double_hit + triple_hit + homeruns;
    
    
    slugging_percentage = (single_hit + (2.0*double_hit) + (3.0*triple_hit) + (4.0*homeruns)) / at_bats;
    
    //if(at-bats >= sum of all (single, double, etc...))
    if(at_bats >= total)
    {
         // output slugging percentage.
        cout << "The players slugging percentage is " << slugging_percentage << endl;
    }
    //otherwise, terminate the program
    else
    {
        cout << endl << "The value of 'at_bat' is not right.\a" << endl;
        cout << "Program terminates." << endl;
    }

    return 0;
}