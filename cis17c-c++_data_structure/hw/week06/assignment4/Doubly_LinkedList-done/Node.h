/*
	Author: Jiwon Yoo
	Date: March 29, 2016
	Specification file for the Node Structure file
*/

#ifndef NODE_H
#define NODE_H

struct Node {
	Node *next; // points successor
	Node *prev; // points predecessor
	int data;
};

#endif
