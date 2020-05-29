/*
	Author: Jiwon Yoo
	File: main.c

	Generate a valid credit card account number,
	loop 10,000 times and record how many valid vs. invalid CC detected.
*/

// System Libraries
#include <stdio.h>
#include <stdlib.h>	// srand
#include <time.h>	// time()

// Symbolic Constants
#define LOOP 100000
#define PRINTCC(x) printf("CARDTYPE: %s\n",x)

// User defined types
typedef enum { 
	AMEX,MASTER,VISA, DISCVR
} CrdCard_t; 

typedef enum {
	FALSE, TRUE
} bool;

// Function Prototypes
char * genCC( CrdCard_t );// generate a valid CC # using the Luhn
void luhn( char *, const int, const int );// luhn algorithm
void flipDig( char *, const int, const int );// randomly flips only 1 digit
bool validCC( char *, const int );// deteremines if the result in a valid

// Execution begins here
int main(int argc, char **argv) {
	// seed the random generator
	unsigned seed = time(0);
	srand(seed);

	// Declare Variables
	int valid=0, invalid=0;
	int cards[4] = {0};
	for(int i=0;i<LOOP;++i) {
		char *cp_accNum;
		CrdCard_t card = (CrdCard_t)(rand()%4);
		const int SIZE = (card==AMEX)?15:16;
		
		// generate a valid CC number 
		cp_accNum = genCC( card );
		switch( card ) {
			case AMEX: cards[0]++;break;//PRINTCC("AMERICAN EXPRESS"); break;
			case MASTER: cards[1]++;break;//PRINTCC("MASTER"); break;
			case VISA: cards[2]++;break;//PRINTCC("VISA"); break;
			case DISCVR: cards[3]++;//PRINTCC("DISCOVER");
		}

		// count valid and invalid
		if( validCC(cp_accNum,SIZE) ) valid++;
		else invalid++;

		// Deallocate the memory
		free(cp_accNum);
	}
	float sum=valid+invalid;
	printf("AMEX:     %d\nMASTER:   %d\nVISA:     %d\nDISCOVER: %d\n",
			cards[0],cards[1], cards[2], cards[3]);
	printf("VALID:   %d\t%.2f%%\n", valid,100*valid/sum);
	printf("INVALID: %d\t%.2f%%\n", invalid,100*invalid/sum);
	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN         : char *
// PARAMETER      :	enum CrdCard_t
// PRE-CONDITION  :	-
// POST_CONDITION : A valid CC is created to test for the validity
//////////////////////////////////////////////////////////////////////
char * genCC( CrdCard_t card) {
	const int SIZE = (card==AMEX)?15:16;
	char *cp = (char *)malloc( sizeof(char)*SIZE );
	int begin=0;
	// Credit Card Number is dependent on the Card Type
	switch( card ) {
			// Amex starts with 34 or 37
			case AMEX: {
				cp[0]=3+'0';
				cp[1]=((rand()%2==0)?4+'0':7+'0'); 
				begin=2;break;
			}
			// Master starts with 5
			case MASTER: {
				cp[0]=5+'0';
				begin=1; break;
			}
			// Visa starts with 4
			case VISA: {
				cp[0]=4+'0';
				begin=1; break;
			}
			case DISCVR: {
				cp[0]=6+'0';
				cp[1]='0';
				cp[2]=1+'0';
				cp[3]=1+'0';
				begin=4;
			}
		} 

	for(int i=begin;i<SIZE;++i)
		*(cp+i) = (rand()%10)+'0';
	
	// use luhn algorithm to generate a valid CC #
	luhn(cp, begin, SIZE);
	
	// filp digit
	flipDig(cp, begin, SIZE);

	return cp;
}

//////////////////////////////////////////////////////////////////////
// RETURN         :	void
// PARAMETER      :	char *, const int, const int
// PRE-CONDITION  :	dynamically allocated array exists
// POST_CONDITION :	using Luhn's, a valid Credit Card # is generated
//////////////////////////////////////////////////////////////////////
void luhn( char *cp, const int begin, const int SIZE ) {
	int sum=0;
	for(int i=SIZE-2;i>=begin;--i) {
		if(i%2==0) {
			int val = (cp[i]-48)*2;
			cp[i] = (val<10)?val+48:val+39;
		}
		sum += cp[i]-48;
	}
	cp[SIZE-1] = (sum*9)%10+48;
}

//////////////////////////////////////////////////////////////////////
// RETURN         :	void
// PARAMETER      :	char *, const int, const int
// PRE-CONDITION  :	valid Credit Card # is stored dynamically at 'cp'
// POST_CONDITION :	one random digit is flipped
//////////////////////////////////////////////////////////////////////
void flipDig( char *cp, const int begin, const int SIZE ) {
	int pos = (rand()%SIZE-begin)+begin;
	int val = ((pos+1)%2==0)?(cp[pos]-48)*2:cp[pos]-48;
	cp[pos] = (val<10)?val+48:val+39;
	return;
}

//////////////////////////////////////////////////////////////////////
// RETURN         :	bool
// PARAMETER      :	char *, const int
// PRE-CONDITION  :	Credit Card # exists
// POST_CONDITION : return TRUE if Credit Card is valid else FALSE
//////////////////////////////////////////////////////////////////////
bool validCC( char *cp, const int SIZE ) {
	int sum=0;
	bool valid=FALSE;
	for(int i=0;i<SIZE;++i) {
		sum += cp[i]-48;
	}
	valid = (sum%10)?FALSE:TRUE;
	return valid;
}
