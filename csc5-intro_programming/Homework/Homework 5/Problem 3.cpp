*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 5 - Problem 3
* I certify this is my own work and code
*/

// Put programs 5 and 6, from Homework 4 into one project,
// specifically, allow the user to select between program 4
// and program 5 through some sort of menu-based operation.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int select;
    while(true)
    {
    cout << "Rock, Paper, Scissor Game.\n\n";
    cout << "Select : \n"
         << "1. Player VS. Player\n"
         << "2. Computer VS. Computer\n"
         << "3. Exit\n";
             
    cout << ": ";
    cin >> select;  

    switch(select)
    {
    case 1:
    {
            //declare a variable for rock-paper-scissor (rps)
        char rpsUser1, rpsUser2;
        char respond;
        
        cout << "This program scores the Rock-Paper-Scissor game.\n"
             << "Player 1 and Player 2 will type in either P, R, or S.\n"
             << "than the program will announces the winner.\n"
             << "Okay, then.... let's begin.!\n\n";
                 
        while(true)
        {
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
                 << "The program terminates.\n\n";
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
            }break;
    
        case 2:
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
    
    case 3:
    cout << "Exiting.\n"; return 0;
    
    default : cout << "Invalid selection.\n";
    }
	}
}

