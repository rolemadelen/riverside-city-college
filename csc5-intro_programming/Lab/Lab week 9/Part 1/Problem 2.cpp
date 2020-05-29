/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 9 - problem 2
*/

// Modify program 1 to user memeber function get.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Write anything you want. When you are done, \n"
		 << "put '@' at the end of your sentence.\n\n";

	//declare ifstream
	//open file "output.dat"
	ofstream input("output.dat");

	//get string, sentece;
	string sentence;
	char c = ' ';
	cout << ": ";
	//continue until they input @
	while(c != '@')
	{
		cin.get(c);
		input << c;
	}
	//close file
	input.close();
}