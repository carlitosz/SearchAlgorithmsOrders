#include <iostream>
#include <string>
#include <chrono>
using namespace std;

// ============================================================================
// User defined libraries
// ============================================================================
#include "LinearSearch.h"

// ============================================================================
// User defined constants used to test different N.
// ============================================================================
const int MAX_SIZE210 = 1024; // 2^10
const int MAX_SIZE213 = 8192; // 2^13
const int MAX_SIZE214 = 16384; // 2^14
const int MAX_SIZE215 = 32768; // 2^15
const int MAX_SIZE216 = 65536; // 2^16
const int MAX_SIZE217 = 131072; // 2^17
const int MAX_SIZE218 = 262144; // 2^18
const int MAX_SIZE219 = 524288; // 2^19

// ============================================================================
// Function prototypes.
// ============================================================================
void printLinear(string*, int);
void printResults(int);

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

    cout << "Array of size " << arraySize << " has been created." << endl;

    string *testData = linear.getTestData();
    auto started = std::chrono::high_resolution_clock::now();

    // Test linear search.
    cout << endl << endl << "Executing linear search ... " << endl << endl;
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
    // ==== End of Binary Search ==============================================
    
    return 0;
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
void print(string *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "[" << i << "] " << arr[i] << endl;                
    }
}