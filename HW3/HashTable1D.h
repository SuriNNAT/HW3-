#ifndef HASHTABLE1D_H
#define HASHTABLE1D_H

#include <iostream>
using namespace std;

class HashTable1D {
private:
    int* table;
    int size;
    int count;

public:
    HashTable1D(int size = 500);
    ~HashTable1D();
    int hashFunction(int x);
    int insert(int value);
    int search(int value);
    int remove(int value);
    void print();
};

#endif // HASHTABLE1D_H

