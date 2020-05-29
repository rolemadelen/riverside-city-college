/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 9 part 1 - #4
*/

// Write a program that reads from a file as input
// by the user, and prints the contents to the screen.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
purpose of this function is to perform an error check;
Error check: If file name is wrong
             or file does not exist
             get new input.
parameter : file name.
*/
void getFile(ifstream &checkFile);

int main()
{
    //declare ofstream data type variable
    ifstream inFile;
    string fileName,word;

    //prompt
    cout << "Enter a file name with extension that you want to open : ";
    //get and output the contents of a file to the screen.

    cin >> fileName;

    //convert string to c_str()
    inFile.open(fileName.c_str());

    if(!inFile)
    {
        //error checking
        cout << "No such file...\n";
        getFile(inFile);
    }
    else
    {
        while(inFile >> word)
        {
            cout << word;
        }
    }
}

void getFile(ifstream &checkFile)
{
    string fileName,word;
    while(!checkFile)
    {

    checkFile.close();
    cout << "Enter different file name: ";
    cin >> fileName;
    checkFile.open(fileName.c_str());
        if(checkFile)
        {
            while(checkFile >> word)
            {
                cout << word;
            }
			cout << endl;
            return;
        }
    }
}
