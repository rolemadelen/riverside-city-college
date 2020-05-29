//Jiwon Yoo
//2013, September 3. Week 2
// Lab Worksheet problem 05
///////////////////////////////////////////////////////////////////
//Write what you think the answer is, and then write the code
//to see if it is true.
//
//     dif : 9.26
//     intDif : 926
//     intReal : 926
//
//      dif is obvious its a subtraction of type double.
// 
//      intDif is 925 because even though the programmer used
//static cast on double variable dif, (dif*mult) is done first;
//therefore, the value of intDif is 9.25 * 100 = 926
// 
//      intReal is just dif*mult which is 9.26 * 100 =  926
//
///////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
   
   double x = 10.76;
  double y = 1.50;
  const int mult = 100;
  
  double dif = x - y;
  cout << dif << endl;
  
  int intDif = static_cast<int>(dif * mult);

  cout << intDif << endl;                    //intDif is 925 because computer read (dif*mult) as 9.259999999999 which is 925.999999
  cout << dif * mult << endl;

  
  return 0;

}
