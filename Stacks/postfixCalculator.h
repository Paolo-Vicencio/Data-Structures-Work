// Paolo Vicencio, pjv7nd, 2/28/21, postfixCalculator.cpp
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "stackNode.h"
#include "stackItr.h"
using namespace std;

class postfixCalculator {
public:
	// constructor, creates a new postfixCalculator object
	postfixCalculator();

	// destructor, cleans it up
	~postfixCalculator();

	// operator= function should go here

	void addition();

	void subtraction();

	void multiplication();

	void division();

	void negate();

	Stack daStack;
private:


};

#endif