/*
* Jiwon Yoo
* Professor Ung
* CSC 5 Lab week 9  - problem 5
*/

// Write a program that read words from a file
// and converts all uppercase letters to lowercase letters.

//ifstream is like cin
//ofstream is like cout

#include <iostream> 
#include <fstream> //file I/O
#include <string> //string vairables
#include <cctype> //tolower

using namespace std;

//purpose of this function is to 
//convert all strings to lower
//parameter: one file name
//returns lowercase string
string convert(ifstream &infile);

int main()
{
	ifstream infile;
	ofstream outfile;
	string sentenceLower=" ";

    //open file
	infile.open("test2.txt");

    //call function to convert
	sentenceLower = convert(infile);
	
	//open ofstream file
	outfile.open("test2.txt");

	//write converted sentence to file.
	outfile << sentenceLower;

	//close ofstream file
	outfile.close();

    //close file
	infile.close();
}

string convert(ifstream &infile)
{
	string word, sentence = " ";
	int get;
	char wordc;
	
	//store words to string
	//use tolower function to make it lowercase
	while(infile >> word)
	{
		//get size of a word so that you can change
		//each character to lower case.
		get = word.size();
		for(int i=0; i<get; i++)
		{
			wordc = word[i];
			wordc = tolower(wordc); //convert to lowercase
			sentence += wordc;
			//every new word, add one empty space
			if(i == (get - 1))
			{
				sentence += " ";
			}
		}
	}
	cout << "...............................\n"
		 << "........Success Converting !!!\n";
	return sentence;
}
