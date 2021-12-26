// Paolo Vicencio, pjv7nd, bitCounter.cpp, 3/17/21
#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cmath>
using namespace std;
int binaryCounter(int x);
string baseConverter(string toConvert, string startBase, string endBase);
int main(int argc, char **argv) {
	// if no command line parameters
	if (argc != 5) {
		cout << "A Graceful Exit Has Been Made..." << endl;
		exit(-1);
	}
	// this is for the bit counter
	int theNumber = atoi(argv[1]);
	cout << argv[1] << " has " << binaryCounter(theNumber) << " bit(s)" << endl;

	
	// this is for the base converter
	baseConverter("ACDF", "16", "20");
	string string1 = argv[2];
	string string2 = argv[3];
	string string3 = argv[4];
	cout << string1 << " (base " << string2 << ")  = " << baseConverter(string1, string2, string3) <<
	" (base " << string3 << ")" << endl;  
	return 0;

}

int binaryCounter(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n==1) {
		return 1;
	}
	else {
		return (binaryCounter(n/2) + binaryCounter(n%2));
	}
}

string baseConverter(string toConvert, string startBase, string endBase) {
	// converting initial base to base 10 (1-10)
	int finalNumber = 0;
	if (startBase == "1" || startBase == "2" || startBase == "3" || startBase == "4" || startBase == "5" ||
		startBase == "6" || startBase == "7" || startBase == "8" || startBase == "9" || startBase == "10") {
		int sB = stoi(startBase);
		int count = toConvert.length() - 1;
		for (int i = 0; i < toConvert.length(); i++) {
			int converted = toConvert[i] - '0';
			int powered = pow(sB, count);
			int final = converted * powered;
			finalNumber += final;
			count--;
		}
	}
	// converting initial base to base 10 (11 - 36)
	else {
		int sB = stoi(startBase);
		int count = toConvert.length() - 1;
		int converted = 0;
		int powered = 0;
		int final = 0;
		for (int i = 0; i < toConvert.length(); i++) {
			if (toConvert[i] != '0' || toConvert[i] != '1' || toConvert[i] != '2' || toConvert[i] != '3' ||
				toConvert[i] != '4' || toConvert[i] != '5' || toConvert[i] != '6' || toConvert[i] != '7' ||
				toConvert[i] != '8' || toConvert[i] != '9') {

				converted = toConvert[i] - 55;
				powered = pow(sB, count);
				final = converted * powered;
				finalNumber += final;
				count--;


			}
			else {
				converted = toConvert[i] - '0';
				powered = pow(sB, count);
				final = converted * powered;
				finalNumber += final;;
				count--;
			}

			}
		}

		// converting from base 10 to any other base!

		int divider = stoi(endBase);
		int workNum = finalNumber;
		int remainder = 0;
		string remainderString = "";
		string finalStringNumber = "";
		while (workNum >= divider) {
			// setting the remainder
			remainder = workNum%divider;
			// accounting for letters
			if (divider == 10) {
				finalStringNumber = to_string(finalNumber);
				break;
			}

			else if (remainder > 9) {
				remainderString = remainder + 55;
				finalStringNumber.insert(0,remainderString);

			}
			else {
				// accounting for numbers
				remainderString = to_string(remainder);
				finalStringNumber.insert(0, remainderString);
		}
		workNum = workNum/divider;
		}
		if (workNum < divider) {
			remainder = workNum%divider;
			if (remainder > 9) {
				remainderString = remainder + 55;
				finalStringNumber.insert(0,remainderString);
			}

			else {
				remainderString = to_string(workNum);
				finalStringNumber.insert(0, remainderString);
		}

	}
	return finalStringNumber;
}








