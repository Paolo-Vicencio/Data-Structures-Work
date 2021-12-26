// Paolo Vicencio, pjv7nd, 2/28/21, postfixCalculator.cpp

#include <iostream>
#include "postfixCalculator.h"
#include "stack.h"
#include "stackNode.h"
#include "stackItr.h"
using namespace std;

postfixCalculator :: postfixCalculator() {
	Stack daStack = Stack();
}

postfixCalculator :: ~postfixCalculator() {
	// I still do not know what goes here
}

void postfixCalculator :: addition() {
		int int1 = daStack.top();
		daStack.pop();
		int int2 = daStack.top();
		daStack.pop();
		int int3 = int1 + int2;
		daStack.push(int3);

}

void postfixCalculator :: subtraction() {
		int int1 = daStack.top();
		daStack.pop();
		int int2 = daStack.top();
		daStack.pop();
		int int3 = int2 - int1;
		daStack.push(int3);
}

void postfixCalculator :: multiplication() {
		int int1 = daStack.top();
		daStack.pop();
		int int2 = daStack.top();
		daStack.pop();
		int int3 = int2 * int1;
		daStack.push(int3);
}

void postfixCalculator :: division() {
		int int1 = daStack.top();
		daStack.pop();
		int int2 = daStack.top();
		daStack.pop();
		int int3 = int2 / int1;
		daStack.push(int3);
}

void postfixCalculator :: negate() {
	int int1 = daStack.top();
	daStack.pop();
	daStack.push(int1 * (-1));
}





