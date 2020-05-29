/*
* Jiwon Yoo
* Black Jack
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Header.h"

using namespace std;

/* Default costructor */
BlackJack::BlackJack() : player_score(0), dealer_score(0)
{}

void Casino::change_chips(int _chips)
{
	chips = chips + (_chips);
}

int Casino::get_chips()
{
	return chips;
}

bool Casino::play_again()
{
	char answer;
	cout << "Player again? (y / n): ";
	cin >> answer;
	
	if (answer == 'Y' || answer == 'y')
		return true;
	else
		return false;
}

void BlackJack::play()
{
	unsigned seed = time(0);
	srand(seed);
	cout << "My chips: " << get_chips() << endl;

	while (!dealer.empty() ){
		dealer.pop_back();
	}
	while (!player.empty()){
		player.pop_back();
	}
	player_score = 0;
	dealer_score = 0;

	cout << "*-----------------------------*\n";
	players_turn();
	dealers_turn();
	cout << "*-----------------------------*\n";
}

void BlackJack::players_turn()
{
	i = 0;
	//dealt two cards
	hit(1);	hit(1);
	output(1, cout);

	thinking = true;

	while (thinking){
		cout << "hit or stay?  (h / s): ";
		cin >> hit_or_stay;
		if (hit_or_stay != 's' || hit_or_stay != 's'){
			hit(1);
			output(1, cout);
		}
		else{
			cout << "Your final score: " << player_score << endl;
			thinking = false;
		}

		if (player_score > 21){
			cout << " Busted. You lost.\n"
				<< " -20 chips\n";
			change_chips(-20);

			if (play_again())
				play();
			else
				exit(1);
		}
	}
	if (player_score == 21){
		twenty_one();
		cout << " Player automatically won.\n +50 chips.\n";
		change_chips(50);
		if (play_again())
			play();
		else
			exit(1);
	}
}

void BlackJack::dealers_turn()
{
	i = 0;
	//dealt two cards
	hit(2); hit(2);
	output(2, cout);

	while (dealer_score < 17){
		hit(2);
		output(2, cout);
	}

	if (dealer_score > 21){
		cout << " Dealer busted. You won.\n"
			<< " +20 chips\n";
		change_chips(20);
		if (play_again())
			play();
		else
			exit(1);
	}
	else if(dealer_score < player_score){
		cout << " Player won. +20 chips.\n";
		change_chips(20);
		if (play_again())
			play();
		else
			exit(1);
	}
	else if (dealer_score == player_score){
		cout << " draw..\n";
		if (play_again())
			play();
		else
			exit(1);
	}
	else{
		cout << " Dealer won.\n -20 chips.\n";
		change_chips(-20);
		if (play_again())
			play();
		else
			exit(1);
	}
}

void BlackJack::hit(int who)
{
	cardset[0] = 'A';	cardset[1] = '2';	cardset[2] = '3';
	cardset[3] = '4';	cardset[4] = '5';	cardset[5] = '6';
	cardset[6] = '7';	cardset[7] = '8';	cardset[8] = '9';
	cardset[9] = 'T';	cardset[10] = 'J';	cardset[11] = 'Q';
	cardset[12] = 'K';

	if (who == 1){
		player.push_back(cardset[deal_card()]);
		add_values(1,i);
	}
	else{
		dealer.push_back(cardset[deal_card()]);
		add_values(2,i);
	}
}

int BlackJack::deal_card()
{
	int card = rand() % 13;
	return card;
}

void BlackJack::output(int who, ostream& outs)
{
	if (who == 1){
		cout << "[Player]  ";
		for (i = 0; i < player.size(); i++){
			if (player[i] == 'T')
				cout << "10" << " ";
			else
				cout << player[i] << " ";
		}
		cout << "   (Score: " << player_score << ")" << endl;
	}
	else{
		cout << "[Dealer]  ";
		for (i = 0; i < dealer.size(); i++)
		if (dealer[i] == 'T')
			cout << "10" << " ";
		else
			cout << dealer[i] << " ";
		cout << "   (Score: " << dealer_score << ")" << endl;
	}
}

void BlackJack::add_values(int who, int& i)
{
	if (who == 1){
		player[i] == '2' ? player_score += 2 :
			player[i] == '3' ? player_score += 3 :
			player[i] == '4' ? player_score += 4 :
			player[i] == '5' ? player_score += 5 :
			player[i] == '6' ? player_score += 6 :
			player[i] == '7' ? player_score += 7 :
			player[i] == '8' ? player_score += 8 :
			player[i] == '9' ? player_score += 9 :
			player[i] == 'T' ? player_score += 10 :
			player[i] == 'J' ? player_score += 10 :
			player[i] == 'Q' ? player_score += 10 :
			player[i] == 'K' ? player_score += 10 :
			player[i] == 'A' && player_score <= 10 ? soft_a = true :
			player_score += 1;

		if (soft_a == true && player_score <= 10)
			player_score += 11;
		else if (soft_a == true && player_score > 21){
			player_score -= 10;
			soft_a = false;
		}
	}
	else{
		dealer[i] == '2' ? dealer_score += 2 :
			dealer[i] == '3' ? dealer_score += 3 :
			dealer[i] == '4' ? dealer_score += 4 :
			dealer[i] == '5' ? dealer_score += 5 :
			dealer[i] == '6' ? dealer_score += 6 :
			dealer[i] == '7' ? dealer_score += 7 :
			dealer[i] == '8' ? dealer_score += 8 :
			dealer[i] == '9' ? dealer_score += 9 :
			dealer[i] == 'T' ? dealer_score += 10 :
			dealer[i] == 'J' ? dealer_score += 10 :
			dealer[i] == 'Q' ? dealer_score += 10 :
			dealer[i] == 'K' ? dealer_score += 10 :
			dealer_score += 1;
	}
	i++;
}

void BlackJack::twenty_one()
{
	cout << endl << endl;
	cout << "d##b     d###    d#####b          ##    ##P \n";
	cout << " ##B      9##   #P    ##          ##   d#B  \n";
	cout << " ##B      ###         ##  d####b  ##  ##P   \n";
	cout << " ##B      ###         ## #######P ####B     \n";
	cout << " #####be  ###   d####### #P       ## ##b    \n";
	cout << " ###P   D ###  #P     d# #b       ##   #Pb  \n";
	cout << " ###b   D ##b  #b     d# d######b ##    #Bb \n";
	cout << " ######P  ###P  E#####P   9####P  ##    ###P\n\n";
	cout << "                           d####   d#####b          ##    ##P  #####\n";
	cout << "                             ###  #P    ##          ##   d#8   #####\n";
	cout << "                             ###        ##  d####b  ##  ##P    #####\n";
	cout << "                             ###        ## #######P ####B      #####\n";
	cout << "                             ###  d####### #P       ## ##b     #####\n";
	cout << "                      d#b    ### #P     d# #b       ##   #Pb       \n";
	cout << "                       3#P   ##b #b     d# d######b ##    #Bb   ###\n";
	cout << "                        9#####P   E#####P   9####P  ##    ###P  ###\n\n\n";
}
