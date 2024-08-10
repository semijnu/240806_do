#include <iostream>
using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cin >> num;
    cout << factorial(num) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    return 0;
}