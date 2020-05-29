/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11
* I certify this is my own work and code!
*/

// Create a time structure with the following
// attributes: seconds, minutes, hours. 

#include <iostream>

using namespace std;

//structure time
// attributes : seconds, minutes, hours
struct Time
{
	int seconds;
	int minutes;
	int hours;
};

int main(int argc, char** argv)
{
	Time meeting;
	
	meeting.hours = 2;
	meeting.minutes = 30;
	meeting.seconds = 50;

	cout << "Meeting at " << meeting.hours << ":"
		 << meeting.minutes << ":" << meeting.seconds << endl;
}

