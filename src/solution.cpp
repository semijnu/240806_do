#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int sumOfPrimes(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        if (isPrime(num)) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    int n;
    vector<int> arr(n);

    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Sum of primes is " << sumOfPrimes(arr) << endl;
    return 0;
}