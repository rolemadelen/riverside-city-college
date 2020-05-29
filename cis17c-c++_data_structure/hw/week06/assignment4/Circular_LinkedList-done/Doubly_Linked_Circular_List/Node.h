/*
	Author: Jiwon Yoo
	Specification file for the Node Structure file
*/

#ifndef NODE_H
#define NODE_H

struct Node {
	Node *next;
	Node *prev;
	int data;
};

#endif
