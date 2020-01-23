/*
	Author: Jiwon Yoo
	Specification file for the Node
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
	T data;
	Node *ptr;
};

#endif
