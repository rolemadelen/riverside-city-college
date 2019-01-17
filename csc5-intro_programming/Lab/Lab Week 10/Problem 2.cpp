/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 10 - problem 2
*/

//Modify program one to store values into
//an array instead of a vector.

#include <iostream>
#include <fstream> //get file
#include <string> //get file name
#include <cstdlib> //atoi function
#include <iomanip>

using namespace std;

void getFile(ifstream &infile);

int main()
{
	//declare array to store a file data
	int number[100];

	//declare string for file name
	string word;
	string outputWord; //output file data

	//declare input file stream
	ifstream infile;

	//get file
	cout << "Enter a file name.\n> ";
	cin >> word;

	//open file
	infile.open(word.c_str());

	//if file DNE
	if(infile.fail())
	{
		//error checking
		cout << "No such file\n";
		getFile(infile);
	}

	//otheriwse
	//store values into an array
	int cnt = 0;
	while(infile >> outputWord)
	{
		int num;
		//change string to integer
		num = atoi(outputWord.c_str());
		number[cnt] = num;
		cnt ++;
	}
	//close file
	infile.close();

	//output array integers
	for(int i = 0; i < cnt; i ++)
	{
		cout << left;
		cout << "array [" << setw(2) << i << "]: "
			<< setw(5) << number[i] << endl;
	}
}

void getFile(ifstream &infile)
{
	//declare string for new file name
	string word;
	
	//close opened file and open new one
	infile.close();

	///prompt user to enter new file name
	cout << "\nEnter different file name.\n> ";

	//get file name
	cin >> word;

	//open new file
	infile.open(word.c_str());

	//while new file DNE
	//repear the process of asking for a new file
	while(infile.fail())
	{
		//recursion of function getFile
		getFile(infile);
	}
}