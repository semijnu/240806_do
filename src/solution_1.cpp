#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << sum(num1, num2) << endl;  // Simplify input and output by removing the prompt message.
    return 0;
}