#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_balanced(string input) {
    stack<char> brackets;
    for (char c : input) {
        switch (c) {
            case '(' : case '[' :
                brackets.push(c);
                break;
            case ')' :
                if (brackets.empty() || brackets.top() != '(')
                    return false;
                brackets.pop();
                break;
            case ']' :
                if (brackets.empty() || brackets.top() != '[')
                    return false;
                brackets.pop();
                break;
        }
    }
    return brackets.empty();
}

int main() {
    string input;
    getline(cin, input);
    cout << (is_balanced(input) ? "YES" : "NO") << endl;
    return 0;
}