#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Casino
{
public:
	/* add or subtract chips */
	void change_chips(int _chips);
	int get_chips();
	bool play_again();
private:
	int chips = 100;
};

class BlackJack : Casino
{
public:
	BlackJack();
	
	/* start the game;
		begin with two given cards */
	void play();
	void players_turn();
	void dealers_turn();
	void twenty_one();

	/* get another card.
		1 for player, 2 for dealer*/
	void hit(int who);
	/* not get another card */
	void stay();

	/* output player's or dealer's card */
	void output(int who, ostream& outs);

private:
	vector<char> player;
	vector<char> dealer;
	int player_score;
	int dealer_score;
	bool soft_a;
	bool thinking;

	char hit_or_stay;

	char cardset[14];

	/* check if card is over 21 */
	bool check_card();

	/* deal random card */
	int deal_card();

	/* add card values */
	void add_values(int who, int& i);
	int i;
};