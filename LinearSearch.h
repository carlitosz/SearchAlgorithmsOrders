#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <iostream>
#include <string>
using namespace std;

#include "GenerateData.h"

class LinearSearch : public GenerateData {
    public:
        void executeSearch(string str) {
            for (int i = 0; i < size; ++i) {
                if (searchArray[i] == str) {
                    return;
                }
            }
        }

        string *getTestData() {
            cout << "Generating test data..." << endl;
            string* testData = generateTestData(searchArray, size);
            cout << "Finished generating test data..." << endl;

            return testData;
        }

        // Overloaded Constructor.
        LinearSearch(int arraySize) {
            size = arraySize;
            cout << "Populating array with random strings..." << endl;
            searchArray = generateStrings(arraySize);
            cout << "Finished populating array..." << endl;
        }

        // Destructor.
        ~LinearSearch() { delete [] searchArray; }
    private:
        int size;
        string *searchArray;
};

#endif /* LINEAR_SEARCH_H */