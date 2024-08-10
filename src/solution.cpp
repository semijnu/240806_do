#include <iostream>
#include <string>
using namespace std;

string createString(int n) {
    string result = "";
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            result += "prime ";
        } else {
            result += "composite ";
        }
    }
    return result;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    string answer = createString(number);
    cout << "The sequence is: " << answer << endl;
    return 0;
}