#ifndef HASHTABLE2D_H
#define HASHTABLE2D_H

#include <iostream>
#include <vector>
using namespace std;

class HashTable2D {
private:
    vector<vector<int>> table;
    int size;
    int bucketSize;

public:
    HashTable2D(int size = 100, int bucketSize = 5);
    int hashFunction(int x);
    int insert(int value);
    int search(int value);
    int remove(int value);
    void print();
};

#endif // HASHTABLE2D_H

