// Paolo Vicencio, pjv7nd, 3/3/21, stackNode.cpp
#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>
using namespace std;

class StackNode {
public:
	StackNode();
private:
	int value;
	StackNode* next;
	StackNode* previous;

	friend class Stack;
	friend class StackItr;
};

#endif
