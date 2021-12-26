// Paolo Vicencio, pjv7nd, 3/3/21, stackItr.h
#ifndef STACKITR_H
#define STACKITR_H
#include "stackNode.h"
using namespace std;

class StackItr {
	public:
		StackItr();

		StackItr(StackNode* theNode);

		bool isPastEnd() const;

		bool isPastBeginning() const;

		void moveForward();

		void moveBackward();

		int retrieve() const;
	

	private:
		StackNode* current;

		friend class Stack;

};

#endif