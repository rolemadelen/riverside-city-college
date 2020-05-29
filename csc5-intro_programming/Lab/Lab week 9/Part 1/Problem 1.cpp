/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab week 9 - problem 1
*/

// Write a program that reads sentences from the
// user through the console, and prints the sentences
// to a file called output.dat. The user should be
// allowed to wrtie as many sentences as they wish
// until they write the symbol'@'

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Write anything you want. When you are done, \n"
         << "put '@' at the end of your sentence.\n\n";

    //declare ifstream
    //open file "output.dat"
    ofstream input("output.dat");

    //get string, sentece;
    string sentence;
    char c = ' ';
    cout << ": ";
    //continue until they input @
    while(sentence != "@")
    {
        cin >> sentence;
        int at = sentence.find('@');

        for(int i = 0; i < at; i ++)
        {
            input << sentence[i];
        }
    }
    //close file
    input.close();

}
