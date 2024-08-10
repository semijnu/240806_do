#include <iostream>
#include <string>
using namespace std;

bool validateBrackets(string str, int index, int counter) {
    if (index == str.size()) {
        return counter == 0;
    } else if (counter < 0) {
        return false;
    } else {
        return (str[index] == '(') ?
            validateBrackets(str, index + 1, counter + 1)
            : (str[index] == ')') ?
            validateBrackets(str, index + 1, counter - 1)
            : validateBrackets(str, index + 1, counter);
    }
}

int main() {
    string inputString;
    cout << "Enter a string: ";
    cin >> inputString;
    bool result = validateBrackets(inputString, 0, 0);
    cout << "The brackets in your string are: " << (result ? "Balanced" : "Not Balanced") << endl;
    return 0;
}