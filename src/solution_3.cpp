#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n < 1)
        return -1;
    else if (n == 1 || n == 2)
        return 1;
    else {
        int a = 1, b = 1, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main() {
    int num;
    cin >> num;
    int result = fibonacci(num);
    if (result != -1)
        cout << result << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    else
        cout << "잘못된 입력" << endl;
    return 0;
}