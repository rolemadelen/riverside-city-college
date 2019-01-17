/*
* Jiwon Yoo
* Professor Ung
* Lab 11 - problem 5
*/

//Create a text file called “broken.dat” where not all
//the names have a last or first name.
//Names that do not have a first name are written with
//a space before the last name. 
//First names with no last name are written with no
//last name. Modify program 5 to accommodate this error.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//output both first and last name in vectors
void output(vector<string>& fName, vector<string>& lName);

int main()
{
	ifstream infile("broken.txt");
	string name;
	vector<string> fName;
	vector<string> lName;

	if(!infile)
	{
		cout << "No such file.\n";
		return 0;
	}

	while(getline(infile,name))
	{
		if(name[0] == ' ')
		{
			lName.push_back(name);
		}
		else
			fName.push_back(name);
		
	}

	output(fName,lName);
}

void output(vector<string>& fName, vector<string>& lName)
{
	cout << "FIRST NAME\t LAST NAME\n\n";
	for(int i = 0; i < fName.size(); i++)
	{
		cout << fName[i] << "\t\t " << lName[i] << endl;
	}
}