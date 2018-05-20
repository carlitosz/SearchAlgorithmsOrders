#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ============================================================================
// User defined constants.
// ============================================================================
const int STRING_SIZE = 20;
const string CHARS = "abcdefghijklmnopqrstuvwxyz";


// ==== Generate data ==========================================================
// Generates data and test data for the linear, binary, and hash searches.
// =============================================================================
class GenerateData {
    public:
        // ====================================================================
        // Generates an array of random strings of size sizeofArray
        // ====================================================================
        string *generateStrings(int sizeOfArray) {
            string str = "";
            string *randomStrings = new string[sizeOfArray];

            for (int i = 0; i < sizeOfArray; ++i) {
                for(int j = 0; j < STRING_SIZE; j++) {
                    str += CHARS[rand() % CHARS.size()];
                }
                randomStrings[i] = str;
                str = "";
            }

            return randomStrings;
        }

        // ====================================================================
        // Generates vector of random strings of size sizeArray
        // ====================================================================
        vector<string> generateStringsAsVector(int sizeOfArray) {
            string str = "";
            vector<string> randomStrings(sizeOfArray);

            for (int i = 0; i < sizeOfArray; ++i) {
                for (int j = 0; j < STRING_SIZE; ++j) {
                    str += CHARS[rand() % CHARS.size()];
                }
                randomStrings.at(i) = str;
                str = "";
            }

            sort(randomStrings.begin(), randomStrings.begin() + 20);

            return randomStrings;
        }

        // ====================================================================
        // Generates test data of size sampleSize.
        // Half of the strings from sample are joined with
        // random strings so that the test data contains 1/2
        // data from the original sample and 1/2 random data.
        // ====================================================================
        string *generateTestData(string *sample, int sampleSize) {
            string *testData = new string[sampleSize];

            for (int i = 0; i < sampleSize; ++i) {
                testData[i] = (i % 2 == 0) ? generateString() : sample[i];
            }

            return testData;
        }

    private:
        // ====================================================================
        // Generates a single random string.
        // ====================================================================
        string generateString() {
            string randomStr = "";

            for(int i = 0; i < STRING_SIZE; i++) {
                randomStr += CHARS[rand() % CHARS.size()];
            }

            return randomStr;
        }
};

#endif /* GENERATE_DATA_H */
