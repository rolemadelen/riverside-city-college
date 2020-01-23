/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 1 - problem 2
*/

//////////////////////////////////////////////////////////
// The game of “23” is a two-player game that begins with a
// pile of 23 toothpicks. Players take turns, withdrawing
// either 1,2, or 3 toothpicks at a time. The player to
// withdraw the last toothpick loses the game. Write a
// human vs. computer program that plays “23”. The human 
// should always move first. When it is the computer’s turn,
// it should play according the following rules:
//
// 1) If there are more than 4 toothpicks left,
// the computer should withdraw 4 – X toothpicks, where X
// is the number of toothpicks the human withdrew on the
// previous turn.
//
// 2) If there are 2 to 4 toothpicks left, the computer
// should withdraw enough toothpicks to leave 1.
//
// 3) If there is 1 toothpick left, the computer has to
// take it and loses.
//
// When the human player enters the number of toothpicks to
// withdraw, the program should perform input validation.
// Make sure the entered number is between 1 and 3 and that
// the player is not trying to withdraw more toothpicks
// than exist in the pile.
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// this function determines whether a user
// wants to try again or not
// parameter is 'char', the users answer.
// returns true to re-start, false to terminate.
bool tryAgain(char respond);

int main()
{
    cout << "\t============================================\n";
    cout << "\tThe game of \"23\" is a two player game\n"
        << "\tthat begins with a pile of 23 toothpicks.\n"
        << "\tPlayer take turns, withdrawing either 1,2, or 3\n"
        << "\ttoothpicks at a time. The player to withdraw\n"
        << "\tthe last toothpick loses the game...\n"
        << "\tAlright then, let's begin.\n";
    cout << "\t============================================\n\n";

    while(true)
	{
        char respond; //ask user to tryAgain.
        int player; //variable for a player to withdraw.
        int remainingTpicks = 23; //remaining toothpicks;

        // start with 23 toothpicks
        cout << "Number of toothpicks : "
		     << remainingTpicks << endl;

        // player withdraws only 1,2, or 3
        cout << "Player's turn : ";
        cin >> player;

        // input validation.
        while(player < 1 || player > 3)
        {
            cout << "ERROR!\a\n";
            cout << "Player's turn : ";
            cin >> player;
        }

        remainingTpicks -= player;
        cout << "\nNumber of toothpicks : "
			 << remainingTpicks << endl;

        // if there are more than 4 toothpicks left,
        // the computer withdraws 4 - x toothpicks, where
        // x is the number of toothpicks withdrew by a player
        // in previous turn.
        while(remainingTpicks > 4)
        {
            int computer = (4 - player);
            cout << "Computer's turn : " << computer << endl;

            remainingTpicks -= computer;
            cout << "\nNumber of toothpicks : "
                 << remainingTpicks << endl;

            cout << "Player's turn : ";
            cin >> player;

            while(player < 1 || player > 3)
            {
            cout << "ERROR!\a\n";
            cout << "Player's turn : ";
            cin >> player;
            }
            remainingTpicks -= player;
            cout << "\nNumber of toothpicks : "
                 << remainingTpicks << endl;

        }

        if(remainingTpicks <= 4 && remainingTpicks >= 2)
        {
            int cnt = 0;
    // if there are 2 to 4 toothpicks left, the computer should
    // withdrew enough to leave 1 toothpick.
            while(remainingTpicks != 1)
            {
                cnt ++;
                remainingTpicks --;
            }
            cout << "Computer's turn : " << cnt << endl;
            cout << "\nNumber of toothpicks : "
                 << remainingTpicks << endl;

            if(remainingTpicks == 1)
            {
            cout << "Player took the last toothpick.\n"
                 << "You lost the game.\n\n";
            }
        }

        // if there 1 left, computer takes and loses the game.
        else if(remainingTpicks == 1)
        {
            cout << "Computer's turn : 1" << endl;
            cout << "Computer took the last toothpick.\n"
                 << "You won the game.\n\n";
        }
        else
        {
      	    cout << "Player took the last toothpick.\n"
                 << "You lost the game.\n\n";
        }
        // prompt thr user to tryAgain.
        cout << "Do you want to try again? (Y / N) : ";
        cin >> respond;
        if(tryAgain(respond))
        {
            for(int i = 0; i <= 50; i ++)
            {
                cout << endl;
            }
            cout << "BEGIN!!\n";
        }
        else
        {
            cout << "That's it!\n";
            return 0;
        }
    }
}

bool tryAgain(char respond)
{
        return ((respond == 'y') || (respond == 'Y'));
}
