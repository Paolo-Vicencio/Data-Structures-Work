// Paolo Vicencio, pjv7nd, heapNode.cpp, 4/26/21

#include "heapNode.h"
#include <iostream>
#include <string>
using namespace std;

heapNode :: heapNode() {
	freq = 0;
	value = ' ';
	left = NULL;
	right = NULL;
}

heapNode :: heapNode(int F, string V) {
	freq = F;
	value = V;
	left = NULL;
	right = NULL;
}
