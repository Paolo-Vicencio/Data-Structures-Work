#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class hashTable {
public:
	hashTable();
	hashTable(int size);
	~hashTable();
	bool contains(string x);
	void insert(string x);
	int hashFunction(string x); // something needs to go into these parentheses

	// prime functions
	bool checkprime(unsigned int p);
	int getNextPrime(unsigned int n);


	vector<list<string> > *finalGrid;

private:	
	int sizeOfTable;



};

#endif

