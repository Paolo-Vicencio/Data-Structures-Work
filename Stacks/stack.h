// Paolo Vicencio, pjv7nd, 3/3/21, stack.h
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "stackNode.h"
#include "stackItr.h"
using namespace std;

class Stack {
	public:	
		// constructor
		Stack();

		// destructor
		~Stack();

		// pushes an element (an int) to the top of the stack
		void push(int e);

		// returns the top element of the stack, does not remove it
		int top();

		// removes the element on top of the stack, but does not return it
		void pop();

		// tells whether or not there are any elements left in the stack
		bool empty();

		// insert before method from the List.cpp file translated here
		void insertBefore(int x, StackItr position);

	private:
		StackNode* head;
		StackNode* tail;
		int count;
};

#endif