/*
	Author: Jiwon Yoo
	Date: March 29, 2016
	Specification file for the Circular Linked List
*/

// User Libraries
#include "Node.h"

class CLnkdLst {
	private:
		Node *head;
		Node *tail;
	public:
		// Constructor
		CLnkdLst( int );

		// Destructor
		~CLnkdLst();	

		// Member Functions
		void push_back( int );	
		void push_front( int );	
		int pop_back();
		int pop_front();
};
