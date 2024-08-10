#include<iostream>
using namespace std;

int andOperation(int a, int b) {
    return a & b;
}

int orOperation(int a, int b) {
    return a | b;
}

int xorOperation(int a, int b) {
    return a ^ b;
}

int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "AND operation: " << andOperation(num1, num2) << endl;
    cout << "OR operation: " << orOperation(num1, num2) << endl;
    cout << "XOR operation: " << xorOperation(num1, num2) << endl;
    return 0;
}