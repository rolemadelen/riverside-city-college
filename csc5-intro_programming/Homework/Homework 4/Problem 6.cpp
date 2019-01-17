/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 4 - Problem 6
* I certify this is my own work and code
*/	

// Modify program 4 to allow two computer bots 
// to play the game. The user will control each
// new game and decide when to stop playing, but 
// the computer bots will make the decisions to 
// choose rock, paper, or scissors. The user 
// should be able to play as many times as they want.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //declare a variable for rock-paper-scissor (rps)
    char rpsUser1, rpsUser2;
    char rps[] = {'R','P','S'};
    char respond;
    
    cout << "This program scores the Rock-Paper-Scissor game.\n"
         << "Computer 1 and Computer 2 will type in either P, R, or S.\n"
         << "than the program will announces the winner.\n"
         << "Okay, then.... let's begin.!\n\n";
      
	srand((time(NULL)));
	
    while(true)
    {
    rpsUser1 = rps[rand() % 3];
    rpsUser2 = rps[rand() % 3];

    cout << "Computer 1: " << rpsUser1 << endl;
    cout << "Computer 2: " << rpsUser2 << endl;

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
                     << "Computer 2 is the winner.\n";
                     break;
            }
            else if(rpsUser2 == 'S' || rpsUser2 == 's')
            {
                cout << "Rock break scissors.\n"
                     << "Computer 1 is the winenr.\n";
                     break;
     	   }
        }
        case 'p':
        case 'P':
        {
            if(rpsUser2 == 'R' || rpsUser2 == 'r')
            {
                cout << "Paper covers rock.\n"
                     << "Computer 1 is the winner.\n";
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
                     << "Computer 2 is the winner.\n";
                 	break;
            }
        }
        case 's':
        case 'S':
        {
            if(rpsUser2 == 'R' || rpsUser2 == 'r')
            {
                cout << "Rock break scissors.\n"
                     << "Computer 2 is the winner.\n";
                     break;
            }
            else if(rpsUser2 == 'P' || rpsUser2 == 'p')
            {
                cout << "Sicssors cut paper.\n"
                     << "Computer 1 is the winner.\n";
                    break;
            }
            else if(rpsUser2 == 'S' || rpsUser2 == 's')
            {
               cout << "Nobody wins.\n";
               break;
            }
         }
    }
        cout << endl << "Do you want to try again? (Y or N) : ";
        cin >> respond;
        if(respond == 'y' || respond == 'Y')
        {
              cout << "Alright.\n\n";
        }
        else
        {
            cout << "That's it!\n";
            return 0;
        }
	}	       
}