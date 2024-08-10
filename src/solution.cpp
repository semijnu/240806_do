#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int p) {
    for(int i = 2; i * i <= p; ++i) {
        if (p % i == 0) return false;
    }
    return true;
}

long long power(int a, int p, int mod) {
    long long ret = 1;
    while(p) {
        if(p%2) ret = ret * a % mod;
        a = (1LL * a * a) % mod;
        p /= 2;
    }
    return ret;
}

vector<int> fermatTheorem(int a) {
    vector<int> results;
    for(int p = 2; p <= 10000; ++p) {
        if (!isPrime(p)) continue;
        if (power(a, p-1, p) == 1) results.push_back(p);
    }
    return results;
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;
    vector<int> results = fermatTheorem(a);
    for (int i = 0; i < results.size(); ++i) {
        cout << "The number " << a << " and prime number " << results[i] << " satisfy Fermat's theorem." << endl;
    }
    return 0;
}