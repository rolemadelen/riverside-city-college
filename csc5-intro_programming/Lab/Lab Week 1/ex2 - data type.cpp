#include <iostream>
using namespace std;
int main()
{    
    string hello = "C++ is FUN!!";
    int number = 5;
    char character = 'a';
    float decimal_float = 3.14159; // accuracy 7 decimal places
    double decimal_double = 3.14159; //accuracy 14 decimal places
    
    cout << endl << hello << endl;
    cout << "HELLO WORLD!";
    cout << "number : " << number << endl;
    cout << "character : " << character << endl;
    cout << "character : " << static_cast<int>(character) << endl;
    cout << "float : " << decimal_float << endl;
    cout << "double : " << decimal_double << endl;
    
    return 0;
}