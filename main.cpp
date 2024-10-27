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


void reading(list<int> &times, vector<string>&, list<string>&, set<string>&);
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

    
    for (auto t : readingTimes)
        cout << t << endl;




    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/

void reading(list<int> &times, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {
    
    ifstream inputFile("codes.txt");

    // Reading in to VECTOR
    // start timing
    auto start = high_resolution_clock::now();

    string temp;
    while(getline(inputFile, temp)) {
        stringVec.push_back(temp);
    }
    // end timing
    auto end = high_resolution_clock::now();

    // duration in milliseconds
    auto duration = duration_cast<milliseconds>(end - start);
    // adding time into vector storing times
    times.push_back(duration.count());
    inputFile.clear();
    inputFile.seekg(0);

    // Reading in to LIST 
    // start timing
    start = high_resolution_clock::now();

    string temp1;
    while(getline(inputFile, temp1)) {
        stringList.push_back(temp1);
    }
    // end timing
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    
    // adding time into vector storing times
    times.push_back(duration.count());
    inputFile.clear();
    inputFile.seekg(0);

     // Reading in to SET 
    // start timing
    start = high_resolution_clock::now();

    string temp2;
    while(getline(inputFile, temp2)) {
        stringSet.insert(temp2);
    }
    // end timing
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    
    // adding time into vector storing times
    times.push_back(duration.count());
    inputFile.clear();
    inputFile.seekg(0);

}
