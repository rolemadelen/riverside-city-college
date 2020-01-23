/*
* Jiwon Yoo
* Student ID : 2485776
* Novemmber 4, 2013.
* Professor Ung
* HW7 - problem 2
* I certify this is my own work and code!!
*/

//Implement number 1 where the file name is
// received from the user. Make sure to do
//error checking on the file itself.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//get fileName
//parameter: ifstream - use file name
//pseudo-return
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
	char file[20];


	//open file
	cout << "enter a file name : ";
	cin.getline(file,20);

	infile.open(file);

	//if no file, output
	if(!infile)
	{
		cout << "No such file..\n";
		getFile(infile);
	}
	//otherwise continue process
	while(infile >> word)
	{
		compare(word,large,small);
	}
	cout << "Largest number on file : " << large <<  endl;
	cout << "Smallest number on file : " << small << endl;

	//close file
	infile.close();

	return 0;
}

void getFile(ifstream &infile)
{
	//close current file
	infile.close();

	char name[20];
	string word;
	int large = 1, small = 1;

	//get different file
	cout << "Enter a different file name: ";
	cin.getline(name,20);
	
	//open file
	infile.open(name);
	
	//ask for another file, if user input wrong file name
	while(!infile)
	{
		infile.close();

		cout << "Different one : ";
		cin.getline(name,20);
		infile.open(name);
	}

}

void compare(string &word, int &large, int &small)
{
	int temp = atoi(word.c_str());

	//if large number is <= fileNumber
	//large = fileNumber
	if(large <= temp)
		large = temp;
	//otherwise large = large
	else
		large = large;

	//if small number is > fileNumber
	//small = small(fileNumber);
	if(small > temp)
		small = temp;
	//otherwise small = small;
	else
		small = small;
}
