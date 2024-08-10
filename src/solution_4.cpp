#include <iostream>
using namespace std;

int maxOfThree(int a, int b, int c) {
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    cout << maxOfThree(num1, num2, num3) << endl;  // Simplify the input and output by removing the prompt message.
    return 0;
}