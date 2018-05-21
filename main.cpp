#include <iostream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

// ============================================================================
// User defined libraries
// ============================================================================
#include "HashSearch.h"
#include "LinearSearch.h"
#include "BinarySearch.h"

// ============================================================================
// User defined constants used to test different N.
// ============================================================================
// These sizes are more appropriate for Linear search
const int MAX_SIZE210 = 1024; // 2^10
const int MAX_SIZE213 = 8192; // 2^13
const int MAX_SIZE214 = 16384; // 2^14
const int MAX_SIZE215 = 32768; // 2^15
const int MAX_SIZE216 = 65536; // 2^16
const int MAX_SIZE217 = 131072; // 2^17
const int MAX_SIZE218 = 262144; // 2^18
const int MAX_SIZE219 = 524288; // 2^19

// These sizes are more appropriate for Binary search and Hash search
const int MAX_SIZE220 = 1048576; // 2^20
const int MAX_SIZE221 = 2097152; // 2^21
const int MAX_SIZE222 = 4194304; // 2^22
const int MAX_SIZE223 = 8388608; // 2^23
const int MAX_SIZE224 = 16777216; // 2^24
const int MAX_SIZE225 = 33554432; // 2^25
const int MAX_SIZE226 = 67108864; // 2^26
const int MAX_SIZE227 = 134217728; // 2^27

// ============================================================================
// Function prototypes.
// ============================================================================
void printObj(string*, int);
void printVec(vector<string>, int);
void printResults(int);
void printArraySize(int);
void printSearchType(string);

// ============================================================================
// Main.
// ============================================================================
int main(void) {
    srand(static_cast<unsigned int>(time(0)));

    // ========================================================================
    // Change the MAX_SIZE variable to test different N.
    // ========================================================================
    int arraySize = MAX_SIZE210;

    // ==== Linear Search =====================================================
    LinearSearch linear(arraySize);
    printArraySize(arraySize);

    string *testData = linear.getTestData();
    auto started = std::chrono::high_resolution_clock::now();

    // Test linear search.
    printSearchType("linear");
    for (int i = 0; i < arraySize; ++i) {
        linear.executeSearch(testData[i]);
    }

    auto done = std::chrono::high_resolution_clock::now();
    int milliseconds = 
        std::chrono::duration_cast<std::chrono::milliseconds>
        (done - started).count();

    printResults(milliseconds);
    // ==== End of Linear Search ==============================================



    // ==== Binary Search =====================================================
    // printArraySize(arraySize);
    // BinarySearch binary(arraySize);

    // vector<string> testData = binary.getTestData();
    // cout << "Generated test data set of "
    //      << testData.size() << " elements." << endl;

    // auto started = std::chrono::high_resolution_clock::now();

    // // Test binary search.
    // printSearchType("binary");

    // for (int i = 0; i < arraySize; ++i) {
    //     int ignore = binary.executeSearch(0, arraySize - 1, testData[i]);
    // }

    // auto done = std::chrono::high_resolution_clock::now();
    // int milliseconds = 
    //     std::chrono::duration_cast<std::chrono::milliseconds>
    //     (done - started).count();

    // printResults(milliseconds);
    // ==== End of Binary Search ==============================================

    

    // ==== Hash Search =======================================================
    // printArraySize(arraySize);
    // HashSearch hash(arraySize);

    // vector<string> testData = hash.getTestData();
    // cout << "Generated test data set of "
    //      << testData.size() << " elements." << endl;

    // auto started = std::chrono::high_resolution_clock::now();
    // printSearchType("hash");

    // // Test hash search.
    // for (int i = 0; i < testData.size(); ++i) {
    //     hash.executeSearch(testData[i]);
    // }

    // auto done = std::chrono::high_resolution_clock::now();
    // int milliseconds =
    //     std::chrono::duration_cast<std::chrono::milliseconds>
    //     (done - started).count();

    // printResults(milliseconds);
    // ==== End of Hash Search ================================================
    
    return 0;
}

// ============================================================================
// Prints the search type.
// ============================================================================
void printSearchType(string type) {
    cout << endl << endl
         << "Executing " << type << " search ... "
         << endl << endl;
}

// ============================================================================
// Prints the array size.
// ============================================================================
void printArraySize(int size) {
    cout << "Creating array of size " << size << "." << endl;
}

// ============================================================================
// Prints the results to stdout.
// ============================================================================
void printResults(int milliseconds) {
    int seconds = (int) (milliseconds / 1000) % 60 ;
    int minutes = (int) ((milliseconds / (1000*60)) % 60);
    int hours   = (int) ((milliseconds / (1000*60*60)) % 24);

    cout << "Elapsed time: "
         << hours << " hour(s) "
         << minutes << " minute(s) "
         << seconds << " seconds "
         << milliseconds << " milliseconds."
         << endl;
}

// ============================================================================
// Debug purposes.
// ============================================================================
void printVec(vector<string> vec, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "[" << i << "] " << vec[i] << endl;
    }
}

void printObj(string *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "[" << i << "] " << arr[i] << endl;                
    }
}
