#include <iostream>
#include <iomanip>
using namespace std;

double calculation(double a, double b) {
    // 여기에 코드를 작성하세요.
}

int main() {
    double number1, number2;
    cin >> number1 >> number2;
    cout << fixed << setprecision(1);
    cout << "Sum: " << calculation(number1, number2);
    cout << "Subtraction: " << calculation(number1, number2);
    cout << "Multiplication: " << calculation(number1, number2);
    cout << "Division: " << calculation(number1, number2);
    return 0;
}