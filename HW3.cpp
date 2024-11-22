#include<cstdlib>
#include <iostream>
#include <ctime>
#include <unordered_set>

using namespace std;

int randomNumber() {
    return 1 + (rand() % (1000));
}
int main()
{
    //initialize the array
    int dataset[100];
    unordered_set<int> unique_numbers;

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

}
