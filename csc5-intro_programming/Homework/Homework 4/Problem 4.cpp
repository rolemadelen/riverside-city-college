/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 4 - Problem 4
* I certify this is my own work and code

*/

// Write a program to score the rock-paper-scissor game.
// Each of two users types in either P,R, or S. The pro-
// gram than announces the winner as well as the basis
// for determining the winner. 'paper covers rock',
// 'rock break scissors', 'scissors cut paper', or 
// nobody wins. Be sure to allow the users to use lower-
// case and uppercase letters..

#include <iostream>

using namespace std;

int main()
{
    //declare a variable for rock-paper-scissor (rps)
    char rpsUser1, rpsUser2;
    
    cout << "This program scores the Rock-Paper-Scissor game.\n"
         << "Player 1 and Player 2 will type in either P, R, or S.\n"
         << "than the program will announces the winner.\n"
         << "Okay, then.... let's begin.!\n\n";
             
    cout << "Player 1: ";
    cin >> rpsUser1;
    cout << "Player 2: ";
    cin >> rpsUser2;

    cout << endl;
    switch(rpsUser1)
    {
    case 'r':
    case 'R':
    {
        if(rpsUser2 == 'R' || rpsUser2 == 'r')
        {
            cout << "Nobody Wins.\n";
            break;
        }
        else if(rpsUser2 == 'P' || rpsUser2 == 'p')
        {
            cout << "Paper covers rock.\n"
                 << "Player 2 is the winner.\n";
                 break;
        }
        else if(rpsUser2 == 'S' || rpsUser2 == 's')
        {
            cout << "Rock break scissors.\n"
                 << "Player 1 is the winenr.\n";
                 break;
        }
        else
        {
            cout << "invaid value was inputted.\n"
                 << "Program will terminate.\n";
       			 break;
        }

    }
    case 'p':
    case 'P':
	{
        if(rpsUser2 == 'R' || rpsUser2 == 'r')
        {
            cout << "Paper covers rock.\n"
                 << "Player 1 is the winner.\n";
                 break;
        }
        else if(rpsUser2 == 'p' || rpsUser2 == 'P')
        {
	      cout << "Nobody wins.\n";
	            break;
        }
        else if(rpsUser2 == 'S' || rpsUser2 == 's')
        {
            cout << "Scissors cut paper.\n"
                 << "Player 2 is the winner.\n";
         		break;
        }
        else
        {
            cout << "Invalid value was inputted.\n"
                 << "Program will termminates.\n";
        		break;
        }
    }
    case 's':
    case 'S':
    {
        if(rpsUser2 == 'R' || rpsUser2 == 'r')
        {
            cout << "Rock break scissors.\n"
                 << "Player 2 is the winner.\n";
                  break;
        }
        else if(rpsUser2 == 'P' || rpsUser2 == 'p')
        {
            cout << "Sicssors cut paper.\n"
                 << "Player 1 is the winner.\n";
                 break;
        }
        else if(rpsUser2 == 'S' || rpsUser2 == 's')
        {
            cout << "Nobody wins.\n";
            break;
        }
        else
        {
            cout << "Invalid value was inputted.\n"
                 << "Program will terminate.\n";
        		break;
        }
    }
    default :
    {
    cout << "Invalid value was inputted.\n"
           << "The program terminates.\n";
    }
    
    }
    return 0;    
}
