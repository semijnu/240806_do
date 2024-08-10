정답 코드
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string str) {
    string copystr = str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    reverse(str.begin(), str.end());
    return (copystr == str);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if (isPalindrome(str))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;

    return 0;
}