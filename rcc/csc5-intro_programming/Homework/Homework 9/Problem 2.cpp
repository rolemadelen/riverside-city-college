/*
* Jiwon Yoo
* Student ID : 2485776
* Professor Ung
* HW9 - Problem 2
* I certify this is my own work and code.
*/

/*
* Write a program to assign passenger seats in an airplane.
* Assume a small airplane with the seat numbering as follow:
* 1 A B C D
* 2 A B C D
* 3 A B C D
* 4 A B C D
* 5 A B C D
* 6 A B C D
* 7 A B C D
* The program should display the seat pattern, with an X 
* marking the seats already assigned. For example,
* after seats 1A, 2B, 4C are taken, the display
* should look like this:
* 1 X B C D
* 2 A X C D
* 3 A B C D
* 4 A B X D
* 5 A B C D
* 6 A B C D
* 7 A B C D
* After displaying the seats available, the program prompts
* for the seat desired, the user types in a sit, and then
* the display of available seats are filled or until the
* user signals that the program should end. If the user
* types in a seat that is already assigned, the program
* should say that the seat is occupied and ask for
* another choice. 
*/

#include <iostream>
#include <cctype>

using namespace std;

const int ROW = 7;
const int COL = 4;

//create plane seat patterns
//parameter : dynamic character array
//pseudo-returns
void planeSeat(char arr[][COL]);

//display plane seats
void output(char arr[][COL]);
/*
* avaliable function checks if user's desired
* seat is avaliable or not. If avaliable output
* reserved and place 'x' in that seat.
*
* parameter : dynamic array,  row and column
*
* pseudo-returns
*/
void avaliable(char arr[][COL], int numRow, char letter);

/*
* errorCheck function checks valid input for num
* and letter.
*
* parameter : num of rows (1~7) and letter(A~D)
*
* pseudo-returns
*/
void errorCheck(int& num, char& letter);

//create 50 end lines.
void clrScr();

bool everything(char arr[][COL]);

int main()
{
	char seat[ROW][COL];
	planeSeat(seat);
	output(seat);

	int num;
	char letter;
	cout << "Enter -1 to quit.\n\n";
	while(true)
	{
		cout << "Enter desired seat numbers. Ex) 1D or 4B.\n";
		cin >> num;
		if(num == -1)
			return 0;
		cin >> letter;

		errorCheck(num,letter);

		avaliable(seat,num,letter);

		output(seat);
	}
	return 0;
}
void planeSeat(char arr[][COL])
{
	char a;
	int cnt = 0;
	for(int i = 0; i < ROW; i++)
	{
		a = 'A';
		for(int j = 0; j < COL; j++)
		{
			arr[i][j] = a;
			a ++;
		}
	}
}

void avaliable(char arr[][COL], int numRow, char letter)
{
	for(int i = numRow-1; i < numRow; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			if(arr[i][j] == letter)
			{ 
				clrScr();
				cout << "Seat " << numRow << letter << " is reserved." << endl;
				arr[i][j] = 'X';
				
				return;
			}
			else if(arr[i][j] == 'X')
			{
				clrScr();
				cout << "I'm Sorry that seat is already reserved.\n";
			}
		}
	}
}

void output(char arr[][COL])
{
	int cnt = 0;
	for(int i = 0; i < ROW; i++)
	{
		cnt++;
		cout << cnt << " ";
		for(int j = 0; j < COL; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void errorCheck(int& num, char& letter)
{
	letter = toupper(letter);
	int letterNum = letter;

	if((num < 1 || num > 7) || (letterNum < 65 || letterNum > 68))
	{
		cout << "Enter desired seat numbers. Ex) 1D or 4B.\n";
		cin >> num;
		if(num == -1)
			exit(1);
		cin >> letter;
		errorCheck(num,letter);
	}
}

void clrScr()
{
	for(int i = 0; i < 50; i++)
		cout << endl;
}