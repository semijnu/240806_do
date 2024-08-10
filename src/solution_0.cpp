#include <iostream>
#include <iomanip>
using namespace std;

double calculation(double a, double b, char op) {
    switch(op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

int main() {
    double number1, number2;
    cin >> number1 >> number2;
    cout << fixed << setprecision(1);
    cout << "Sum: " << calculation(number1, number2, '+') << endl;
    cout << "Subtraction: " << calculation(number1, number2, '-') << endl;
    cout << "Multiplication: " << calculation(number1, number2, '*') << endl;
    cout << "Division: " << calculation(number1, number2, '/') << endl;
    return 0;
}