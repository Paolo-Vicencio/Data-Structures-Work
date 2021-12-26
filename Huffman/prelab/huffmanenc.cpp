#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <vector>
#include <map>
#include "heap.h"
#include "heapNode.h"

// prefix functions
void printPrefix(heapNode* theNode, string path);
void findPrefix(heapNode* theNode, string path, string key);
map<char,string> freqMap;
string prefixString;
// TIME TO FIGURE OUT THE PREFIX CODES VIA THE TREE #2 (B)

// The print prefix function prints out the prefixes in a certain order
void printPrefix(heapNode* theNode, string path) {
	if (theNode->left == NULL && theNode->right == NULL) {
		// recursion is over
		if (theNode->value == ' ') {
			cout << "space" << " " << path << endl;
			freqMap[theNode->value] = path;
		}
		else {
			cout << theNode->value << " " << path << endl;
			freqMap[theNode->value] = path;
		}	
	}		
	else  {

		 printPrefix(theNode->right, path + "1");
		 printPrefix(theNode->left, path + "0");
	}

}

// The find prefix function finds just one specific prefix and prints it out
void findPrefix(heapNode* theNode, string path, char key) {
	if (theNode->left == NULL && theNode->right == NULL) {
		// recursion is over
		if (theNode->value == key) {
			if (theNode->value == ' ') {
				cout <<  path << " ";
				prefixString += path;
			}
			else {
				cout << path << " ";
				prefixString += path;
			}	
		}
	}		
	else  {
		 findPrefix(theNode->right, path + "1", key);
		 findPrefix(theNode->left, path + "0", key);
	}
}

// CHANGE THE CONDITION BITCH

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "1 Parameter Required." << endl;
		exit(-1);
	}

	// Reading the file into a comprehensible string
	ifstream myFile(argv[1]);
	string myText((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>()); 

	// Setting up data structures to store values
	map<char,int> theMap;
	vector<char> theVec;
	binaryHeap freqHeap;

	vector<char> valueVec;
	vector<int> freqVec;

	// Traversing the string and storing the frequencies as well as the chars
	for (int i = 0; i < myText.length() - 1; i++) {
		if (theMap.count(myText[i]) == 0) {
			theMap[myText[i]] = 1;
		}
		else {
			theMap[myText[i]] += 1;
		}
	}
	// Putting the keys and values into their respective vectors
	map<char,int>::iterator it;
	for (it = theMap.begin(); it != theMap.end(); it++) {
		// cout << it->first << " " << it->second << endl;
		valueVec.push_back(it->first);
		freqVec.push_back(it->second);
	}
	// Creating new nodes with those new values
	for (int i = 0; i < valueVec.size(); i++) {
		heapNode* myNode = new heapNode(freqVec[i], valueVec[i]);
		freqHeap.insert(myNode);
	}
	// TIME TO BUILD THE MF TREE PART #2 (A)
	// cout << freqHeap.heapSize << endl;
	int placeHolder = freqHeap.heapSize + 1;
	for (int i = 0; i < placeHolder ; i++) {
		if (freqHeap.heapSize == 1 ) {
			break;
		}
		else {
			// instantiates the new node pointers to work with
			heapNode* abba = new heapNode();
			heapNode* a = freqHeap.deleteMin();
			heapNode* b = freqHeap.deleteMin();
			// sets the arb nodes L and R pointers = the new Node Pointers
			abba->left = a;
			abba->right = b;
			// sets the value of the arb node to the sum of the two children
			abba->freq = a->freq + b->freq;
			freqHeap.insert(abba);

			// cout << freqHeap.heap[1]->freq << endl;
		}
	}
	// Calculate the Prefix codes using the findPrefix() method and store them in a map

	// PRINTING OUT EVERYTHING IN THE PROPER FORMAT!
	// map<char,string>::iterator ste;
	// for (ste = freqMap.begin(); ste != freqMap.end(); ste++) {
	// 	cout << ste->first << " " << ste->second << endl;
	// }

	// float p = myText.length();
	// float v = prefixString.length();


	printPrefix(freqHeap.heap[1], "");

	cout << "----------------------------------------" << endl;

	for (int i = 0; i < myText.length(); i++) {
		findPrefix(freqHeap.heap[1], "", myText[i]);
	}
	cout << " " << endl;

	cout << "----------------------------------------" << endl;
	cout << "There are a total of " << myText.length() - 1 << " symbols that are encoded." << endl;
	cout << "There are " << theMap.size() << " distinct symbols used." << endl;
	cout << "There were " << (myText.length() - 1) * 8 << " bits in the original file." << endl;
	cout << "There were " << prefixString.length() << " bits in the compressed file." << endl;

	cout << "This gives us a compression ratio of " << (float)((myText.length() -1)  * 8) / (float)prefixString.length()  << "." << endl;

	cout << "The cost of hte Huffman tree is " << (float)prefixString.length() / (float)(myText.length() - 1) << " bits per character." << endl;

	


}






