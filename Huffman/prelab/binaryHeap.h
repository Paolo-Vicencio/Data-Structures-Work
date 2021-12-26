#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "heapNode.h"
using namespace std;

class binaryHeap {
public:
	binaryHeap();
	binaryHeap(vector<heapNode*> vec);
	~binaryHeap();;

	void insert(heapNode* theNode);
	void percolateUp(int hole);
	heapNode* deleteMin();
	void percolateDown(int hole);
	int findMin();

	unsigned int size();
	void makeEmpty();
	bool isEmpty();
	void print();


// private:
	vector<heapNode*> heap;
	int heapSize;
	map<char, string> frequencyMap;

};

#endif