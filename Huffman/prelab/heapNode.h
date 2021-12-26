// Paolo Vicencio, pjv7nd, heapNode.h, 4/26/21
#ifndef HEAPNODE_H
#define HEAPNODE_H
#include <iostream>
#include <string>
using namespace std;

class heapNode {
public:
	heapNode();
	// Consider a unique constructor w/ frequency and value parameters
	heapNode(int F, char V);

	int freq;
	char value;
	heapNode* left;
	heapNode* right;



};

#endif