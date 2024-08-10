#include <iostream>
using namespace std;

int fibonacci(int n) {
    // 여기에 코드를 작성하세요.
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