#include <iostream>
#include <fstream>
#include <string>
#include "hashTable.h"
#include "timer.h"
#include <vector>
using namespace std;

// grid specifications

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// other functions that I'll be needing
bool readInGrid(string filename, int rows, int cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
	int numRows, int numCols);


int main(int argc, char **argv) {
	if (argc != 3) {
		cout << "2 Parameters Required." << endl;
		exit(-1);

	}

	// reading in and storing all of the elements from the word file into a dictionary
	// unordered_set<string> myDictionary;
 	
	// getting the initial count from the file to use in the table
	string myText;
	ifstream myFile(argv[1]);
 	int daCount = 0;
	while(getline(myFile, myText)) {
		daCount++;
	}
	myFile.close();

	// cout << daCount << endl;

	// setting up the hash table with the newly gathered int
	hashTable myTable(daCount);
	// cout << myTable.finalGrid->size() << endl;


	// setting up components necessary for reading in the file
	// unordered_set<string> myDictionary;

	// new file opening
	ifstream myFile2(argv[1]);



	// finally, reading it in 
	while (getline(myFile2, myText)) {
		if (myText.length() > 2) {
			// cout << myText << endl;
			myTable.insert(myText);
			// myDictionary.insert(myText);
		}
	}
	myFile2.close();

	// myTable.insert("abcdef");



	// iterating through the dictionary and printing it
	// cout << "\nAll ELements: ";
	// unordered_set<string> :: iterator itr;
	// for (itr = myDictionary.begin(); itr != myDictionary.end(); itr++) {
	// 	cout << (*itr) << endl;
	// }


	// reading the grid into an array
	string theArray[3];
	int count = 0;
	ifstream myGrid(argv[2]);
	while (getline(myGrid, theArray[count], '\n')) {
		count++;

	}


	int rows = stoi(theArray[0]);
	int cols = stoi(theArray[1]);

	// cout << theArray[0] << endl;
	// cout << theArray[1] << endl;

	readInGrid(argv[2], rows, cols);


	/**
	1) the first integer is the start of the row
	2) the second integer is the start of the column
	3) the third integer is the direction (north-northwest -> 0-7)
	4) length of the desired string to return
	*/
	
	string nesw[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
	int deez = 0;
	// vector<string> foundWords;
	// vector<string> cardinals;

	timer daTimer;
	daTimer.start();


	for (int sr = 0; sr < rows; sr++) {
		for (int sc = 0; sc < cols; sc++) {
			for (int direction = 0; direction < 8; direction++) {
				for (int length = 3; length < 22; length++) {
					string daWord = getWordInGrid(sr, sc, direction, length, rows, cols);
					if (length > daWord.length()) {
						break;
					}
					// cout << daWord << endl;
					if (myTable.contains(daWord) == true) {
						deez++;
						// string cardinal = string(nesw[direction]);
						// foundWords.push_back(daWord);
						// cardinals.push_back(cardinal);
						cout << nesw[direction] << " " << "("
						<< sr << ", " << sc << "):" << " " << daWord << endl;
					}

				}
			}
		}
	}
	daTimer.stop();

	// for (int yuh = 0; yuh < foundWords.size(); yuh++) {
	// 	cout << cardinals[yuh] << " " << "(" << theArray[0] << ", " << theArray[1] << "):" << " " << foundWords[yuh] << endl;
	// }

	cout << deez << " words found" << endl;
	// cout << "Found all words in " << daTimer << " seconds" << endl;







	return 0;
}

bool readInGrid(string filename, int rows, int cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            // cout << grid[r][c];
        }
        // cout << endl;
    }
    return true;
}


string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}