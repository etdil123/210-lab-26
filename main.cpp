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

    cout << "Number of simulations: 15" << endl;
    // for each operation
    for (int op = 0; op < 4; ++op) {
        cout << left << setw(columnWidth) << operations[op];
        // for each data structure
        for (int ds = 0; ds < 3; ++ds) {
            int total = 0;
            for (int run = 0; run < 15; ++run) {
                // run through each element in 3d array
                total += times[run][op][ds];
            }
            // output the average
            cout << setw(columnWidth) << (total / 15); 
        }
        cout << endl;
    }

    cout << "\nThank you for using the data structures olympic program!" << endl;
    return 0;
}

void reading(int times[15][4][3], int run, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {
    ifstream inputFile("codes.txt");
    string temp;

    // Reading into VECTOR
    auto start = high_resolution_clock::now();
    while(getline(inputFile, temp)) {
        stringVec.push_back(temp);
    }
    auto end = high_resolution_clock::now();
    times[run][0][0] = duration_cast<microseconds>(end - start).count();
    inputFile.clear();
    inputFile.seekg(0);

    // Reading into LIST
    start = high_resolution_clock::now();
    while(getline(inputFile, temp)) {
        stringList.push_back(temp);
    }
    end = high_resolution_clock::now();
    times[run][0][1] = duration_cast<microseconds>(end - start).count();
    inputFile.clear();
    inputFile.seekg(0);

    // Reading into SET
    start = high_resolution_clock::now();
    while(getline(inputFile, temp)) {
        stringSet.insert(temp);
    }
    end = high_resolution_clock::now();
    times[run][0][2] = duration_cast<microseconds>(end - start).count();
}

void sorting(int times[15][4][3], int run, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {
    // Sorting VECTOR
    auto start = high_resolution_clock::now();
    sort(stringVec.begin(), stringVec.end());
    auto end = high_resolution_clock::now();
    times[run][1][0] = duration_cast<microseconds>(end - start).count();

    // Sorting LIST
    start = high_resolution_clock::now();
    stringList.sort();
    end = high_resolution_clock::now();
    times[run][1][1] = duration_cast<microseconds>(end - start).count();

    // Sorting SET - use -1 because set is already sorted
    times[run][1][2] = -1;
}

void inserting(int times[15][4][3], int run, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {
    // Inserting into VECTOR
    auto start = high_resolution_clock::now();
    stringVec.insert(stringVec.begin() + (stringVec.size() / 2), "TESTCODE");
    auto end = high_resolution_clock::now();
    times[run][2][0] = duration_cast<microseconds>(end - start).count();

    // Inserting into LIST
    start = high_resolution_clock::now();
    auto it = stringList.begin();
    advance(it, (stringList.size() / 2));
    stringList.insert(it, "TESTCODE");
    end = high_resolution_clock::now();
    times[run][2][1] = duration_cast<microseconds>(end - start).count();

    // Inserting into SET
    start = high_resolution_clock::now();
    stringSet.insert("TESTCODE");
    end = high_resolution_clock::now();
    times[run][2][2] = duration_cast<microseconds>(end - start).count();
}

void deleting(int times[15][4][3], int run, vector<string>& stringVec, list<string>& stringList, set<string>& stringSet) {
    // Deleting from VECTOR
    auto start = high_resolution_clock::now();
    stringVec.erase(stringVec.begin() + (stringVec.size() / 2));
    auto end = high_resolution_clock::now();
    times[run][3][0] = duration_cast<microseconds>(end - start).count();

    // Deleting from LIST
    start = high_resolution_clock::now();
    auto it = stringList.begin();
    advance(it, (stringList.size() / 2));
    stringList.erase(it);
    end = high_resolution_clock::now();
    times[run][3][1] = duration_cast<microseconds>(end - start).count();

    // Deleting from SET
    start = high_resolution_clock::now();
    auto it1 = stringSet.begin();
    advance(it1, (stringSet.size() / 2));
    stringSet.erase(it1);
    end = high_resolution_clock::now();
    times[run][3][2] = duration_cast<microseconds>(end - start).count();
}