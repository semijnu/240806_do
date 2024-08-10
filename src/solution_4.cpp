#include <iostream>
#include <string>
using namespace std;

string findLongestPalindrome(string str) {
    int len = str.size();
   
    for (int palindrome_len = len; palindrome_len > 1; --palindrome_len) {
        for (int i = 0; i + palindrome_len - 1 < len; ++i) {
            bool is_palindrome = true;
            for (int j = 0; j < palindrome_len / 2; ++j) {
                if (str[i + j] != str[i + palindrome_len - 1 - j]) {
                    is_palindrome = false;
                    break;
                }
            }
            
            if (is_palindrome)
                return str.substr(i, palindrome_len);
        }
    }
   
    return str.substr(0, 1);
}

int main() {
    string input;
    cin >> input;
    cout << findLongestPalindrome(input) << endl;
    return 0;
}