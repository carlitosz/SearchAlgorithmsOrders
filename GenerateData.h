#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include <iostream>
#include <string>
using namespace std;

const int STRING_SIZE = 20;
const string CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}|";

class GenerateData {
    public:
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

        string *generateTestData(string *sample, int sampleSize) {
            string *testData = new string[sampleSize];

            for (int i = 0; i < sampleSize; ++i) {
                testData[i] = (i % 2 == 0) ? generateString() : sample[i];
            }

            return testData;
        }

    private:
        string generateString() {
            string randomStr = "";

            for(int i = 0; i < STRING_SIZE; i++) {
                randomStr += CHARS[rand() % CHARS.size()];
            }

            return randomStr;
        }
};

#endif /* GENERATE_DATA_H */