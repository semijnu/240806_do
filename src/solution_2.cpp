#include <iostream>
using namespace std;

int difference(int a, int b) {
    return a - b;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << difference(num1, num2) << endl;  // Removed the prompt messages to simplify I/O.
    return 0;
}