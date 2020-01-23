//Jiwon Yoo
//Homework 6 part : e
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

int main
	// when ')' is missing
	//error C2143: syntax error : mising ')' before '{'

	//when '(' is missing
	//error C2059: syntax error : ')'
	//error C2470: 'main" : looks like a function definition,but there is no parameter list, skipping apparent body.

	//when missing both
	//error C2470

{
	cout << "Hello, World" << endl;

	return 0;
}
