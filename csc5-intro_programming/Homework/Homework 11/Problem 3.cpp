/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 3
* I certify this is my own work and code!
*/

// Create an instance of your time class
// and time structure. Then, output the data.


#include <iostream>

using namespace std;

// structure:  time
// attributes : seconds, minutes, hours
struct Time_struct
{
    int seconds = 26;
    int minutes = 40;
    int hours = 9;
};

// class : timer
// attributes: seconds, minutes, hours
class Time_class
{
	public:
		int seconds;
		int minutes;
		int hours;
};

int main(int argc, char** argv)
{
	//time class
	Time_class meeting;
	//time structure
    Time_struct meeting2;
	
	//init time class attributes
	meeting.hours = 2;
	meeting.minutes = 30;
	meeting.seconds = 50;

	//output
	cout << "First meeting is at " << meeting.hours << ":"
		<< meeting.minutes << ":" << meeting.seconds << endl;

    cout << "Second meetting is at " << meeting2.hours << ":"
         << meeting2.minutes << ":" << meeting.seconds << endl;

    return 0;
}

