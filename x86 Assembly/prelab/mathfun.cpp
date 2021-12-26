// Paolo Vicencio, pjv7nd, 4/12/21, mathfun.cpp

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

extern "C" int product(int x, int y);
extern "C" int power(int x, int y);

int main() {
	int x;
	int y;
	cout << "Enter the first integer: ";
	cin >> x;
	cout << "Enter the second integer: ";
	cin >> y;

	int daProduct = product(x,y);
	cout << "Product: "  << daProduct << endl;
	int daPower = power(x,y);
	cout << "Power: " << daPower << endl;
}