/*
Jiwon Yoo
Professor Ung
CSC5 - C++ Programming
Week 4 Lab Part 1 - #5
*/

// Create a guessing game. The computer randomly selects a number
// between 1 and 100. If the user enter a number lower than the
// selected number, tell the user they have selected a too small
// number. If the user enters a larger number, tell the user they
// entered a number too large. allow the user only 10 guesses
// before starting game over.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int user_respond;
	int guesses = 10;
	int computer_number;
	char gameover;
	
	//computer generates a random number between 1 ~ 100;
	 srand(time(NULL));
	computer_number = (rand()%100) + 1;

	cout << "WELCOME TO THE GUESSING GAME!!\n\n";
	cout << "You have to guess the number that is between 1 and 100" << endl
		<< "You have 10 guesses. ready? Here we go.\n\n" << endl << endl; 

	//while(true)
	while(guesses > 0)
	{
		for(int i = 1; i <= 10; i ++)
		{
			cout << "guess " << i << ": ";
			cin >> user_respond;
		
			//if number < selected number
			if(user_respond < computer_number)
			{
				//output "number is too small"
				cout << "Your number is too small" << endl;
				guesses --;
			}
		
			//if number > selected number
			else if(user_respond > computer_number)
			{
				//output "number is too large"
				cout << "Your number is too large.\n";
				guesses --;
			}
			else
			{
				cout << "CORRECTO!! The 'number' was : " << computer_number << endl;
				return 0;

			}
			
		}
	
	}
	cout << "GAME OVER.!\n";
	
}