/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 6
* I certify this is my own work and code!
*/

// Edit your time class to now include accessor/mutator (getter/setter)
// functions for the attributes. You also need to define your
// member functions. Edit your code (main) to use the member functions
// instead of directly accessing the attributes.

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
};

int main(int argc, char** argv)
{
	Time my_time;

	my_time.set_hours(2);
	my_time.set_minutes(30);
	my_time.set_seconds(59);
	my_time.output();

	return 0;
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
