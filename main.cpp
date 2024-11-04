// COMSC 210 | Ethan Dilk | Lab 26 Olympics
// Key change - using microseconds to track race time - when using milliseconds I was getting 0 for insert and delete
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
using namespace std::chrono;


void reading(int times[15][4][3], int run, vector<string>&, list<string>&, set<string>&);
void sorting(int times[15][4][3], int run, vector<string>&, list<string>&, set<string>&);
void inserting(int times[15][4][3], int run, vector<string>&, list<string>&, set<string>&);
void deleting(int times[15][4][3], int run, vector<string>&, list<string>&, set<string>&);

int main() {
    int times[15][4][3] = {0}; // 3D array to store times for 15 runs, 4 operations, 3 data structures
    int columnWidth = 15;

    // Run tests 15 times
    for (int run = 0; run < 15; ++run) {
        // Initialize vector, list, and set to be used in each race
        vector<string> testVec;
        list<string> testList;
        set<string> testSet;

        reading(times, run, testVec, testList, testSet);
        sorting(times, run, testVec, testList, testSet);
        inserting(times, run, testVec, testList, testSet);
        deleting(times, run, testVec, testList, testSet);
    }

    // Calculate and display average times
    cout << left << setw(columnWidth) << "Operation" << setw(columnWidth) << "Vector" << setw(columnWidth) << "List" << setw(columnWidth) << "Set" << endl;

    string operations[4] = {"Read", "Sort", "Insert", "Delete"};

    for (int op = 0; op < 4; ++op) {
        cout << left << setw(columnWidth) << operations[op];
        for (int ds = 0; ds < 3; ++ds) {
            int total = 0;
            for (int run = 0; run < 15; ++run) {
                total += times[run][op][ds];
            }
            cout << setw(columnWidth) << (total / 15); // Output average
        }
        cout << endl;
    }

    cout << "\nThank you for using the data structures race program!" << endl;
    return 0;
}

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

    // duration in microseconds
    auto duration = duration_cast<microseconds>(end - start);
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
    duration = duration_cast<microseconds>(end - start);
    
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
    duration = duration_cast<microseconds>(end - start);
    
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
    auto duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

    // Sorting LIST
    start = high_resolution_clock::now();

    sort(stringVec.begin(), stringVec.end());
    
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

    // Sorting SET - using -1 because set is already sorted
    times.push_back(-1);

}

void inserting(list<int> &times, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {

    // Inserting value in VECTOR
    auto start = high_resolution_clock::now();

    stringVec.insert(stringVec.begin() + (stringVec.size() / 2), "TESTCODE");
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

    // Inserting value in LIST
    start = high_resolution_clock::now();

    auto it = stringList.begin();
    advance(it, (stringList.size() / 2));
    stringList.insert(it, "TESTCODE");
    
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

    // Inserting value in SET
    start = high_resolution_clock::now();

    stringSet.insert("TESTCODE");
    
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

}

void deleting(list<int> &times, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {

    // Deleting value in VECTOR
    auto start = high_resolution_clock::now();

    stringVec.erase(stringVec.begin() + (stringVec.size() / 2));
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

    // Deleting value in LIST 
    start = high_resolution_clock::now();

    auto it = stringList.begin();
    advance(it, (stringList.size() / 2));
    stringList.erase(it);
    
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

    // Deleting value in SET 
    start = high_resolution_clock::now();

    auto it1 = stringSet.begin();
    advance(it1, (stringSet.size() / 2));
    stringSet.erase(it1);
    
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);

    times.push_back(duration.count());

} 

