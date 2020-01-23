/*
* Jiwon Yoo
* Student ID : 2485776
* Novemmber 4, 2013.
* Professor Ung
* HW7 - problem 1
* I certify this is my own work and code!!
*/

// Write a program that will search a file of numbers of type int
// and write the largest and the smallest numbers to the screen.
// The file contains nothing but numbers of type int separate
// by blanks or line breaks. Call the file “data.dat”.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//get fileName
void getFile(ifstream &infile);

//compare and find largest and smallest number.
//parameter : three reference type variable
//pseudo-returns
void compare(string &word, int &large, int &small);

int main()
{
	//used to open a integer value file
	ifstream infile;
	int large = 1, small = 1;
	string word;


	//open file
	infile.open("data.dat");

	//if no file, output
	if(!infile)
	{
		cout << "No such file..\n";
	}
	//otherwise continue process
	else
	{ 
		while(infile >> word)
		{
			compare(word,large,small);
		}
		cout << "Largest number on file : " << large <<  endl;
		cout << "Smallest number on file : " << small << endl;

		//close file
		infile.close();
	}

	return 0;
}

void compare(string &word, int &large, int &small)
{
	int temp = atoi(word.c_str());

	if(large <= temp)
		large = temp;
	else
		large = large;

	if(small > temp)
		small = temp;
	else
		small = small;
}
