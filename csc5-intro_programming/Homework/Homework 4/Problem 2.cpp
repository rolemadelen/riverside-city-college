/*
* Jiwon Yoo
* Professor Ung
* Student ID: 2485776
* CSC5 - C++ Programming
* Homework 4 - Problem 2
* I certify this is my own work and code
*/

/*
  The formula for the calories needed for a 
  woman to maintain her weight is:
  BMR = 655 + (4.3 x weight in pounds)
  + (4.7 x height in inches) – (4.7 x age in years)

  The formula for the calories needed
  for  a man to maintain his weight is:
  BMR = 66 + (6.3 x weight in pounds)
  + (12.9 x height in inches) – (6.8 x age in years)

*/
// A typical chocolate bar will contain around 230 calories.
// Write a program that allows the user to input in the 
// following order: his or her weight in pounds, height
// in inches, age in years, and the character M for male
// and F for female. The program should then output the
// number of chocolate bars that should be consumed to
// maintain one’s weight for the appropriate sex of the
// specified weight, height, and age..
// Allow the user to do this as many times as they wish.

#include <iostream>
using namespace std;

int main()
{
    const int CHOCOLATE_BAR = 230;
        
    //declare weight(lb), height(in), age(yr), gender
    double weight, height, age;
    double bmr;
    char gender;
    //repeat?
    char respond;
        
    while(true)
    {
        // get weight
        cout << "How much do you weight? (lb).\n> ";
        cin >> weight;
                
        // get height
        cout << "How tall are you? (inches). 1 ft = 12 inch.\n> ";
        cin >> height;
                
        // get age
        cout << "How old are you?\n> ";
        cin >> age;
                
        // get gender
        cout << "What is your gender? (M or F).\n> ";
        cin >> gender;
                
        cout << endl;
                
        // calculate BMR for man and women
        if(gender == 'F' || gender == 'f')
        {
              bmr = 655.0 + (4.3 * weight)
			       + (4.7 * height) - (4.7 * age);
        }
        else if(gender == 'M' || gender == 'm')
        {
            bmr = 66.0 + (6.3 * weight)
		          + (12.9 * height) - (6.8 * age);
        }
        else
		{
			cout << "Invalid value was inputted.\n"
				 << "Program will terminate.\n";
			return 0;
		}
        cout << "Your BMR is : " << bmr << endl << endl;

        // divide BMR by cholocateBar and output 
        // how many chocoBar should be consumed.
        cout << "Number of chocolate bars you should\n"
             << "consume to maintain your weight is....\n";
        cout << static_cast<int>(bmr / CHOCOLATE_BAR)
             << " chocolate bars.\n\n";
                
        //try again?
        cout << "Do you want to try again? (Y / N): ";
        cin >> respond;
                
        //if yes, try agian
        if(respond == 'y' || respond == 'Y')
        {
              cout << "okay.!" << endl << endl;
        }
             //else return 0;
        else
        {
            cout << "That's it !!\n";
            return 0;
        }
    }
}
