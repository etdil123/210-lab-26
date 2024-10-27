// COMSC 210 | Ethan Dilk | Lab 25 Races
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
using namespace std;
using namespace std::chrono;


list<int> reading(list<int> &times, vector<string>&, list<string>&, set<string>&);
list<int> sorting(list<int> &times, vector<string>&, list<string>&, set<string>&);
list<int> inserting(list<int> &times, vector<string>&, list<string>&, set<string>&);
list<int> deleting(list<int> &times, vector<string>&, list<string>&, set<string>&);

int main() {
    
    // initialize lists to store scores
    list<int> readingTimes, sortingTimes, insertingTimes, deletingTimes;

    // Initialize vector, list, and set to be used in race
    vector<string>;
    list<string>;
    set<string>;





    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

list<int> reading(list<int> &times, vector<string>&, list<string>&, set<string>&) {
    
    ifstream inputFile("codes.txt");

    // Reading in to vector
    // start timing
    auto start = high_resolution_clock::now();








}
