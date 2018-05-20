#include <iostream>
#include <string>
using namespace std;

#include "LinearSearch.h"

const int MIN_SIZE = 1024;
const int MAX_SIZE = 33554432;

int main(void) {
    srand(static_cast<unsigned int>(time(0)));
    int arraySize = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;

    cout << "Creating array of size " << arraySize << " for Linear Search." << endl;
    LinearSearch linear(arraySize);

    return 0;
}