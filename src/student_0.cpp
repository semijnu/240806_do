#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(vector<int>& seq) {
    // 여기에 코드를 작성하세요.
}

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    cout << longest_increasing_subsequence(seq) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    return 0;
}