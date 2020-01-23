/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 10
* I certify this is my own work and code!
*/

// Create a Date class, like in lecture, that inherits
//from the time class. The date class should have a month and a year.

#include <iostream>
#include <fstream>

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
        void output(ostream &);
};

//class date inherits from Time class
class Date : Time
{
	public:
		int month;
		int year;
};

int main(int argc, char** argv)
{
	//file data.dat
	ofstream outfile;
	outfile.open("data.dat");

	Time my_time;
	Time your_time(10,30,59);

    Date today;
    
	//output to console
	my_time.output(cout);
	your_time.output(cout);

    //output to file
    my_time.output(outfile);
    your_time.output(outfile);

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

void Time::output(ostream &outs)
{
    outs << "Hours : " << get_hours() << endl;
    outs << "Minutes : " << get_minutes() << endl;
    outs << "Seconds : " << get_seconds() << endl;
    outs << endl;
    outs << get_hours() << ":" << get_minutes()
         << ":" << get_seconds() << endl << endl;
}
