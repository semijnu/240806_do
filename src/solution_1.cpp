#include <iostream>
using namespace std;

string isPrime(int n) {
    if (n <= 1) {
        return "NO";
    }

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int num;
    cin >> num;
    cout << isPrime(num) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    return 0;
}