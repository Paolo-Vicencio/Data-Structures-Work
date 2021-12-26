#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
 /**
  * Does the actual traversal
  * and printing of the given command line parameters
  */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed 
    /** @file */ 
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    // pull out first string from dests
    string initial = dests[0]; 

    // holding variables
    float least = computeDistance(me,initial,dests);;
    float inter = 0.0;
    vector<string> check = dests; 

    // two new iterators for sort
    vector<string>::iterator daOne = dests.begin() + 1;
    vector<string>:: iterator daTwo = dests.end();
    sort(daOne, daTwo); 

    while(next_permutation(daOne,daTwo)) {
        inter = computeDistance(me,initial,dests);
        if(inter < least){
            check = dests;
            least = inter;
    }
  }
    initial = check.at(0);
    cout<<"Minimum path has distance of "<< least << ": ";
    printRoute(initial, check);
    cout << " " << endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/**
 * This is the implementation of the computeDistance function 
 * described in the middleearth.cpp file
 * @see middleearth.cpp
 * @param MiddleEarth object "me"
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    
    float distance = 0.0;

    // store the variables before it begins
    string first = start; /*! Storing the start of the journey into an unchanging variable*/
    string last = dests.back(); /*! Storing the end of the journey into an unchanging variable*/
    int length = dests.size();
    

    for (int i = 0; i < length; i++) {
        distance = distance + me.getDistance(first, dests[i]);
        first = dests[i];
    }

    distance = distance + me.getDistance(dests[0], last);
    return distance; /*! Returns the final value */
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
 * This is the implementation of the printRoute fucntion
 * described in the middleearth.cpp file
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    // this is the iterator
    for (auto &it : dests) {
        cout << it << " -> ";
    }
    cout << start;

}