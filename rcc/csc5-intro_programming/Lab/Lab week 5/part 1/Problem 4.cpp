/*
* Jiwon Yoo
* Professor Ung
* Lab 5 part 1 - problem 4
*/

// Write a program that reads in a string
// and determines if is a palindrome.
// Allow the user to enter as many times
// as they wish.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

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
        cout << "Enter a word : ";
        cin >> word;
        
        if(word == "exit")
        {
                cout << "That's it !!\n";
                return 0;
        }
        // get a length of word;
        // s.size();
        size = word.size();

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
        if(word == wordholder)
        {
        	cout << "Palindrome : YES." << endl << endl;
        }
        else
        {
        	cout << "Palindrome : NO\a." << endl << endl;
        }
    }
}
