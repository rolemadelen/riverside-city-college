/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 10 - problem 1
*/

//Write a program that reads a file from the user,
//performs the correct error checking, and stores
//the values in the file into a vector.
//Assume that the values are integers.

#include <iostream>
#include <vector> //store value in vector
#include <fstream> //get file
#include <string> //get file name
#include <cstdlib> //atoi function
#include <iomanip>

using namespace std;

int main()
{
	//declare vector to store a file data
	vector<int> v;

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
	}

	//otheriwse
	//store values into a vector
	while(infile >> outputWord)
	{
		int num;
		//change string to integer
		num = atoi(outputWord.c_str());
		v.push_back(num);
	}
	//close file
	infile.close();

	//just to check, output vector integers
	for(int i = 0; i < v.size(); i++)
	{
		cout << left;
		cout << "Vector [" << setw(2)<< i << "]: "
			 << setw(5) << v[i] << endl;
	}
}