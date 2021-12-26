// Paolo Vicencio, pjv7nd, 3/3/21, stackItr.cpp
#include <iostream>
#include "stackItr.h"
using namespace std;

StackItr :: StackItr() {
	current = new StackNode;
}

StackItr :: StackItr(StackNode* theNode) {
	current = theNode;
}

bool StackItr :: isPastEnd() const {
	if (current->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool StackItr :: isPastBeginning() const{
	if (current->previous == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void StackItr :: moveForward() {
	if (isPastEnd() == false) {
		current = current->next;
	}
}

void StackItr :: moveBackward() {
	if (isPastBeginning() == false) {
		current = current->previous;
	}
}

int StackItr :: retrieve() const {
	return current->value;
}