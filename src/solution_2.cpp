#include <iostream>
using namespace std;

int calculate_polynomial(int n) {
    int sum = 0;
    for(int i=0; i<=n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << calculate_polynomial(n) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    return 0;
}