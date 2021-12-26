#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <array>
using namespace std;



class graph {
public:
	// graph structures and variables

	// number of vertices/nodes
	int vertices;

	// adjacency list
	list<int>* adjacentList;

	// map that will help connect ints to strings
	map<int, string> mainMap;

	// graph functions
	// constructor
	graph(int num);

	// recursive help function for main topSort function
	void sortHelp(int v, bool visited[], stack<int>& Stack);

	// adds new edge, adjusting both int->string reference map
	// as well as adjacency list
	void addEdge(map<string, int> theMap, string s1, string s2);

	// final top sort function that prints out and moves through 
	// various lists and stacks
	void topSort();

};

// Graph constructor -- creates a graph object, which is essentially the 
// number of vertices and a vector of vectors of strings
graph :: graph(int vs) {
	vertices = vs;
	adjacentList = new list<int>[vertices];
}

void graph :: sortHelp(int vertex, bool visited[], stack<int>& daStack) {
	
	// set vertex in the visited equal to "true"
	visited[vertex] = true;

	// create a new iterator to go through the adjacency list
	list<int>::iterator iterator;
	for (iterator = adjacentList[vertex].begin(); iterator != adjacentList[vertex].end(); iterator++) {
		if (visited[*iterator] == false) {
			sortHelp(*iterator, visited, daStack);
		}
	}

	daStack.push(vertex);
}

// adds a new edge to the graph with the provided start and end points
void graph :: addEdge(map<string, int> theMap, string s1, string s2) {
	// since cannot add strings to the adjacency list, need to 
	// map them with corresponding integers
	int new1 = theMap[s1];
	int new2 = theMap[s2];

	mainMap[new1] = s1;
	mainMap[new2] = s2;

	adjacentList[new1].push_back(new2); 
}


void graph :: topSort() {
	
	// create data structures necessary for sorting
	stack<int> daStack;
	bool* visited = new bool[vertices];
	// set all initial "visited" values to "false"
	for (int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	// if it has not been visited, call recursive helper function
	for (int i = 0; i < vertices; i++) {
		if (visited[i] == false) {
			sortHelp(i, visited, daStack);
		}
	}

	while (daStack.empty() == false) {
		string finalPrint = mainMap[daStack.top()];
		int x = daStack.top();
		string output = mainMap[x];
		// cout << finalPrint << "yum ";
		// cout << output << " ";
		daStack.pop();
	}
}


// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // // count the number of lines and create an array with this size
    int count = 0;
    string line;
    ifstream myFile(argv[1], ifstream::binary);
    while (getline(myFile,line)) {
    	count++;
    }
    count -= 2;
    myFile.close();

   	graph daGraph(count);

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    string line2;
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // create new map for int->string reference
    map<string, int> daMap;

    // read in two strings
    while (getline(file,line2)) {
    	string s1,s2;
	    file >> s1;
	    file >> s2;
	    if (s1 == "0" || s2 == "0") {
	    	break;
	    }

	    daGraph.addEdge(daMap,s1,s2);

	    // output those strings
	}



	// Execute the topological search on the newly created edges
    daGraph.topSort();

    // close file before the end
   	file.close();

}





