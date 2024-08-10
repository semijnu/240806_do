정답 코드
#include <iostream>
using namespace std;

int calculateEvenFibonacciSum(int N) {
    int first = 1, second = 2, sum = 0;
    while (second <= N) {
        if (second % 2 == 0) {
            sum += second;
        }
        int temp = first;
        first = second;
        second = first + temp;
    }
    return sum;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    cout << "Sum: " << calculateEvenFibonacciSum(N) << endl;
    return 0;
}