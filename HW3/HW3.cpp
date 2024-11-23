#include<cstdlib>
#include <iostream>
#include <ctime>
#include <unordered_set>
#include "HashTable1D.h"
#include "HashTable2D.h"

using namespace std;

int randomNumber() {
    return 1 + (rand() % (1000));
}
int main()
{
    //initialize the array
    int dataset[100];
    unordered_set<int> unique_numbers;

    //hash tables
    HashTable1D hash1(500);
    HashTable2D hash2(500);

    //generate the number and save to the array
    srand(time(0));
    for (int i = 0; i < 100; ) {
        int num = randomNumber();
        if (unique_numbers.find(num) == unique_numbers.end()) {
            dataset[i] = num;
            unique_numbers.insert(num);
            ++i;
        }
    }

    //1st insertion
    int insert_1 = 0;
    int insert_2 = 0;
    for (int i = 0; i < 50; i++) {
        insert_1 += hash1.insert(dataset[i]);
        insert_2 += hash2.insert(dataset[i]);
    }

    cout << "The checked operations in both hash table in 1st insertion are at follow: ";
    cout << insert_1 << " " << insert_2 << endl;

    //1st removal
    int remove_1 = 0;
    int remove_2 = 0;

    for (int i = 0; i < 50; i++) {
        if (dataset[i] % 7 == 0) {
            remove_1 += hash1.remove(dataset[i]);
            remove_2 += hash2.remove(dataset[i]);
        }
    }

    cout << "The checked operations in both hash table in 1st removal are at follow: ";
    cout << remove_1 << " " << remove_2 << endl;

    //2nd insertion
    insert_1 = 0;
    insert_2 = 0;
    for (int i = 0; i < 50; i++) {
        insert_1 += hash1.insert(dataset[i]);
        insert_2 += hash2.insert(dataset[i]);
    }

    cout << "The checked operations in both hash table in 2nd insertion are at follow: ";
    cout << insert_1 << " " << insert_2 << endl;

    //2nd removal
    remove_1 = 0;
    remove_2 = 0;

    for (int i = 0; i < 50; i++) {
        if (dataset[i] % 9 == 0) {
            remove_1 += hash1.remove(dataset[i]);
            remove_2 += hash2.remove(dataset[i]);
        }
    }

    cout << "The checked operations in both hash table in 2nd removal are at follow: ";
    cout << remove_1 << " " << remove_2 << endl;

}
