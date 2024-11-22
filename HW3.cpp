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
    cout << insert_1 << " " << insert_2;

}
