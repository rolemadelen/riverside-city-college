//Jiwon Yoo
//2013, September 3. Week 2
// Lab Worksheet problem 01
//Write a program that outputs the following. 
//      Hello, my name is Hal!
//      What is your name?
//      Matthew           <------ user input
//      Hello, Matthew. I am glad to meet you.

#include <iostream>
using namespace std;

int main()
{
    // declare a data type string
    string name;
    
     // ask for name, prompt
    cout << "Hello, my name is Jiwon!" << endl;
    cout << "What is your name?" << endl;
    
    // get a name from the user
    cin >> name;
    
    // output name
    cout << "Hello, " << name << ". I am glad to meet you." << endl;
    
    return 0;
}