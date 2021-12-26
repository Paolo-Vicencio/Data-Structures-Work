// Paolo Vicencio, pjv7nd, 3/3/21, stack.cpp
#include "stack.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Stack :: Stack() {
	count = 0;
	head = new StackNode();
	tail = new StackNode();

	tail->previous = head;
	head->next = tail;

	tail->next = NULL;
	head->previous = NULL;
}

Stack :: ~Stack() {

}

void Stack :: push(int e) {
	StackNode *newNode = new StackNode();
	StackItr iterator = StackItr(head);
	if (empty() == true) {
		StackItr iterator2 = StackItr(tail);
		insertBefore(e, iterator2);
	}
	else {
		iterator.moveForward();
		insertBefore(e, iterator);
	}
}

int Stack :: top() {
	StackItr iterator = StackItr(head);
	iterator.moveForward();
	if (empty() == true) {
		cout << "There are no elements in this stack." << endl;
		exit(-1);

	}
	return iterator.current->value;
	
}

void Stack :: pop() {
	StackItr iterator = StackItr(head);
	iterator.moveForward();
 	if (empty() == true) {
 		cout << "There are no elements in this stack." << endl;
 		exit(-1);
}
 	else {
 		iterator.current->previous->next = iterator.current->next;
 		iterator.current->next->previous = iterator.current->previous;
            
        iterator.current->next = NULL;
        iterator.current->previous = NULL;
        iterator.current->value = 0;
}
}

bool Stack :: empty() {
	if (tail->previous == head && head->next == tail) {
		return true;
	}
	else {
		return false;
	}
}

void Stack :: insertBefore(int x, StackItr position) {
    StackNode *newNode = new StackNode();
    newNode->value = x;
    newNode->next = position.current;
    newNode->previous = position.current->previous;

    position.current->previous->next = newNode;
    position.current->previous = newNode;

}





