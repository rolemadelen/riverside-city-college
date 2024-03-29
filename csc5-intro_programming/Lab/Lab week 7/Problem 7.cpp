/*
* Jiwon Yoo
* Professor Ung
* CSC5 Lab 7 - problem 7
*/

// Create a simple Palindrome checker program.
// The program should allow the user to enter a string
// and check whether the given string is a palindrome or not.
// Only digits and alphabets should be considered while
// checking for palindromes -- any other characters are
// to be ignored. The palindrome check should be created as a function.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//this function determine whether two strings are equal or not.
//parameters : two string data.
//return type is boolean.
bool checkPal(string str1, string str2);

//this function gets the word from a user.
//parameter is none.
//return type is string.
string getWord();
int main()
{
    cout << "Palindrome Program.\n\n";
    cout << "If the word is a palindrome, the program\n"
         << "will output YES else NO...\n"
         << "Only English with no spaces in between..\n\n"
         << "Enter 'exit' to quit.\n\n";

    while(true)
    {
        string word;       // inputted by the user
        string wordholder = ""; // 뒤에서부터 store 할 string.
        int size;
         
        // get a word from the user;
		//exit game if string == exit
        word = getWord();

		if(checkPal(word,wordholder))
			cout << "Palindrome : YES." << endl << endl;
		else
			cout << "Palindrome : NO\a." << endl << endl;	        
    }
}
bool checkPal(string word, string wordholder)
{
	// get the length of word;
    // s.size();
    int size = word.size();
	
	//loop
    // store a letter from the back and see if it's a palindrome.
    for(int j = 0; j < size; j ++)
    {
        //make everything capital
        //in case the user inputted 'Level' or 'LevEl'
        char cap = word[j];
        cap = toupper(cap);
        word[j] = cap;

    }
    for(int i = size; i > 0; i --)
    {
        //make everything capital
        //in case the user inputted capital letter
        char cap = word[i - 1];
        cap = toupper(cap);
        wordholder = wordholder + cap;
            
    //loop end
    }
    return (word == wordholder);
  
}

string getWord()
{
	string str;

	cout << "Enter a word : ";
	cin >> str;
	if(str == "exit")
		exit(1);
	return str;
}