/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ Programming
* Week 5 Lab Part 1
* Problem 3
*/

// print the pattern like shown below with loops,
// where the number of stars in first row rectangle 
// is input by user. Dashes will never be on the edges.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, j, numStar;
    string star = "", newStar;

	    cout << "Enter the number of stars in first row of a rectangle.\n";
	    cout << "The number should be greater than 3.\n> ";
	    cin >> numStar;

	    for(i = 0; i <= numStar; i ++)
	    {
	        star += "*";
	    }

	    for(j = 0; j < (numStar - 1); j++)
	    {
	        int k = j;
	        if(k % 2 == 0)
	        {
	        star[j+1] = '-';
	        cout << star << endl;
	        star[j+1] = '*';
	        }
	    }
	    cout << endl;
	return 0;
}