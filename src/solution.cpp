#include <iostream>
using namespace std;

struct Bucket {
    int size;
    int* items;
};

int searchBucket(Bucket* bucket, int value) {
    for(int i = 0; i < bucket->size; i++) {
        if(bucket->items[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    Bucket* bucket = new Bucket;
    bucket->size = 10;
    bucket->items = new int[10]{1, 2, 3, 5, 7, 8, 11, 15, 20, 25};

    cout << "Index of 5: " << searchBucket(bucket, 5) << "\n"; // 3
    cout << "Index of 20: " << searchBucket(bucket, 20) << "\n"; // 8
    cout << "Index of 6: " << searchBucket(bucket, 6) << "\n"; // -1

    delete[] bucket->items;
    delete bucket;
    return 0;
}