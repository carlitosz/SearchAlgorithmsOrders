#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <iostream>
#include <string>
using namespace std;

#include "GenerateData.h"

class LinearSearch {
    public:
        bool search(string findMe);
        void printFirst(int num) {
            for (int i = 0; i < num; ++i) {
                cout << "[" << i << "] " << searchArray[i] << endl;                
            }
        }

        LinearSearch() {};
        LinearSearch(int arraySize) {
            searchArray = generator.generateStrings(arraySize);
        }

    protected:
        GenerateData generator;

    private:
        int size;
        string* searchArray;
};

#endif /* LINEAR_SEARCH_H */