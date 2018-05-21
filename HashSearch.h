#ifndef HASH_SEARCH_H
#define HASH_SEARCH_H

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "GenerateData.h"

// ============================================================================
// User defined constants.
// ============================================================================

// ==== HashSearch ============================================================
// Executes search using hash table.
// ============================================================================
class HashSearch : public GenerateData {
    public:
        // ====================================================================
        // Constructor.
        // ====================================================================
        HashSearch(int listSize) {
            sizeOfList = listSize;

            cout << "Generating table of size " << listSize << endl;
            vector<vector<string> > table(listSize);
            for (int i = 0; i < listSize; ++i) {
                vector<string> newCol;
                table.push_back(newCol);
            }

            searchTable = table;

            cout << "Generating random strings..." << endl;
            vector<string> randoms = generateStringsAsVector(listSize);
            cout << "Finished generating random strings..." << endl;

            randomStrings = randoms;

            cout << "Populating the table with random strings" << endl;
            for (int i = 0; i < listSize; ++i) {
                int hash = generateHash(listSize, randoms[i]);
                insert(hash, randoms[i]);
            }
            cout << "The vector is ready for searching..." << endl;
        }

        // ====================================================================
        // Executes the hash table search.
        // ====================================================================
        void executeSearch(string key) {
            int hash = generateHash(sizeOfList, key);
            vector<string> temp = searchTable[hash];

            if (temp.size() > 0) {
                for (int i = 0; i < temp.size(); ++i) {
                    if (temp[i] == key) {
                        return;
                    }
                }
            }
        }

        // ====================================================================
        // Gets the test data from the GenerateData class.
        // ====================================================================
        vector<string> getTestData() {
            cout << "Generating test data set..." << endl;
            vector<string> temp =  generateTestDataAsVector(randomStrings, sizeOfList);
            cout << "Finished generating test data set..." << endl;

            return temp;
        }

    private:
        // ====================================================================
        // Attempts to insert into the hash table.
        // ====================================================================
        void insert(int index, string val) {
            searchTable[index].push_back(val);
        }


        // ====================================================================
        // Generates the hash.
        // ====================================================================
        int generateHash(int size, const string &str) {
           unsigned int seed = 131;
           unsigned int hash = 0;

           for(std::size_t i = 0; i < str.length(); i++) {
              hash = (hash * seed) + str[i];
           }

           return hash % size;
        }

        int sizeOfList;
        vector<vector<string> > searchTable;
        vector<string> randomStrings;
};

#endif /* HASH_SEARCH_H */

