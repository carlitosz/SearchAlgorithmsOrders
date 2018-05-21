# SearchAlgorithmsOrders
Use Linear, Binary, and Hash (chaining) search algorithms to determine the runtime of each search
algorithm with different sizes of N.

# How to use
1. You will see that there is commented code in the `main.cpp` file. If you want to run all 3 searches for the same `N`, uncomment all the code and compile. Otherwise, it's best to run one search per session to get faster results.

2. Please update the line `int arraySize = MAX_SIZE2XX;`, with a new `MAX_SIZE2XX`. This will be the size of N.
It is recommended that you use larger N for Binary and Hash searches. Linear searches will take a really long time to finish with large N.

3. Compile `main.cpp` and run the executable.

## Sample output using Hash Search:
```
Creating hash table of size 67108864.
Generating hash table of size 67108864
Generating random strings...
Finished generating random strings...
Populating the hash table with random strings...
The hash table is ready for searching...
Generating test data set...
Finished generating test data set...
Generated test data set of 67108864 elements.


Executing hash search ...

Elapsed time: 0 hour(s) 1 minute(s) 4 seconds 64774 milliseconds.
```

# Chart with output for N that I used
Linear is in Green.
Binary is in Red.
Hash is in Orange.

![alt text](https://github.com/carlitosz/SearchAlgorithmsOrders/blob/master/chart.png?raw=true)


# How to create your own graph
Log your N and Time, and create a graph of Time vs N. I used Google Spreadsheets for this.
