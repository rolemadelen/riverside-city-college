////Jiwon Yoo
////2013, September 3. Week 2
//// Lab Worksheet problem 03
////Write a program that reads in an integer between 1 and 10000.
////Then, have the console display each digit followed by a space.
////For example, if I were to enter 12345, the terminal would show:
////1 2 3 4 5
////hint uses ampersand
//
#include <iostream>
using namespace std;
int main()
{
    //declare and initialize a variable
    int number =  0;
    int first = 0,second = 0,
        third = 0, fourth = 0, fifth = 0; //without Ampersand
	int first_amp = 0, second_amp = 0,
		third_amp = 0, fourth_amp = 0, fifth_amp = 0; // Ampersand 
    
    //prompt the user to enter an integer
    cout << "Enter a number between 1 ~ 10000." << endl;
    
    // get number
    cin >> number;
    
    //using the idea of Ampersand
    first = number / 10000;  
    second = (number - (first * 10000)) / 1000;
    third = ((number - (first * 10000)) - (second * 1000))/100;
    fourth = ((number - (first * 10000)) - (second * 1000) - (third * 100)) / 10;
    fifth = ((number - (first * 10000)) - (second * 1000) - (third * 100) - (fourth * 10));

	//using Ampersand
	first_amp = number % 10;
	second_amp = (number % 100) / 10;
	third_amp = (number % 1000) / 100;
	fourth_amp = (number % 10000) / 1000;
	fifth_amp = (number / 10000);
	
    // output number followed by a number
	cout << "Without using Modulus operator\n";
    cout << first << " " << second << " " << third << " " << fourth << " " << fifth <<endl << endl;
	cout << "With Modulus operator\n";
	cout << fifth_amp << " " << fourth_amp << " " << third_amp << " " << second_amp << " " << first_amp << " \n";
    
    return 0;
}
