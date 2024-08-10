#include <iostream>
using namespace std;

void findPerfectNumbers(int a, int b) {
    for (int i = a; i <= b; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0)
                sum += j;
        }
        if (sum == i)
            cout << i << " is a perfect number." << endl;
    }
}

int main() {
    int start, end;
    cout << "Enter the start and end: ";
    cin >> start >> end;
    findPerfectNumbers(start, end);
    return 0;
}