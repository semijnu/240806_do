#include <iostream>
using namespace std;

void fizzbuzz(int n) {
    for(int i = 1; i <= n; i++) {
        if (i % 15 == 0) 
            cout << "FizzBuzz ";
        else if (i % 5 == 0) 
            cout << "Buzz ";
        else if (i % 3 == 0) 
            cout << "Fizz ";
        else 
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    fizzbuzz(number);
    return 0;
}