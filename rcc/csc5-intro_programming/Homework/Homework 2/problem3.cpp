/*
* Name: Jiwon Yoo
* Student ID: 2485776
* Date: Sept 10, 2013.
* HW: 2
* Problem: 3
* I certify this is my own work and code.
*/

// Create a program that receives 9 total scores, three for each person,
// and calculates the average of scores for each quiz. The program should
// output all values as indicated below.
// The averages have only two data points, and all numbers are right 
// justified to the center of the QUIZ output.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // declare integer for test scores;
    // declare double for average test scores;
    int score1_1 = 0, score1_2 = 0, score1_3 = 0,
        score2_1 = 0, score2_2 = 0, score2_3 = 0,
        score3_1 = 0, score3_2 = 0, score3_3 = 0;
    double ave1 = 0.0, ave2 = 0.0, ave3 = 0.0;
    string fname1, fname2, fname3;
 
    // get name1
    cout << "Enter first name of a student : ";
    cin >> fname1;
    
    // get name2
    cout << "Enter second student's name : ";
    cin >> fname2;
    
    // get name3
    cout << "Enter third student's name : ";
    cin >> fname3;
    
    // get three quiz scores for name1
    cout << "Enter " << fname1 << "'s three test scores.\n> ";
    cin >> score1_1 >> score1_2 >> score1_3;
    
 
    // get three quiz scores for name2
    cout << "Enter " << fname2 << "'s three test scores.\n> ";
    cin >> score2_1 >> score2_2 >> score2_3;
    
    // get three quiz scores for name3
    cout << "Enter " << fname3 << "'s three test scores.\n> ";
    cin >> score3_1 >>  score3_2 >> score3_3;
    
    ave1 = (static_cast<double>(score1_1) + (score2_1 + score3_1)) / 3;
    ave2 = (static_cast<double>(score1_2) + (score2_2 + score3_2)) / 3;
    ave3 = (static_cast<double>(score1_3) + (score2_3 + score3_3)) / 3;
    
    cout << endl;
    
    // output the average
    cout << "Name\t\t" << "Quiz 1\t" << "Quiz 2\t" << "Quiz 3\t" << endl;
    cout << setfill('-') << setw(6) << "\t\t" << setfill('-') << setw(7) << "\t" 
		 << setfill('-') << setw(7) << "\t" << setfill('-') << setw(7) << " " << setfill(' ') << endl;

	cout << left << setw(6) << fname1 << "\t\t" << right << setw(4) << score1_1 << "\t" << setw(4) 
		 << score1_2 << "\t" << setw(4) << score1_3 << endl;
	cout << left << setw(6) << fname2 << "\t\t" << right << setw(4) << score2_1 << "\t" << setw(4) 
		 << score2_2 << "\t" << setw(4) << score2_3 << endl;
	cout << left << setw(6) << fname3 << "\t\t" << right << setw(4) << score3_1 << "\t" << setw(4) 
		 << score3_2 << "\t" << setw(4) << score3_3 << endl << endl;

	cout << fixed << setprecision(2) << "Average\t\t" << right << setw(4) << ave1 << "\t" << 
		 setw(4) << ave2 << "\t" << setw(4) << ave3 << endl;
    return 0;


}