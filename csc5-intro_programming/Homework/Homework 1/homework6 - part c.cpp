//Jiwon Yoo
//Homework 6 part : c
////////////////////////////////////////////////////////////////////////////////
// The purpose of the exercise is to product a catalog of typical syntax errors
// and error messages that will be encountered by a beginner and to continue
// acquainting you with the programming environment. This exercise should leave 
// you with a knowledge of what error to look for when given any of a number of 
// common error messages.
// Use a program you from one of the previous Programming Projects.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>  

using namespace std;

main()        //error C4430: misiing type spcifier - int assumed. c++ does not support default-int.
{
	cout << "Hello, World" << endl;

	return 0;
}
