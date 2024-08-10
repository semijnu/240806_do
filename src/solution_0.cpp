#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(vector<int>& seq) {
    vector<int> lis(seq.size(), 1);
    for(int i = 1; i < seq.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(seq[j] < seq[i])
                lis[i] = max(lis[i], lis[j]+1);
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    cout << longest_increasing_subsequence(seq) << endl;  // 프롬프트 메시지를 표시하는 프롬프트를 제거하여 입력과 출력을 간단히 합니다.
    return 0;
}