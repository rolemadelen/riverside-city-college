/*
	Author: Jiwon Yoo
	File: main.cpp
	February 28, 2016, ( BEGIN: 17:54 PM
						 END  : 18:50 PM )	

	Credit Card error detection check --> luhn Algorithm
*/

// System Libraries
#include <iostream>
#include <cstdlib>	// srand
#include <ctime>	// time
using namespace std;

// Function Prototypes
void genCCrd(char [], const char);
void luhn(char [], const char);

// Execution begins here
int main(int argc, char **argv) {
	// Initialize the random seed
	unsigned seed = time(0);
	srand(seed);
	
	// Declare variables
	const char SIZE = 12;	
	char crg_accNum[SIZE] = {};

	// Generate a random cc account number
	genCCrd(crg_accNum, SIZE-2);

	// Output the un-verified check number
	cout << crg_accNum << 'x' << endl;

	// Find the last check digit using luhn's algorithm
	luhn(crg_accNum, SIZE-2);

	// Output the result
	cout << crg_accNum << endl;

	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : char credict_card, const char SIZE
// PURPOSE   : generate a random credit card account number to test
//			   the luhn algorithm
//////////////////////////////////////////////////////////////////////
void genCCrd(char cc[], const char size) {
	for(int i=0;i<size;++i)
		cc[i] = rand()%10+48;
}

//////////////////////////////////////////////////////////////////////
// RETURN    : void
// PARAMETER : char credict_card, const char SIZE
// PURPOSE   : find the last check digit using the luhn Algorithm
//////////////////////////////////////////////////////////////////////
void luhn(char cc[], const char size) {
	char c_sum=0;

	for(int i=0;i<size;++i) {
		// double the value of every 2nd digit
		if(i%2!=0) {
			int i_val = (cc[i]-48)*2;
			// if doubling is > 9, sum the digits of the products
			cc[i] = ((i_val>=10) ? i_val-9 : i_val)+48;
		}
		c_sum += cc[i]-48;
	}
	// compute and store the last digit(x) 
	cc[size] = (c_sum*9)%10+48;
	// put the null terminator at the end
	cc[size+1] = '\0';
}
