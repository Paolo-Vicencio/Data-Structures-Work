// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "heap.h"
#include "heapNode.h"
using namespace std;


// Helper function for creating the tree
void newTree(heapNode* theNode, string PFC, string key);
void search(heapNode* theNode, string key);
void newTree(heapNode* theNode, string PFC, string key) {
    if (PFC == "") {
        // end of the recursion
        theNode->value = key;
    }
    // if the next element on the string is 0, go left
    if (PFC[0] == '1') {
        if (theNode->right == NULL) {
            heapNode* newNode = new heapNode();
            theNode->right = newNode;
        }
        newTree(theNode->right, PFC.substr(1, PFC.length() -1), key);
    }
    // if the next element on the string is 1, go right
    if (PFC[0] == '0') {
        if (theNode->left == NULL) {
            heapNode* newNode = new heapNode();
            theNode->left = newNode;
        }
        newTree(theNode->left, PFC.substr(1, PFC.length() -1), key);
    }
}

void search(heapNode* theNode, string key) {
    if (key == "") {
        cout << theNode->value;
    }
    if (key[0] == '1') {
        search(theNode->right, key.substr(1, key.length() - 1));
    }
    if (key[0] == '0') {
        search(theNode->left, key.substr(1, key.length() - 1));
    }
}


// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // Map that holds all the values and prefixes
    map<string, string> preCodes;
    heapNode* theNode = new heapNode();
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        preCodes[character] = prefix;
        newTree(theNode, prefix, character);
        // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // cout << theNode->left->value << endl;
    // cout << theNode->right->right->value << endl;
    // cout << theNode->right->left->right->value << endl;
    // cout << theNode->right->left->left->value << endl;


    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
        search(theNode, bits);
        // cout << bits << endl;


    }

    cout << "" << endl;

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();






}