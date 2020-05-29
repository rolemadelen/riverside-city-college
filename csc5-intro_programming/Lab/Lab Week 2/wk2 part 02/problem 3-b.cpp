//Jiwon Yoo
//Lab 3  week 2 part 2
//problem 3-b
// Write a program that prompts the user to take in 3 test
// scores and outputs the average score.

#include <iostream>
using namespace std;

int main()
{
    int score1 = 0, score2 = 0, score3 = 0, total = 0;
    double average = 0.0;
    
    // get three test scores
    cout << "Enter your three test scores with space in between.\n";
    cin >> score1 >> score2 >> score3;
    
    total = score1 + score2 + score3;
    
    // output the average
    average = static_cast<double>(total) / 3;
    cout << "Your average is " << average << endl;
    
    return 0;
}