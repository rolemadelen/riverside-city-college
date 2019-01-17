/*
	Author: Jiwon Yoo
	Purpose: Binomial Coefficient
	Date : March 30, 2016
*/

// System Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
int bcoeff(int, int);

// Execution begins here
int main() {
	// seed rand numbers
	unsigned seed = time(0);
	srand( seed );
	int l = rand()%20+1;

	// Create a Pascla Triangle
	for(int n=0;n<=l;++n) {
		for(int k=0;k<=n;++k)
			printf("%d ",bcoeff(n,k));
		printf("\n");
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : 
// POST-CONDITION:
// PURPOSE       : output nCk ( n!/((n-k)!k!)
//////////////////////////////////////////////////////////////////////
int bcoeff(int n, int k) {
	if( k==0 ) return 1;
	if( n==k ) return 1;
	return bcoeff(n-1, k-1) + bcoeff(n-1, k);
}
