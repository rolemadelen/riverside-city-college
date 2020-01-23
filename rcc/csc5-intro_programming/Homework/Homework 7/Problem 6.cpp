/*
* Jiwon Yoo
* Student ID : 2485776
* Novemmber 5, 2013.
* Professor Ung
* HW7 - problem 6
* I certify this is my own work and code!
*/

////////////////////////////////////////////////////////////
//Write a program that merges the numbers in two files
//and write all the numbers into a third file.
//Your program takes input from two different files
//and writes its output to a third file.
//Each input contains a list of numbers of type int,
//and the numbers are in sorted order. After the program is run,
//the third file should contain the merged set of numbers
//in sorted order (smallest to largest).
//
//Name the input files “data1.dat” and “data2.dat”,
//while the file to be written to can be called “out.dat”.
//This program should have a function that has two input file
//streams and one output file stream as arguments.
/////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/*
* Purpose: this function reads in
* two diff. integer files and outputs
* to third file called "out.dat";
*
* Paramter: two input file streams and
* one output file stream

* pseudo-returns
*/
void thirdFile(ifstream &infile,
			 ifstream &infile2, ofstream &outfile);
int main()
{
	//get input from two diff. files(ifstream)
	//output to a third file.(ofstream)
	ifstream infile1;
	ifstream infile2;
	ofstream outfile;
	
	infile1.open("data1.dat");
	infile2.open("data2.dat");
	outfile.open("outfile.dat", ios::app);

	if(!infile1 || !infile2)
		cout << "No such file.\n";

	//rewrite it to third file using function.
	thirdFile(infile1, infile2, outfile);
}

void thirdFile(ifstream &infile,
			 ifstream &infile2, ofstream &outfile)
{
	string word;
	int cnt = 0;

	while(infile >> word)
	{
		outfile << word << " ";
	}
}
