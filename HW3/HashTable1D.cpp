#include "HashTable1D.h"

HashTable1D::HashTable1D(int size) : size(size), count(0) {
    table = new int[500];
    fill(table, table + size, -1);
}

HashTable1D::~HashTable1D() {
    delete[] table;
}

int HashTable1D::hashFunction(int x) {
    return x % 500;
}

int HashTable1D::insert(int value) {
    int index = hashFunction(value);
    int spotsChecked = 0;

    while (spotsChecked < size) {
        if (table[index] == -1) {
            table[index] = value;
            return spotsChecked + 1;
        }
        index = (index + 1) % size;
        spotsChecked++;
    }

    cout << "The value " << value << " cannot be inserted." << endl;
    return spotsChecked;
}

int HashTable1D::search(int value) {
    int index = hashFunction(value);
    int spotsChecked = 0;

    while (spotsChecked < size) {
        if (table[index] == value) {
            cout << "The value " << value << " can be found." << endl;
            return spotsChecked + 1;
        }
        if (table[index] == -1) break;
        index = (index + 1) % size;
        spotsChecked++;
    }

    cout << "The value " << value << " cannot be found." << endl;
    return spotsChecked;
}

int HashTable1D::remove(int value) {
    int index = hashFunction(value);
    int spotsChecked = 0;

    while (spotsChecked < size) {
        if (table[index] == value) {
            table[index] = -1;
            cout << "The value " << value << " was removed." << endl;
            return spotsChecked + 1;
        }
        if (table[index] == -1) break;
        index = (index + 1) % size;
        spotsChecked++;
    }

    cout << "The value " << value << " cannot be removed." << endl;
    return spotsChecked;
}

void HashTable1D::print() {
    for (int i = 0; i < size; ++i) {
        if (table[i] == -1)
            cout << "Slot " << i << ": Empty" << endl;
        else
            cout << "Slot " << i << ": " << table[i] << endl;
    }
}
