#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

extern "C" int threexplusone(int num);

int main() {
	int num;
	cout << "Enter Number: ";
	cin >> num;

	int final = threexplusone(num);
	cout << final << endl;
	return 0;
}