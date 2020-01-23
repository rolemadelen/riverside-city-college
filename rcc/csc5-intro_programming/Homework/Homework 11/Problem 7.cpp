/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 7
* I certify this is my own work and code!
*/

// Create constructors for your time class.
//Create a default constructor and a
//constructor that takes hours, minutes, and seconds.

#include <iostream>

using namespace std;

//class time
// attributes : seconds, minutes, hours
class Time
{
	private:
		int seconds;
		int minutes;
		int hours;
    public:
        int get_seconds();//get time(accessor)
        void set_seconds(int); //set time(mutator)
        int get_minutes();
        void set_minutes(int);
        int get_hours();
        void set_hours(int);

        //constructor
        Time();
        Time(int, int, int); //h,m,s
        void output();
};

int main(int argc, char** argv)
{
	Time my_time;
	Time your_time(1,5,30);

	my_time.set_hours(2);
	my_time.set_minutes(30);
	my_time.set_seconds(59);
	my_time.output();

	your_time.output();

	return 0;
}

//constructor
Time::Time() : hours(0),minutes(0),seconds(0)
{}

Time::Time(int h, int m, int s)
{
    hours = h;
    minutes = m;
    seconds = s;
}
//getter
int Time::get_hours()
{
    return hours;
}
//setter
void Time::set_hours(int h)
{
    hours = h;
}
//getter
int Time::get_minutes()
{
    return minutes;
}
//setter
void Time::set_minutes(int m)
{
    minutes = m;
}
//getter
int Time::get_seconds()
{
    return seconds;
}
//setter
void Time::set_seconds(int s)
{
    seconds = s;
}

void Time::output()
{
    cout << "Hours : " << get_hours() << endl;
    cout << "Minutes : " << get_minutes() << endl;
    cout << "Seconds : " << get_seconds() << endl;
    cout << endl;
    cout << get_hours() << ":" << get_minutes()
         << ":" << get_seconds() << endl << endl;
}
