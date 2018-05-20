#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "GenerateData.h"


// ============================================================================
// Executes linear searches for arrays of size N.
// ============================================================================
class LinearSearch : public GenerateData {
    public:
        // ====================================================================
        // Executes the linear search algorithm.
        // ====================================================================
        void executeSearch(string str) {
            for (int i = 0; i < size; ++i) {
                if (searchArray[i] == str) {
                    return;
                }
            }
        }

        // ====================================================================
        // Gets test data from the GenerateData class.
        // ====================================================================
        string *getTestData() {
            cout << "Generating test data..." << endl;
            string* testData = generateTestData(searchArray, size);
            cout << "Finished generating test data..." << endl;

            return testData;
        }

        // ====================================================================
        // Constructs new objects of LinearSearch by populating them with
        // random strings.
        // ====================================================================
        LinearSearch(int arraySize) {
            size = arraySize;
            cout << "Populating array with random strings..." << endl;
            searchArray = generateStrings(arraySize);
            cout << "Finished populating array..." << endl;
        }

        // ====================================================================
        // Destructor.
        // ====================================================================
        ~LinearSearch() { delete [] searchArray; }
    private:
        int size;
        string *searchArray;
};

#endif /* LINEAR_SEARCH_H */