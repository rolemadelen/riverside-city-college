/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 4
* I certify this is my own work and code!
*/

// Repeat the previous problem, but give values
// to the attributes of the two objects.
// Output the data after you’ve given them values.

#include <iostream>

using namespace std;

//class time
// attributes : seconds, minutes, hours
struct Time_struct
{
    int seconds = 26;
    int minutes = 40;
    int hours = 9;
};

class Time_class
{
	public:
		int seconds;
		int minutes;
		int hours;
};

int main(int argc, char** argv)
{
	Time_class meeting;
    Time_struct meeting2;

	cout << "enter two number(hours) : ";
	cin >> meeting.hours;
	cin >> meeting2.hours;

    cout << "Enter two number(minutes) : ";
    cin >> meeting.minutes;
    cin >> meeting2.minutes;

    cout << "Enter two number(seconds) : ";
    cin >> meeting.seconds;
    cin >> meeting2.seconds;

    cout << endl;
    
	cout << "First meeting is at " << meeting.hours << ":"
		<< meeting.minutes << ":" << meeting.seconds << endl;

    cout << "Second meetting is at " << meeting2.hours << ":"
         << meeting2.minutes << ":" << meeting.seconds << endl;

    return 0;
}

