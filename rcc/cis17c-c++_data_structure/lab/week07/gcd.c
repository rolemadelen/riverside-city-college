/*
	Author: Jiwon Yoo
	Purpose: Greatest Common Denominator
	Date : March 30, 2016
*/

// System Libraries
#include <stdio.h>

// Function Prototypes
int gcd(int, int);

// Execution begins here
int main() {
	// Test out the Greatest Common Denominator
	int num = 24; // numerator
	int denom = 54; // denominator
	int fact = gcd(num, denom);
	printf("GCD: %d\n%d/%d = %d/%d\n", 
			fact, num,denom,num/fact,denom/fact);

	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : int
// PRE-CONDITION : 
// POST-CONDITION:
// PURPOSE       : find GCD of m and n
//////////////////////////////////////////////////////////////////////
int gcd(int m, int n) {
	return ( n==0 )?m:
		   ( m%n==0 )?n:
		   ( m>n )?gcd(n, m%n):gcd(m, n%m);
}
