#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "GenerateData.h"

// ============================================================================
// Executes binary search on an array of random strings of size N.
// ============================================================================
class BinarySearch : public GenerateData {
    public:
        // ====================================================================
        // Executes the binary search algorithm.
        // ====================================================================
        void executeSearch() {

        }

        // ====================================================================
        // Gets test data from the GenerateData class.
        // ====================================================================
        // string *getTestData() {
        //     cout << "Generating test data..." << endl;
        //     string *testData = generateTestData(searchArray, size);
        //     cout << "Finished generating test data..." << endl;

        //     return testData;
        // }

        // ====================================================================
        // Constructs new objects of type BinarySearch by populating them with
        // random strings.
        // ====================================================================
        BinarySearch(int arraySize) {
            size = arraySize;
            cout << "Populating array with random strings..." << endl;
            searchArray = generateStringsAsVector(arraySize);
            cout << "Finished populating array..." << endl << endl;
        }

        // ====================================================================
        // Destructor.
        // ====================================================================
        BinarySearch() { }
    private:
        int size;
        vector<string> searchArray;
};

#endif /* BINARY_SEARCH_H */