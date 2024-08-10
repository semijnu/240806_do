#include <iostream>
using namespace std;

int difference(int a, int b) {
    return a - b;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << difference(num1, num2) << endl;  // The prompt message is removed to simplify input and output.
    return 0;
}