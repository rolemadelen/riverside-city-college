/*
* Jiwon Yoo
* Student ID : 2485776
* Novemmber 4, 2013.
* Professor Ung
* HW7 - problem 3
* I certify this is my own work and code!!
*/

//Modify number 2 to calculate and print the number
//of even numbers that the file contains.
//Create three different files that contain zero, some,
//and all even numbers.Name the files “data1.dat”,
//“data2.dat”, “data3.dat”.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

//get fileName
//parameter: ifstream - use file name
//pseudo-return
void getFile(ifstream &infile);

//get evens from a file
//paramter : ifstream - get file name
//pseudo-returns
void getEven(ifstream &infile);

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
	//get even and output
	getEven(infile);

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

void getEven(ifstream &infile)
{
	string word;
	int num, cnt = 0;
	
	cout << "Even numbers on file.\n"
		<< "========================\n";
	while(infile >> word)
	{
		num = atoi(word.c_str());
		if(num % 2 == 0)
		{
			cout << left << setw(3) << num << " ";
			cnt ++;
			if(cnt % 5 == 0)
				cout << endl;
		}
	}
	cout << "\n========================\n";
}