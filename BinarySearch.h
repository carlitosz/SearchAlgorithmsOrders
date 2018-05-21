#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <vector>
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
        int executeSearch(int first, int last, string target) {
            int position = -1;

            while (first <= last) {
                int middle = (first + last) / 2;

                if (searchArray[middle] == target) {
                    position = middle;
                    break;
                }

                else if (searchArray[middle] > target) {
                    last = middle - 1;
                }

                else {
                    first = middle + 1;
                }
            }

            return position;
        }

        // ====================================================================
        // Gets test data from the GenerateData class.
        // ====================================================================
        vector<string> getTestData() {
            cout << "Generating test data..." << endl;
            vector<string> testData = generateTestDataAsVector(searchArray, size);
            cout << "Finished generating test data..." << endl;

            return testData;
        }

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
        // Debug purposes.
        // ====================================================================
        void print(int size) {
            for (int i = 0; i < size; ++i) {
                cout << "[" << i << "] " << searchArray[i] << endl;
            }
        }
    private:
        int size;
        vector<string> searchArray;
};

#endif /* BINARY_SEARCH_H */
