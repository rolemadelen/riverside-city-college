/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* Homewwork 11 - problem 13
* I certify this is my own work and code!
*/

//Create three instances of your date class using
// the three constructors outlined in problem 11.
// Output the three date objects to the console and to a file.


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
	private:
		int month;
		int year;
    public:
        //constructor
        Date();
        Date(int, int);
        Date(int, int, int, int ,int);

        void output(ostream &);
};

int main(int argc, char** argv)
{
	//file data.dat
	ofstream outfile;
	outfile.open("data.dat");

    Date yesterday;
    Date today(2013,12);
    Date tommorow(2013,12,7,30,17);

	//output to console
	yesterday.output(cout);
	today.output(cout);
    tommorow.output(cout);

    //output to file
    yesterday.output(outfile);
    today.output(outfile);
    tommorow.output(outfile);

	return 0;
}

//TIME CLASS ###################
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
    outs << get_hours() << ":" << get_minutes()
         << ":" << get_seconds() << endl << endl;
}

//DATE CLASS ##################
//Default Constructor
Date::Date() : year(0), month(0)
{}

//year-month constrctor
Date::Date(int y, int mnt)
{
    year = y;
    month = mnt;
}

//y,mnt,h,m,s Constructor
Date::Date(int y, int mnt, int hr, int m, int s)
{
    year = y;
    month = mnt;
    Time::set_hours(hr);
    Time::set_minutes(m);
    Time::set_seconds(s);
}

void Date::output(ostream &outs)
{
    outs << "Year : " << year << endl;
    outs << "Month : " << month << endl;
    Time::output(outs);
}
