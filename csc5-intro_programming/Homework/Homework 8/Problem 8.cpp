/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homework 8  - #8
* I certify this is my own work and code.
*/

//Write a program that creates two parallel vectors
//representing the name of the person, and the plane
//ticket ID of the corresponding person.
//The program should allow the user to enter a new name,
//of which the user is then provided with a new random
//ticket ID number between 1- 40.

#include <iostream>
#include <iomanip>
#include <vector> //vector
#include <string> //name
#include <ctime> //srand, Ticket ID

using namespace std;

/*
* Purpose of this function is to get name and Ticket ID.
* Prompt user to enter a name store it to nameVector and
* create a corresponding ticket ID.
*
* parameter : name vector and ticket ID vector
*
* return type is void
*/
void getNameId(vector<string>& name, vector<int>& id);

/*
* ticketId produces a number btwn 1~40;
*
* parameter is ticket ID vector
*
* return type is void
*/
void ticketId(vector<int>& id);

int main()
{
	srand(unsigned int(time(NULL)));

	//create a vector: represents Name
	vector<string> nameVec;
	
	//create a vector : represents Ticket ID
	vector<int> ticketVec;

	cout << "To quit, enter any number or JUST press enter.\n\n";

	while(ticketVec.size() < 40)
	{
		//function that get user name and produce ID
		getNameId(nameVec,ticketVec);
	}

		return 0;
}

void getNameId(vector<string>& name, vector<int>& id)
{
	cout << "Enter a name.\n: ";
	string userName;
	getline(cin,userName);

	char singleStr = userName[0];
	if(isalpha(singleStr))
	{
		name.push_back(userName);
		ticketId(id);

		cout << setw(10) << "NAME" << setw(20) << "TICKET ID" << endl;
		cout << setw(50) << setfill('=') << " " << setfill(' ') << endl;

		for(unsigned int i = 0; i < name.size(); i++)
		{
			cout << setw(11) << name[i] << setw(16) << id[i] << endl;
		}
	}
	else
	{
		cout << "Program terminates.\n";
		exit(1);
	}

}

void ticketId(vector<int>& id)
{
	int exist = -1;

	int ticketNum = (rand() % 40) + 1;
	
	//check if same Ticket ID exist
	for(unsigned int i = 0; i < id.size(); i++)
	{
		if(id[i] == ticketNum)
		{
			exist = 1;
		}
	}

	//if number alreadt exist call function again
	//to get new randNum
	if(exist != -1)
	{
		ticketId(id);
	}
	else
		id.push_back(ticketNum);
}