#include <iostream>
using namespace std;

int product(int a, int b) {
    return a * b;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << product(num1, num2) << endl;  // Remove the prompt message to make the input and output simpler.
    return 0;
}