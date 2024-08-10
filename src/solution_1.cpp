#include <iostream>

long long fibonacci(int n) {
    long long fib[51];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;
    return 0;
}