// Paolo Vicencio, pjv7nd, prelab4.cpp, 3/15/21
#include <iostream>
#include <string>
#include <climits>
#include <limits.h>
#include <vector>
using namespace std;
void sizeOfTest();
void overflow();
void outputBinary(unsigned int x);
 

int main() {
	unsigned int integer;
 	cin >> integer;
 	sizeOfTest();
 	overflow();
 	outputBinary(integer);
   	return 0;
}

void sizeOfTest() {
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of bool: " << sizeof(bool) << endl;
	cout << "Size of int*: " << sizeof(int*) << endl;
	cout << "Size of char*: " << sizeof(char*) << endl;
	cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
	unsigned int maxValue = UINT_MAX;
	maxValue += 1;
	cout << UINT_MAX << " + " << 1 << " = " << maxValue << endl;
}

void outputBinary(unsigned int x) {
	int numberArray[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int i = 0;
	while (i<32) {
		numberArray[i] = x % 2;
		x = x/2;
		i++;
	}
	for (int x = 31; x >=0; x--) {
		if (x == 28 || x == 24 || x == 20 || x == 16 || x == 12 || x == 8 || x == 4) {
			cout << numberArray[x];
			cout << " ";

		}
		else {
			cout << numberArray[x];
		}
	}
	cout << " " << endl;

}






















