//Jiwon Yoo
//Lab 3  week 2 part 2
//problem 3
// Write a program that prompts the user to take in 3 test
// scores and outputs the average score.

#include <iostream>
using namespace std;

int main()
{
    int score1 = 0, score2 = 0, score3 = 0, total = 0;
    double average = 0.0;
    
    // get three test scores
    cout << "Enter first test score: ";
    cin >> score1;
    total += score1;
    
    cout << "Enter second test score: ";
    cin >> score2;
    total += score2;
    
    cout << "Enter third test score: ";
    cin >> score3;
    total += score3;
    
    // output the average
    average = static_cast<double>(total) / 3;
    cout << "Your average is " << average << endl;
    
    return 0;
}