/*
	Author: Jiwon Yoo
	Purpose: Mutual Recursion
	Date : March 30, 2016
*/

// System Libraries
#include <stdio.h>
#include <cmath>
using namespace std;

// Global Constants
const float PID4 = atan(1);

// Function Prototypes
float rSin(float);
float rCos(float);

// Execution begins here
int main() {
	// Test the recursive Sine and cosine
	float angle = 30;
	printf("The angle in degrees: %f\n", angle);
	angle = angle*PID4/45;
	float aprxSin = rSin(angle);
	float aprxCos = rCos(angle);
	printf("The rCos(%f) = %f\n",angle,aprxCos);
	printf("The rSin(%f) = %f\n",angle,aprxSin);
	printf("The Cos(%f) = %f\n",angle,cos(angle));
	printf("The Sin(%f) = %f\n",angle,sin(angle));
	
	return 0;
}

//////////////////////////////////////////////////////////////////////
// RETURN        : float
// PRE-CONDITION : 
// POST-CONDITION:
// PURPOSE       : find GCD of m and n
//////////////////////////////////////////////////////////////////////
float rSin(float angle) {
	if( abs(angle)<1e-3f) return (angle-(angle*angle*angle)/6);
	return 2*rSin(angle/2)*rCos(angle/2);
}

float rCos(float angle) {
	if( abs(angle)<1e-3f) return (1-(angle*angle)/2);
	float b = rSin(angle/2);
	return 1-2*b*b;
}
