//Jiwon Yoo
//Homework 6 part : f
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

int main()   
{
	cout << "Hello, World" <<  endl;
	//misspell cout
	//error C2065 'cot' : undeclared identifier

	//missing one insertion operator
	//error C2679: binary '<' : no operator found --

	//missing both
	//error C2146: syntax error : missing ';' before identifier 'endl'
	//warning C4551: function call missing argument list

	//missing ending curly brace
	//error C1075: end of file found before the left brace '{' at 'c:\uesrs-------' was matched

	return 0;
	//missing return 0; worked fine, but misspelling caused an error.
	//error C2065: 'retun' : undeclared identifier
	//error C2143 : syntax error : missing ';' before 'constant'
}