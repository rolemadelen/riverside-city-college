/*
* Jiwon Yoo
* Professor Ung
* Lab 6 - problem 3
*/

// Write a function that reads a string
// and returns the length of the string

#include <iostream>
#include <string>
using namespace std;

int size(string word)
{
	return word.size();
}

int main()
{
	string word;
	cout << "This program returns the"
		<< "length of the inputted string.\n\n";
	
	cout << "enter a word : ";
	getline(cin,word);
	
	cout << "The length of a word is : "
		 << size(word) << endl;
		 
	return 0;	
}