#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}

int main() {
    string input;
    getline(cin, input);
    cout << (isPalindrome(input) ? "true" : "false") << endl;  
    return 0;
}