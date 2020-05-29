/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* HW9 - Problem 1
* I certify this is my own work and code.
*/

/*
* Write a program that will read a line of
* text and output a list of all the letters
* that occur in the text together with the
* number of times each letter occurs in the line.
* End the line with a period that serves as a
* sentinel value. The letters should be listed
* in the following order:
* the most frequently occurring letter,
* the next most frequently occurring letter,
* and so forth.
* You may use either arrays or vectors to store
* both the integers and the letters.
* You may assume that the input uses all lower
* case letters, and all the characters are valid.
*/


/*
let's use file I/O..
Step:
1) get a line of a text.
	- period(.) = sentinel value.
2) output to file (make all lowercase)
3) read from a file character by character
4) store it to vector
5) sort alphabets a~z
6) remove all repeated letters
   and store it to new Vector,
   so new vector will have bunch of single
   alphabets.
7) compare new vector with old vector and
	count how many same letters have been used.
*/
#include <iostream>
#include <fstream> //file I/O
#include <vector> //vector
#include <cctype> //tolower();

using namespace std;

/*
* readFile function reads in a line of a text
* from a file "data.dat" and store it to vector
*
* parameter : ifstream
*
* return type is vector<char>
*/
vector<char> readFile(ifstream& infile);

/*
* sortAlpha function sorts letter alphabetically.
*
* parameter : non-ordered vector
*
* return type is void
*/
void sortAlpha(vector<char>& v);

//output all characters in vector
//parameter : vector
//pseudo-returns.
void output(vector<char>& v);

/*
* delete_repeats function remove all repeated
* letters inside vector and store it to newVector
*
* parameter : sorted vector
*
* return type is vector<char>
*/
vector<char> delete_repeats(vector<char>& v);

/*
* countRep function outputs a list of all the letters
* that occur in the text together with the
* number of times each letter occurs in the line.
*
* parameter : sorted old vector that contains repeats
			  and new sorted vector that does not
			  contain repeats.
*
* pseudo-returns;
*/
void countRep(vector<char>& oldVec, vector<char>& newVec);

int main()
{
	//file that will store a line of a text
	ofstream outfile;
	ifstream infile;
	outfile.open("data.dat");

	//used to get line of a text
	char line;
	
	cout << "Enter a line of a text.\n"
		<< "Place period(.) after you're done.\n\n> ";
	
	//step 1:
	//if infile exist, get line of atext
	while(outfile)
	{
		//get until user enters period(.)
		cin >> line;

		//step 2:
		//output to a file if and only if
		//character is letter(a~z/A~Z).
		if(isalpha(line))
		{
			//change upper case to lower case
			char lowerLine = tolower(line);
			outfile << lowerLine;
		}
		else if(line == '.')
			break;
	}
	cout << endl << " Letter\t\tNumber of Occurence.\n";
	outfile.close();

	//step 3: 
	//read from a file char by char.
	//vector that include all the characters
	vector<char> oldAlpha;
	oldAlpha = readFile(infile);

	//cout << "BEFORE SORTING\n";
	//output(oldAlpha);

	//step 5: sort (a~z)
	sortAlpha(oldAlpha);

	//cout << "AFTER SORTING\n";
	//output(oldAlpha);

	//step 6: 
	//remove all repeated letters
	//and store it to new Vector
	vector<char> newAlpha;

	newAlpha = delete_repeats(oldAlpha);

	//cout << "AFTER DELETE_REPEATS.\n";
	//output(newAlpha);

	//step 7:
	countRep(oldAlpha,newAlpha);
	return 0;
}

vector<char> readFile(ifstream& infile)
{
	//store each letter
	vector<char> v;
	
	//get a letter from a file
	char ch;

	//open file that stored user's line
	infile.open("data.dat");

	//step 4:
	//store each char to vector
	while(infile >> ch)
	{
		v.push_back(ch);
	}

	return v;
}

void sortAlpha(vector<char>& v)
{
	for(unsigned int i = 0; i < v.size()-1; i++)
	{
		for(unsigned int j = 0; j < v.size()-1; j++)
		{
			//if 1st char is > than 2nd char, swap
			if(v[j] > v[j+1])
				swap(v[j],v[j+1]);
		}
	}
}

vector<char> delete_repeats(vector<char>& v)
{
	int repeat;
	vector<char> newV = v;

	for(unsigned int i = 0; i < newV.size(); i++)
	{
		for(unsigned int j = newV.size()-1; j > i; j--)
		{
			if(newV[j] == newV[i])
			{
				repeat = j;
				//if found repeated letter
				//move to very end and pop_back;
				for(unsigned int k = repeat; k < newV.size()-1; k++)
				{
					newV[k] = newV[k+1];
				}
				newV.pop_back();
			}
		}
	}
	return newV;
}

void output(vector<char>& v)
{
	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << "Vector[" << i << "]: "
			<< v[i] << endl;
	}

	cout << endl << endl;
}

void countRep(vector<char>& oldVec, vector<char>& newVec)
{
	int cnt;
	vector<int> order;

	//count number of occurence
	for(unsigned int i = 0; i < newVec.size(); i++)
	{
		cnt = 0;
		for(unsigned int j = 0; j < oldVec.size(); j++)
		{
			if(newVec[i] == oldVec[j])
				cnt ++;
		}
		order.push_back(cnt);
	}

	//sort order highest to lowest
	for(unsigned int k = 0; k < newVec.size()-1; k++)
	{
		for(unsigned int l = 0; l < newVec.size()-1; l++)
		{
			if(order[l] < order[l+1])
			{
				swap(order[l],order[l+1]);
				swap(newVec[l],newVec[l+1]);
			}
		}
	}
	
	//output
	for(unsigned int m = 0; m < order.size(); m++)
	{
		cout << "   " << newVec[m] << "\t\t\t"
				<< order[m] << endl;
	}
}