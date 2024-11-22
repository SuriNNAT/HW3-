#include "HashTable2D.h"

HashTable2D::HashTable2D(int size, int bucketSize) : size(size), bucketSize(bucketSize) {
    table.resize(size, vector<int>(bucketSize, -1));
}

int HashTable2D::hashFunction(int x) {
    return x % size;
}

int HashTable2D::insert(int value) {
    int index = hashFunction(value);
    int spotsChecked = 0;

    for (int& slot : table[index]) {
        spotsChecked++;
        if (slot == -1) {
            slot = value;
            return spotsChecked;
        }
    }

    cout << "The value " << value << " cannot be inserted." << endl;
    return spotsChecked;
}

int HashTable2D::search(int value) {
    int index = hashFunction(value);
    int spotsChecked = 0;

    for (int slot : table[index]) {
        spotsChecked++;
        if (slot == value) {
            cout << "The value " << value << " can be found." << endl;
            return spotsChecked;
        }
    }

    cout << "The value " << value << " cannot be found." << endl;
    return spotsChecked;
}

int HashTable2D::remove(int value) {
    int index = hashFunction(value);
    int spotsChecked = 0;

    for (int& slot : table[index]) {
        spotsChecked++;
        if (slot == value) {
            slot = -1;
            cout << "The value " << value << " was removed." << endl;
            return spotsChecked;
        }
    }

    cout << "The value " << value << " cannot be removed." << endl;
    return spotsChecked;
}

void HashTable2D::print() {
    for (int i = 0; i < size; ++i) {
        cout << "Bucket " << i << ": ";
        for (int j = 0; j < bucketSize; ++j) {
            if (table[i][j] == -1)
                cout << "Empty ";
            else
                cout << table[i][j] << " ";
        }
        cout << endl;
    }
}
