#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int number1, number2;
    cin >> number1 >> number2;
    cout << "gcd: " << gcd(number1, number2) << ", " << "lcm: " << lcm(number1, number2) << endl;
    return 0;
}