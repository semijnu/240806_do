#include <iostream>
#include <string>
using namespace std;

string isPalindrome(string s) {
    string str = "";
    for(char c : s)
        if(isalpha(c))
            str += tolower(c);
            
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());

    if(str == rev_str)
        return "Yes";
    else
        return "No";
}

int main() {
    string s;
    getline(cin, s);
    cout << isPalindrome(s) << endl;
    return 0;
}