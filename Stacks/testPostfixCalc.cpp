// Paolo Vicencio, pjv7nd, 2/28/21, testPostfixCalculator.cpp
#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "stackItr.h"
#include "stackNode.h"
#include <sstream>
using namespace std;

int main() {
	string response;
	postfixCalculator myCalculator;
	Stack daStack;
	while (cin >> response) {
		if (response == "+") {
			myCalculator.addition();
		}
		else if (response == "-") {
			myCalculator.subtraction();
		}
		else if (response == "*") {
			myCalculator.multiplication();
		}
		else if (response == "/") {
			myCalculator.division();
		}
		else if (response == "~") {
			myCalculator.negate();
		}
		else {
			int theInteger = stoi(response);
			myCalculator.daStack.push(theInteger);
		}
	}


	cout << myCalculator.daStack.top() << endl;
	return 0;
}	
	// getline(cin, response);
	// postfixCalculator myCalculator;
	// for (int i = 0; i <  response.length() ; i++ ) {
	// 	if (response[i] == ' ') {
	// 		continue;
	// 	}
	// 	if (response[i] == '+') {
	// 		myCalculator.addition(); 
	// 	}
	// 	else if (response[i] == '-') {
	// 		myCalculator.su btraction();
	// 	}
	// 	else if (response[i] == '*') {
	// 		myCalculator.multiplication();
	// 	}
	// 	else if (response[i] == '/') {
	// 		myCalculator.division();
	// 	}
	// 	else {
	// 		if (response[i + 1] != ' ') {
	// 			std::string theStringInteger = "";

	// 			char first = response[i];
	// 			char second = response[i +1];

	// 			theStringInteger.push_back(first);
	// 			theStringInteger.push_back(second);

	// 			stringstream streamer(theStringInteger);
	// 			int x = 0;
	// 			streamer >> x;

	// 			myCalculator.myStack.push(x);
	// 			i++;
		
	// 		}
	// 		else {	
	// 			int number = response[i];
	// 			int theInteger = (int)number - 48;
	// 			myCalculator.myStack.push(theInteger);

	// 		}	
	// 		}
	// }
	// cout << myCalculator.myStack.top() << endl;
// 	return 0;

// }
