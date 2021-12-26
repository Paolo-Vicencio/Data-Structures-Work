// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "heapNode.h"
using namespace std;

// default constructor
binaryHeap::binaryHeap() : heapSize(0) {
    heap.push_back(0);

}

// builds a heap from an unsorted vector
binaryHeap::binaryHeap(vector<heapNode*> vec) : heapSize(vec.size()) {
    heap = vec;
    heap.push_back(heap[0]);
    heap[0] = 0;
    for (int i = heapSize/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
binaryHeap::~binaryHeap() {
}

void binaryHeap::insert(heapNode* theNode) {
    // vector "push back" command will push node into next availible spot in the vector
    heap.push_back(theNode);
    // percolate up switches the parent w/ the child until the ordering principle is fulfilled
    heapSize++;
    percolateUp(heapSize);
}

void binaryHeap::percolateUp(int hole) {
    // get the value that was just inserted
    heapNode* x = heap[hole];
    // while loop for the conditions: not at the main root
    // and while the value is less than the parent
    for ( ; (hole > 1) && (x->freq < heap[hole/2]->freq); hole /= 2)
        heap[hole] = heap[hole/2]; // move the parent down into the spot
        // heap[hole]->value = heap[hole/2]->value;
    // this will be reached once the correct position is found, is inserted at that spot
    heap[hole] = x;
}

heapNode* binaryHeap::deleteMin() {
    // first make sure that the heap isnt empty
    if ( heapSize == 0) {
        throw "deleteMin() was called on an empty heap";
    }
    // if not empty, first save the value that needs to be returned (the root node)
    heapNode* returnValue = heap[1]; // root node saved
    // move the farthest back node/index into the root node position
    heap[1] = heap[heapSize--];
    // makes sure that the vector itself removes the element
    heap.pop_back();
    // percolate the root down to the proper position 
    if (!isEmpty()) {
        percolateDown(1);
    }
    // finally, return the root node
    return returnValue;
}

void binaryHeap::percolateDown(int hole) {
    // save the value that needs to be percolated down
    heapNode* x = heap[hole];
    // while there is a left child...
    while (hole * 2 <= heapSize) {
        int child = hole * 2; // this is the left child
        // is there a right child? if so, is it lesser?
        if ( (child + 1) <= heapSize && 
                (heap[child+1]->freq < heap[child]->freq))
            child++;
        // if the child is greater than the node
        if (x->freq > heap[child]->freq) {
            heap[hole] = heap[child]; // move child up
            hole = child;             // move hole down
        }
        else 
            break;
    }
    // correct position found, insert at this spot
    heap[hole] = x;
}

int binaryHeap::findMin() {
    if (heapSize == 0) {
        throw "findMin() was called on an empty heap.";
    }
    return heap[1]->freq;
}

unsigned int binaryHeap::size() {
    return heapSize;
}

void binaryHeap::makeEmpty() {
    heapSize = 0;
    heap.resize(1);
}

bool binaryHeap::isEmpty() {
    return heapSize == 0;
}

void binaryHeap::print() {
    cout << "(" << heap[0] << ") ";
    for (int i = 1; i <= heapSize; i++) {
        cout << heap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}







