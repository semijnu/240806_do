#include <iostream>
using namespace std;

int fib(int n) {
    // 여기에 코드를 작성하세요.
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    for (int i = 0; i <= number; i++) {
        cout << fib(i) << " ";
    }
    return 0;
}