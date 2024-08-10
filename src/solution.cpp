#include <iostream>
using namespace std;

int dp[41]; 

int fib(int n) {
    if (n <= 1) {
        return n;
    } else if (dp[n] != 0) {
        return dp[n];
    } else {
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
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