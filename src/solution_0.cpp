#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int primeSum(int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; ++i)
        if (isPrime(i))
            sum += i;
    return sum;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    cout << primeSum(num1, num2) << endl; 
    return 0;
}