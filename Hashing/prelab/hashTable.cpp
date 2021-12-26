#include "hashTable.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

/*
IMPORTANT REFERENCES:
1) iterator movement and idea for contains method -> inspiration from geeksforgeeks.com
*/
hashTable :: hashTable() {

}

hashTable :: hashTable(int size) {
	// initialize
	finalGrid = new vector<list<string > >;
	// check if the number is already prime
	if (checkprime(size) == true) {
		sizeOfTable = size * 2;
	}
	else {
		int product = size * 2;
		sizeOfTable = getNextPrime(product);
	}
	// set the new table value
	finalGrid->resize(sizeOfTable);

	int count = 0;
	list<string> buckets;
	while (count < sizeOfTable) {
		finalGrid->push_back(buckets);
		count++;
	}


}

hashTable :: ~hashTable() {
	delete finalGrid;
}

bool hashTable :: contains(string x) {
	int hashed = hashFunction(x);
	list<string> locationOfHash = finalGrid->at(hashed);

	for (list<string> :: iterator search=locationOfHash.begin();
		search != locationOfHash.end(); ++search) {
		if (x == *search) {
			return true;
		}
	}
	return false;
}

void hashTable :: insert(string x) {
	 int hashed = hashFunction(x);
	 finalGrid->at(hashed).push_back(x);
	 // cout << "was inserted correctly" << endl;
}

int hashTable :: hashFunction(string x) {
	unsigned long long int array37[22];
	array37[0] = 1;
	for (int i = 1; i < 23; i++) {
		unsigned long long int value = array37[i-1] * 37;
		array37[i] = value;
	}

	unsigned int running = 0;
	// cout << "This is the length of the string: "<<  x.length() << endl;
	for (int j = 0; j < x.length(); j++) {
		running += int(x[j]) * array37[j];
	}	
	unsigned long int finalInt = running % sizeOfTable;
	return finalInt;
}

bool hashTable :: checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable :: getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}




