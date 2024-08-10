#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
   // 여기에 코드를 작성하세요.
}

int sumOfPrimes(const vector<int>& arr) {
   // 여기에 코드를 작성하세요.
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