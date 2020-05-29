/*
	@Author: Jiwon Yoo
	Date: 1 June 2016
*/

// System Libraries
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// User Libraries
#include "GeneralHashFunctions.h"

string toStr(unsigned, unsigned);
int main(int argc, char **argv) {
	// four keys to hash	
	string L[5];
	L[1] = "Then out spake brake Horatius, The Captain of the Gate:";
	L[2] = "To every man upon this earth Death cometh soon or late.";
	L[3] = "And how can man die better Than facing fearful odds,";
	L[4] = "For the ashes of his fathers, \
				And the temples of his Gods.";

	// Declare Variables
	const int SIZE2=2, SIZE3=4;
	unsigned topHash; // concatenation of _2ndHash
	unsigned _2ndHash[SIZE2]; // concatenation of _3rdHash
	unsigned _3rdHash[SIZE3]; // hash values of L blocks

	// Hash values of L blocks
	for(int i=0;i<SIZE3;++i) _3rdHash[i] = RSHash(L[i+1]);
	cout << "Hash 0-0: " << _3rdHash[0] << endl;
	cout << "Hash 0-1: " << _3rdHash[1] << endl;
	cout << "Hash 1-0: " << _3rdHash[2] << endl;
	cout << "Hash 1-1: " << _3rdHash[3] << endl;

	// concatenate Hash 0-0,0-1 and 1-0,1-1 to get Hash 0 and Hash 1
	string temp = toStr(_3rdHash[0], _3rdHash[1]);
	_2ndHash[0] = RSHash(temp);
	temp = toStr(_3rdHash[2], _3rdHash[3]);
	_2ndHash[1] = RSHash(temp);
	cout << "Hash 0: " << _2ndHash[0] << endl;
	cout << "Hash 1: " << _2ndHash[1] << endl;

	// concatenate hash 0 and hash 1 to get the top hash
	temp = toStr(_2ndHash[0], _2ndHash[1]);
	topHash = RSHash(temp);
	cout << "Top Hash: " << topHash << endl;

	// check L1 = 0-1,1, top
	cout << "===================check L1 is 0-1,0,top" << endl;
	unsigned hashL1 = RSHash(L[1]);
	temp=toStr(hashL1, _3rdHash[1]);
	unsigned hash0 = RSHash(temp);
	temp=toStr(hash0,_2ndHash[1]);
	unsigned checkTop = RSHash(temp);
	cout << "checkTopHash     : " << checkTop << endl; 
	cout << "original Top Hash: " << topHash << endl;
	
	cout << "===================check L2 is 0-0,1,top" << endl;
	unsigned hashL2 = RSHash(L[2]);
	temp=toStr(_3rdHash[0],hashL2);
	hash0 = RSHash(temp);
	temp=toStr(hash0, _2ndHash[1]);
	checkTop = RSHash(temp);
	cout << "checkTopHash     : " << checkTop << endl; 
	cout << "original Top Hash: " << topHash << endl;

	cout << "===================check L3 is 1-1,0,top" << endl;
	unsigned hashL3 = RSHash(L[3]);
	temp = toStr(hashL3, _3rdHash[3]);
	unsigned hash1 = RSHash(temp);
	temp = toStr(_2ndHash[0], hash1);
	checkTop = RSHash(temp);
	cout << "checkTopHash     : " << checkTop << endl; 
	cout << "original Top Hash: " << topHash << endl;

	cout << "===================check L4 1-0,0,top" << endl;
	unsigned hashL4 = RSHash(L[4]);
	temp = toStr(_3rdHash[2],hashL4);
	hash1 = RSHash(temp);
	temp = toStr(_2ndHash[0], hash1);
	checkTop = RSHash(temp);
	cout << "checkTopHash     : " << checkTop << endl; 
	cout << "original Top Hash: " << topHash << endl;
	return 0;
}

string toStr(unsigned a, unsigned b) {
	stringstream ss;
	string temp="";
	ss << a;
	ss << b;
	ss >> temp;
	ss.clear();
	return temp;
	
}
