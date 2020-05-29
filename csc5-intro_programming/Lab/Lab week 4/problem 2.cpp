//Jiwon Yoo
//Professor Ung
//CSC5 - C++ Programming
//Lab Week4 Problem 2

/*
Write a program that inputs an integer for n, iterates through the
Babylonian algorithm until guess is within 1% of the previous guess
and outputs the answer as a double.
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    // get a number 'n' to compute the square root of it.
    double number;
     do
    {
    cout << "Enter a number that you want to find square root of.\n> ";
    cin >> number;
    }while(number < 3);

    // iterate until 'guess' is within 1% of the previous guess.
        //step 1 : make a guess at the answer (you can pick number/2 as your initial guess.)
        double guess = number / 2.0;
        double oldGuess;
        double subtract;

        do
        {
            //step 2 : compute root = number / guess
            double root = number / guess;
            oldGuess = guess;

            //step 3 : set guess = (guess + root ) / 2
            guess = (guess + root) / 2.0;
            subtract = oldGuess - guess;

        }while(subtract > oldGuess * 0.01);

    // outputs the 'answer' as a double.
    double answer = guess;
	cout << fixed << showpoint  << setprecision(5);
    cout << "A square root of " << number << " is " << answer << "." << endl;
    cout << answer << " X " << answer << " = "  << answer * answer << ". check!" << endl;

    return 0;
}

