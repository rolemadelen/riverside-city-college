/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab 7 problem 10
*/

///////////////////////////////////////////////////////////////
// Write a program that tells what coins to give out for
// any amount of change from 1 cent to 99 cents. For example,
// if the amount is 86 cents, the output would be something
// like the following:

// 86 cents can be given as
// 3 quarter(s) 1 dime(s) and 1 penny(pennies)

// Use coin denominations of 25 cents (quarters),
// 10 cents (dimes), and 1 cent (pennies).
// Do not use nickel and half-dollar coins.

// Your program will use the following function (among others):
////////////////////////////////////////////////////////////////////
// void compute_coins(int coin_value, int &num, int &amount_left);
/////////////////////////////////////////////////////////////////////
// Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
// Postcondition: num has been set equal to the maximum number of
// coins of denomination coin_value cents that can be obtained
// from amount_left. Additionally, amount_left has been decreased
// by the value of the coins, that is, decreased by num * coin_value

// For example, suppose the value of the variable amount_left is 86.
// Then, after the following call, the value of number will be 3
// and the value of amount_left will be 11
// (because if you take 3 quarters from 86 cents, that leaves 11 cents):

// compute_coins(25, number, amount_left);

// Include a loop that lets the user repeat this computation
// for new input values until the user says he or she wants
// to end the program.
////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

/*
This function reads in a coin_value such as 25, 10, or 1 and the 
amount the user have,  1 ~ 99 cents. Then return how many coins
they have (quarters, dimes, or pennies).
Parameters : coin value, variable that stores a coin, and the 
amount left.
return type is pseudo-return.
*/
void compute_coins(int coin_value, int &num, int &amount_left);

//check if an amount the user have is less than 100 and larger
//than 0.
//parameter : amount left ( what user have ).
//return type : pseudo-returns.
void checkAmount(int &amountLeft);

//check if coin value is between 1 and 100.
//parameter : get coin value
//returny type : pseudo-returns.
void checkValue(int &coinVal);
int main()
{
	cout << " This program tells what coins to give out for\n"
		 << " any amount of change from 1 to 99 cents.\n";
	cout << " Enter -1 to quit.\n";
	for(;;)
	{
		//amount of coins a user have..(amount_left)
		int amount;
		//variable to store number of coins.
		int num = 0;

		cout << "\n Enter the amount between 1 and 99 cents.\n > ";
		cin >> amount;

		if(amount == -1)
			return 0;

		cout << " " << amount << " cents can be given as....\n";

		//quarters
		compute_coins(25,num,amount);
		cout << " " << num << " quarter(s) ";

		//dimes
		compute_coins(10,num,amount);
		cout << " " << num << " dime(s) and ";

		//cents
		compute_coins(1,num,amount);
		cout << " " << num << " penny(pennies)..\n";
	}
}

void compute_coins(int coin_value, int &num, int &amount_left)
{
	// Precondition: 0 < coin_value < 100; 0 <= amount_left < 100.
	//helper function to check coin_Value and amount_Left.
	checkAmount(amount_left);
	checkValue(coin_value);

	num = static_cast<int>(amount_left / coin_value);
	amount_left -= (num * coin_value);
	// Postcondition: num has been set equal to the maximum number of
	// coins of denomination coin_value cents that can be obtained
	// from amount_left. Additionally, amount_left has been decreased
	// by the value of the coins, that is, decreased by num * coin_value
}

void checkAmount(int &amountLeft)
{
	while(amountLeft < 0 || amountLeft >= 100)
	{
		cout << " Please enter a value between 0 - 99.\n> ";
		cin >> amountLeft;
	}

	return;
}

void checkValue(int &coinVal)
{
	 while(coinVal <= 0 || coinVal > 100)
	 {
		cout << " Coin value must be between 1 and 100.\n> ";
		cin >> coinVal;
	 }
	 return;
}