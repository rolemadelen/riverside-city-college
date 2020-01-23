/*
* Jiwon Yoo
* Professor Ung
* Lab 6 - problem 4
*/

// write a program that reads strings from a file,
// and counts how many characters there are in all 
// of the strings. The program should indicate the 
// total number of characters. This program should
// invoke the function used in probelm 3

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int size(string word)
{
	return word.size();
}

int main()
{
	fstream infile;
	string word;
	int length = 0;
	
	infile.open("test2.txt");

	while(infile >> word)
	{
		//cout << word << endl;
		length = length + size(word);
	}
	infile.close();
	cout << "length : " << length << endl;
	return 0;
}