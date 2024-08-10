#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char mostFrequentCharacter(string s) {
    vector<int> freq(26, 0);
    for(char ch: s) {
        freq[ch - 'a']++;
    }
    return max_element(freq.begin(), freq.end()) - freq.begin() + 'a';
}

int main() {
    string str;
    getline(cin, str);
    cout << mostFrequentCharacter(str) << endl;  // 프롬프트 메시지를 제거하여 입력과 출력을 간단히 합니다.
    return 0;
}