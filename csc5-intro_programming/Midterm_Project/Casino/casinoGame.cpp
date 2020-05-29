/*
* Jiwon Yoo
* Professor Ung
* CSC5 - C++ computer programming
* Project 1 - Mini Casino Game
* start : October 5, 2013. fixed : 17th
* finished : October 12, 2013. fixed : 
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//global variable is used to interact with this
//variable in every game, or function.
int initialSum = 100;

//purpose of this function is to play game Craps.
//return type is void.
//parameter : none.
void craps();

//purpose of this function is to play game Roulette.
//return type is void.
//parameter : none.
void fiveCardPoker();

//purpose of this function is to play game Slots.
//return type is void.
//parameter : none.
void slots();

//purpose of this function is to
//generate a specific value of a
//random number.
//return type is integer.
//parameter : min value and max value
int randNum(int min, int max);

//purpose of this function is to get a value
//of cards : Ace - King
//return type is string.
//parameter is void.
string cardRand();

//purpose of this function is to determine
//whether a player has a winning hand or not.
//retrun type is void.
//parameter is 5 value of cards.
void cardCheck(string a, string b,
			   string c, string d, string e);
			   
//purpose of this function is to keep in track w/
//the money that a player has.
//return type is void.
//parameter is referenced : int type var. money;
void currentMoney(int &money, int div);

//purpose of this function is to get initial bet
//from a user.
//return type is integer.
//parameter : player's total money
int placeBet(int initialSum);

//purpose of this function is to determine
//whether to keep playing a game or not by
//prompting a user yes or no question
//return type is boolean.
//parameter : choice of a player.
bool startGame(char choice);

// clears the screen
void clear() {
    for(int i=0; i<50; ++i)
        cout << endl;
}
string randSlot();

int main()
{	
	//used fstream to save the data of a player's name to
	//show who was the last person played this game.
	string name;
	ofstream saveData;
	ifstream takeData("data.dat"); //open data.dat
	takeData >> name; //get name
	takeData.close(); //close
	cout << "The last person who played Mini Casino : " << name << ".\n";
	cout << "What is your name? : "; // get name
	cin >> name;
	saveData.open("data.dat"); //reads in a name from a file
	saveData << name;
	saveData.close();
	clear(); //clear the screen	
	cout << endl << endl;

	while(true)
	{
		cout <<"  d8888888b 888888888   .d8888  88888888 d88b     d8b  d888b\n";
		cout <<" 8888888P\" 888d   8888 d8888888 X888888X.Y8888b   888 8888888\n";
		cout <<"8888P\"     888d   88888b.         d88b   88P Y8   888d88EE888b\n";
		cout <<"888P       88888888888 Y8888888b  8888   888  88  888d88   888\n";
		cout <<"888b       88888888888  88888888b 8888   888  88  888d88   888\n";
		cout <<"88888.     8888   8888        \"88 d88b   888   8b X88Y88EE888P\n";
		cout <<" 8888888b  8888   8888  888888P Y8888888 888   88888d 8888888\n";
		cout <<"  Y888888Pd8888  d8888  \"8888P  88888888 d8b    Y888   d888P\n\n";

		cout << "\n*--- Mini Casino Game by Jiwon Yoo.\n\n";
		cout << "Welcome, " << name << ".\n" 
			 << "100 chips are given to play. First time only...\n\n";
		cout << "You have $" << initialSum << endl << endl;
		int select = 0;
		cout << "Select a game to play : \n\n";
		cout << "1. Craps\n"
				<< "2. 5 Card Poker\n"
				<< "3. Slots\n"
				<< "4. Exit.\n";

		if(initialSum == 0)
		{
			cout << "5. Get free chips.\n> ";
			cin >> select;
		}
		else
		{
			while(select < 1 || select > 4)
			{
			cout << "> ";
			cin >> select;
			}
		}

		switch(select)
		{
		case 1: clear();craps(); break;
		case 2: clear();fiveCardPoker(); break;
		case 3: clear();slots(); break;
		case 4:
			{
				cout << "Exiting...\n";
				return 0;
			}
		case 5:
			{
			initialSum += 10;
			clear();
			}
		}
	}
}

void craps()
{
	int dice1, dice2, sum, sum2;
	int wins = 0, loses = 0;
	int initialBet;
	char start;

	unsigned seed = time(0); srand(seed);
	cout << endl << endl;
	cout << "  8888b.d888 d8b.8888b. 88888b.  .d8888b       \n";
	cout << " 88Y\"   888e8Y\"      \"88b88 \"88b88K        \n";
	cout << "888.    888    .d8888888888   888\"Y8888b      \n";
	cout << " 888b.  888    888   888888  d88P     X88      \n";
	cout << "  Y88888888    \"Y88888\" 888888\"   8888P\"   \n";
	cout << "                         888                   \n";
	cout << "                         888                   \n";
	cout << "                         888                   \n\n";

	cout << "\nCraps is a game that takes place over 2 rounds.\n\n"
		<< "In round one, 2 dice are rolled. If the sum of the\n"
		<< "dice is either 7 or 11, you win your bet. If it's\n"
		<< "2,3 or 12, you lose, or you crapped. If it's any other\n"
		<< "number, the next round begins.\n\n";
	cout << "In round 2, 2 dice are rolled. If the roll is 7,\n"
		<< "all bets are lost. Otherwise, the rolls continue\n"
		<< "until the first number rolled is rolled again,\n";
	cout << "==========================================================\n\n";

	//prompt a user to play game or not
	cout << "Start the game? (Y / N) : ";
	cin >> start;
	//if yes, clear the screen and start playing.
	if(startGame(start))
		clear();
	//if no, clear the screen and go back to Main
	else
	{
		clear();
		return;
	}

	while(true)
	{
		//round 1 begins, prompt the user how much they have
		cout << "Round 1.................\n\n";
		cout << "You have $" << initialSum << endl;

		// if a player has no money to play, prompt that you 
		// cannot play anymore and exit.
		if(initialSum == 0)
		{
			cout << "You have 0 chips. GAME OVER.\n"
				 << "Back to Main Menu? (Y / y) : ";
			cin >> start;
			if(startGame(start))
				clear();
			return ;
		}

		// get bet
		//if bet is less than 0 or greater than what you have,
		// get the value again
		initialBet = placeBet(initialSum);
	
		//store randValue in dice1 and dice2
		//sum = total value of two dices
		dice1 = randNum(1,6);
		dice2 = randNum(1,6);
		sum = dice1 + dice2;

		//if sum of 2 dice = either 7 or 11
		// player wins.
		if(sum == 7 || sum == 11)
		{
			cout << "You rolled : " << sum << endl;
			cout << "You won your bet.\n\n";
			initialSum += initialBet;
			cout << "Do you want to try again? (Y / N) : ";
			cin >> start;
			if(startGame(start))
			{
				clear();
			}
			else
			{
				clear();
				return;
			}
		 }

		//if sum of 2 dice = 2, 3 or 12
		// player lose, crapped.
		else if(sum == 2 || sum == 3 || sum == 12)
		{
           cout << "You rolled : " << sum << endl;
           cout << "You crapped out. You lost.\n";
           initialSum -= initialBet;
           cout << "Do you want to try again? (Y / N) : ";
           cin >> start;
           if(startGame(start))
           {
			clear();
           }
           else
           {
			clear();
			return;
           }
		}

		//otherwise move on to round 2
		else
		{
			cout << "You rolled : " << sum << endl;
	
			//round 2 begins.
			//player may bet more on top of previous bet
			cout << "\nRound 2.................\n\n";

			//bet more if user wants to..
			//but cannot bet if a user has 0 chips.
			if(initialSum - initialBet != 0)
			{
			cout << "You have " << initialSum - initialBet
				 << " chips left." <<  endl;
			cout << "Do you want to bet more? (Y / N) : ";
			cin >> start;
			//if yes, get additional bet
				if(startGame(start))
				{
				cout << "\nCurrent bet : $" << initialBet << endl;
				initialBet = initialBet + placeBet(initialSum - initialBet);
				}
			//otherwise continue
			}
		
			while(true)
			{
				//round 2, store new rand value 
				//sum2 = total value of 2 dices
				dice1 = randNum(1,6);
				dice2 = randNum(1,6);
				sum2 = dice1 + dice2;

				// in round2 if sum2 of 2 dice is 7
				// player lose
				if(sum2 == 7)
				{
					cout << sum2 << " is rolled.\n";
					cout << "You lost all your bet!\n";
					initialSum -= initialBet;
					//ask a user to try again.
					cout << "Do you want to try again? (Y / N) : ";
					cin >> start;
					//if yes, clear screen and re-play it.
					if(startGame(start))
					{
						clear();
						break;
					}
					//if no, clear screen and return to Main
					else
					{
						clear();
						return ;
					}
				}
				//if total value in round2(sum2) == round1(sum)
				//user win
				else if(sum2 == sum)
				{
					cout << sum2 << " is rolled.\n";
					cout << "You wont the bet.\n";
					initialSum += initialBet;
					//ask user try again?
					cout << "Do you want to try again? (Y / N) : ";
					cin >> start;
					//if yes, re-play it.
					if(startGame(start))
					{
						clear();
						break;
					}
					//if no, return to Main
					else
					{
						clear();
						return;
					}
				}
				//if sum2 != sum or sum2 != 7
				//continue rolling
				else
				{
					cout << sum2 << " is rolled.\n";
					cout << "Continue rolling......(enter)\n";
					fflush(stdin);
					getchar();
				}
			}
		}
	}
}

void fiveCardPoker()
{
	unsigned seed = time(0); srand(seed);
	char start;

	cout << endl << endl;
	cout << "                8888\n";
	cout << " 888888b. .d88b.  Y8 888k_ .d88b.  888  d8b. \n";
	cout << " 888    888    88 888B    d8P  Y8b 888 8Y    \n";
	cout << " 88888P  88    88 88 88   88888888 8888\"     \n";
	cout << " 88P     8b    d8 88  8b  Y8b.     888    \n";
	cout << " 888      \"8888\" 888   88b.\"Y8888  888      \n\n";

	cout << "\n The objective of 5 card poker is to have\n"
		 << " a winning hand. The user is given 5 cards.\n"
		 << " The user can select to exchange any number\n"
		 << " of cards from the current given hand.\n\n"
		 << " Wins :  \n"
		 << " ========================================\n"
		 << " Pair                5 5\n"
		 << " Two Pair            K K 7 7\n"
		 << " Three of a Kind.    9 9 9\n"
		 << " Four of a Kind.     A A A A\n"
		 << " Full House.         8 8 8 J J\n";
	cout << " ========================================\n";

	//if user got no money to play,
	//only option is to go back to the Menu
	if(initialSum == 0)
	{
		cout << "Back to Main Menu (N / N) : ";
		cin >> start;
		clear();
			return ;
	}
	//prompt a user to start game or not
	cout << " Start the game? (Y / N) : ";
	cin >> start;
	//if yes, clear screen and start playing
	if(startGame(start))
		clear();
	//if no, clear screen and go back to Main
	else
	{
		clear();
		return;
	}

	while(true)
	{
		//declare 5 variables and
		//deal/store 5 cards to 5 diff. variables.
		string card1 = cardRand();
		string card2 = cardRand();
		string card3 = cardRand();
		string card4 = cardRand();
		string card5 = cardRand();
	
		//show a user what cards they have
		cout << " Your card :\n " << card1 << card2 << card3
			 << card4 << card5 << endl << endl;

		//ask user to exchange any cards or not.
		cout << " Do you want to exchance any cards? (Y / N) : ";
		cin >> start;

		//if user wants to exchange any cards
		//ask how many cards to exchange
		if(startGame(start))
		{
			int exchange,select;
			cout << " How many cards ?\n > ";
			cin >> exchange;
			//if user say 0 or 6, get input again
			while(exchange < 1 || exchange > 5)
			{
				cout << " > ";
				cin >> exchange;
			}
			cout << " 1. " << card1 << endl
				 << " 2. " << card2 << endl
				 << " 3. " << card3 << endl
				 << " 4. " << card4 << endl
				 << " 5. " << card5 << endl;
			cout << "One by one, enter a number of card to change.\n";
			
			//let user change cards one by one.
			for(int i = 0; i < exchange; i ++)
			{
				cout << " > ";
				cin >> select;
				switch(select)
				{
				case 5: card5 = cardRand(); break;
				case 4: card4 = cardRand(); break;
				case 3: card3 = cardRand(); break;
				case 2: card2 = cardRand(); break;
				case 1: card1 = cardRand(); break;
				}
			}
			//output result;
			cout << " Result :\n " << card1 << card2 << card3
			 << card4 << card5 << endl << endl;
			 //function invocation : check a pair, double pair
			 //3 of a kind, 4 of a kind, or a full house.
			cardCheck(card1,card2,card3,card4,card5);
		}
		//otherise : user is not exchanging any cards.
		//output results
		else
		{
			cout << "\n Result :\n " << card1 << card2 << card3
			 << card4 << card5 << endl << endl;
			 //function invocation
			cardCheck(card1,card2,card3,card4,card5);
		}
		//ask a user to try again.
		cout << " Do you want to try again? (Y / N) : ";
		cin >> start;
		//if yes, clear screen and go back to the start.
		if(startGame(start))
			clear();
		//if not, clear screen and go back to the Main
		else
		{
			clear();
			return ;
		}
	}
}

void slots()
{
 
 char start;
	//used to store amount of dollars and credits
	int credits, dollars; 
	unsigned seed = time(0); srand(seed);
	cout << endl << endl;
	cout << "         888        888    \n"
		 << ".d8888b  888        888   \n";
	cout << "88b      888  8888 d8888b   \n";
	cout << "\"Y8888b. 888 88  88 888    \n";
	cout << "     d88 888 88  88 Y88b     \n";
	cout << " 8888P\"  888  8888  \"Y888b.  \n\n";

	cout << " Slots is a game of random chance. A win is when a \n"
		 << " combination of symbols are on a single row, specifically\n"
		 << " the center row. There is one symbol that acts like a \n"
		 << " wild and cherry. Wild symbol, or 'W', have half the\n"
		 << " chance of appearing than all other symbols.\n"
		 << " *1 game cost 10 credits.*\n";
	cout << "\n Point allocations : (center row only)\n"
		 << "==========================================\n"
		 << left << setw(15) << " Wild  (W) " << " 5000 credits\n"
		 << setw(15) << " Cherry(C)" << " 20 credits\n"
		 << setw(15) << " normal(X)" << " 30 credits\n"
		 << setw(15) << " normal(P)" << " 30 credits\n"
		 << setw(15) << " normal(O)" << " 30 credits\n"
		 << setw(15) << " normal(U)" << " 30 credits\n"
		 << "==========================================\n\n";

	//prompt a user to run this program or not.
	//if the user have no money, only option is
	//to go back to Main Meun.
	if(initialSum == 0)
	{
		cout << "Back to Main Menu (N / N) : ";
		cin >> start;
		clear();
			return ;
	}
	cout << "Start the game? (Y / N) : ";
	cin >> start;
	//if yes, clear screen and start playing
	if(startGame(start))
		clear();
	//if no, clear screen and go back to Menu
	else
	{
		clear();
		return ;
	}
	
	//convert dollars into credits.
	//a dollar is equal to 10 credits.
	cout << " You need credits to play slots.\n";
	cout << " You have $" << initialSum << endl << endl;
	cout << " 1 dollar = 10 credits.\n\n";
	cout << " Enter an amount of a dollar to exchange. $";
	cin >> dollars;
	//if user input money that is less than 0 or
	//greather than what they have.
	//get input again
	while(dollars < 1 || dollars > initialSum)
	{
		cout << " Enter an amount of a dollar to exchange. $";
		cin >> dollars;
	}
	credits = dollars * 10;
	initialSum -= dollars;
	clear();

	//where the actual game starts
	while(true)
	{
		//game starts
		//output how much they have.
		cout << " You have " << credits << " credits.\n\n";
		//if credits == 0 go back to main menu
		if(credits == 0)
		{
			cout << "You have 0 credits. GAME OVER.\n"
				 << "Back to Main Menu? (Y / y) : ";
			cin >> start;
			if(startGame(start))
				clear();
			return ;
		}
		//prompt the user to keep play or not
		cout << " You may input 'y' several time.\n"
			 << " ex) 'YYY' run slots three times.\n";
		cout << " 'Y' to play, 'Q' to quit. : ";
		cin >> start;
		if(startGame(start))
		{
			credits -= 10;
			clear();
		}
		//when user quit, change credits
		//back to dollar value and add the value to initialSum.
		else
		{
			clear();
			initialSum += (credits / 10);
			return ;
		}

		//store rand symbol to each row
		string row1 = randSlot(), row1_2 = randSlot(), row1_3 = randSlot();
		string row2 = randSlot(), row2_2 = randSlot(), row2_3 = randSlot();
		string row3 = randSlot(), row3_2 = randSlot(), row3_3 = randSlot();

		//add each symbol to string to form a complete row.
		string line1 = "  " + row1 + "  " + row1_2 + "  " + row1_3;
		string line2 = "  " + row2 + "  " + row2_2 + "  " + row2_3;
		string line3 = "  " + row3 + "  " + row3_2 + "  " + row3_3;
		
		//display results , or slots
		cout << " Jiwon's slot game.\n";
		cout << " " << setfill('=') << setw(9) <<  "" << endl;
		cout << line1 << "\n" << line2 << "\n" << line3 << endl;
		cout << " " << setw(9) << "" <<  setfill(' ') << endl;

		//if center row symbol is all same
		if(row2 == row2_2 && row2_2 == row2_3)
		{
			//and if its wild, add 5000 credits.
			if(row2 == "W")
			{
				cout << " WILD WILD WILD!!!.\n"
					 << " WIN!!! 5000 credits.\n";
				credits += 5000;
			}
			//if not wild, add 30 credits
			else
			{
				cout << " WIN!! 30 Credits.\n";
				credits += 30;
			}
		}
		//if its cherry, add 20 credits
		else if(row2 == "C" || row2_2 == "C"
				|| row2_3 == "C")
		{
			cout << " CHERRY!! Win 20 credits.\n";
			credits += 20;
		}
	}
}

int randNum(int min, int max)
{
     return rand() % (max - min + 1) + min;
}

string cardRand()
{
	string card[]={"A ","1 ","2 ","3 ","4 ","5 ","6 ",
				 "7 ","8 ","9 ","10 ","J ","Q ","K "};
	return card[rand()%14];
}

void cardCheck(string a, string b,
			   string c, string d, string e)
{
	int pair=0;
	if(a==b||a==c||a==d||a==e||
		b==c||b==d||b==e||c==d||
		c==e|d==e)
	{
		//pair
		pair = 1;
		if(a==b&&c==d||a==b&&c==e||
	   a==b&&d==e||a==c&&d==e||
	   a==c&&b==d||a==c&&b==e||
	   a==d&&b==c||a==d&&b==e||
	   a==d&&c==e||a==e&&b==c||
	   a==e&&b==d||a==e&&c==d||
	   b==c&&d==e||b==d&&c==e||
	   b==e&&c==d)
		//double pair
		pair = 2;
	}
	if(a==b&&b==c||a==b&&b==d||
	   a==b&&b==e||a==c&&c==d||
	   a==c&&c==e||a==d&&d==e||
	   b==c&&c==d||b==c&&c==e||
	   c==d&&d==e)
	{
		//Three of a kind.
		pair = 3;
		if(a==b&&b==c&&c==d||a==b&&b==c&&c==e||
	   a==b&&b==d&&d==e||a==c&&c==d&&d==e||
	   b==c&&c==d&&d==e||b==c&&c==d&&d==e)
	   //Four of a kind.
		pair = 4;		
	}
	if(a==b&&b==c&&d==e||a==b&&b==d&&c==e||
	   a==b&&b==e&&c==d||a==c&&c==d&&b==e||
	   a==c&&c==e&&b==d||a==d&&d==e&&b==c||
	   b==c&&c==e&&a==d||c==d&&d==e&&a==b)
	   //full house
	   pair = 5;
	switch(pair)
	{
	case 1:
		{
			cout << " A PAIR!! You won.\n";
			cout << " + $10\n";
			initialSum += 10; break;
		}
	case 2:
		{
			cout << " A DOUBLE PAIR!! You won.\n";
			cout << " + $20\n";
			initialSum += 20;break;
		}
	case 3:
		{
			cout << " THREE OF A KIND!! You won.\n";
			cout << " + $30\n";
			initialSum += 30;break;
		}
	case 4:
		{
			cout << " FOUR OF A KIND!! You won.\n";
			cout << " + $40\n";
			initialSum += 40;break;
		}
	case 5:
		{
			cout << " FULL HOUSE!! You won.\n";
			cout << " + $100\n";
			initialSum += 100;break;
		}
	default :
		{	
			cout << " NOTHING...You lost\n";
			cout << " - $10\n";
			initialSum -= 10;break;

		}
	}
}
void currentMoney(int &money, int div)
{
	money += div;
	if(money <= 0)
	{
		money = 0;
	}
}

int placeBet(int initialSum)
{
    int initialBet = 0;
    while(initialBet < 1 || initialBet > initialSum)
    {
        cout << "Place your bet ($1 - $"
             << initialSum << ") : $";
      cin >> initialBet;      
    }
    return initialBet;
}

bool startGame(char choice)
{
	return (choice == 'y' || choice == 'Y');
}

string randSlot()
{
	char row[] = {'C','X','P','U','O','U',
				  'X','P','O','W'};
	string str1;
	str1 = row[rand()%10];

	return str1;
}
