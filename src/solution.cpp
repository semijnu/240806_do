#include <iostream>
using namespace std;

long long fibonacci(int n) {
    long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
         fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n];
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "The " << number << "th fibonacci number is: " << fibonacci(number) << endl;
    return 0;
}