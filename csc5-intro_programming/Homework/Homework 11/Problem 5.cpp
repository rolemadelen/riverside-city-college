/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 5
* I certify this is my own work and code!
*/

// Make the time class’s attributes private instead of public.
// Trying running your program.
// It should not compile. Why? Provide the answer in comments within your code.

#include <iostream>

using namespace std;

//class time
// attributes : seconds, minutes, hours

class Time_class
{
    //class is private
	private:
		int seconds;
		int minutes;
		int hours;
};

int main(int argc, char** argv)
{
    //class declared.
	Time_class meeting;

    //Time class's attributes are private
    //I can't give values to private data
	cout << "enter two number(hours) : ";
	cin >> meeting.hours;

    cout << "Enter two number(minutes) : ";
    cin >> meeting.minutes;

    cout << "Enter two number(seconds) : ";
    cin >> meeting.seconds;

    return 0;
}

