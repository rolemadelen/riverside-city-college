/*
	Author: Jiwon Yoo
	Date: March 30, 2016
	Specification file for the Node Structuer file
*/

#ifndef NODE_H
#define NODE_H

struct Node {
	int data;
	Node *next;
	Node *prev;
};

#endif
