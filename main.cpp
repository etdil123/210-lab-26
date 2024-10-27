// COMSC 210 | Ethan Dilk | Lab 25 Races
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
using namespace std::chrono;


void reading(list<int> &times, vector<string>&, list<string>&, set<string>&);
void sorting(list<int> &times, vector<string>&, list<string>&, set<string>&);
void inserting(list<int> &times, vector<string>&, list<string>&, set<string>&);
void deleting(list<int> &times, vector<string>&, list<string>&, set<string>&);

int main() {
    
    // initialize lists to store scores
    list<int> readingTimes, sortingTimes, insertingTimes, deletingTimes;

    // Initialize vector, list, and set to be used in race
    vector<string> testVec;
    list<string> testList;
    set<string> testSet;

    reading(readingTimes, testVec, testList, testSet);


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

void sorting(list<int> &times, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {
    // Sorting VECTOR
    auto start = high_resolution_clock::now();

    sort(stringVec.begin(), stringVec.end());
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

    // Sorting LIST
    start = high_resolution_clock::now();

    sort(stringVec.begin(), stringVec.end());
    
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

    // Sorting SET - using -1 because set is already sorted
    times.push_back(-1);

}

void inserting(list<int> &times, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {

    // Inserting value in VECTOR
    auto start = high_resolution_clock::now();

    stringVec.insert(stringVec.begin() + (stringVec.size() / 2), "TESTCODE");
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

    // Inserting value in LIST
    start = high_resolution_clock::now();

    auto it = stringList.begin();
    advance(it, (stringList.size() / 2));
    stringList.insert(it, "TESTCODE");
    
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

    // Inserting value in SET
    start = high_resolution_clock::now();

    stringSet.insert("TESTCODE");
    
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

}

void deleting(list<int> &times, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {

    // Deleting value in VECTOR
    auto start = high_resolution_clock::now();

    stringVec.erase(stringVec.begin() + (stringVec.size() / 2));
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

    // Deleting value in LIST 
    start = high_resolution_clock::now();

    auto it = stringList.begin();
    advance(it, (stringList.size() / 2));
    stringList.erase(it);
    
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

    // Deleting value in SET 
    start = high_resolution_clock::now();

    auto it = stringSet.begin();
    advance(it, (stringSet.size() / 2));
    stringSet.erase(it);
    
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    times.push_back(duration.count());

} 

