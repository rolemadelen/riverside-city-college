/*
* Jiwon Yoo
* Professor Ung
* Lab 11 - problem 5
*/

//Write two parallel vectors that store the
//first name and last names of people.
//Read in the names from a file called
//“names.dat”, and store the last name and
//first name appropriately.

/*
1) declare file and 2 vector
2) open file
3) read in file
4) store characters to string until white space.
5) store that string to appropriate vector.
	- first word is first name (odd)
	- second word is last name (even)

*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//output first and last name
void output(vector<string>& fName, vector<string>& lName);

int main()
{
	//declare vars
	ifstream infile;
	vector<string> fName;
	vector<string> lName;
	string name;
	int cnt = 1;

	//open name file
	infile.open("name.dat");
	
	//if file DNE, output no file
	if(!infile)
	{
		cout << "no such file...\n";
		return 0;
	}

	//while file exist, read all char's.
	while(infile  >> name)
	{
		//if cnt is odd, fName;
		if(cnt % 2 != 0)
			fName.push_back(name);
		//otherwise Last name.
		else
			lName.push_back(name);

		cnt++;	
	}

	infile.close();

	output(fName,lName);
	return 0;
}

void output(vector<string>& fName, vector<string>& lName)
{
	cout << "FIRST NAME\t LAST NAME\n\n";
	for(int i = 0; i < fName.size(); i++)
	{
		cout << fName[i] << "\t\t " << lName[i] << endl;
	}
}