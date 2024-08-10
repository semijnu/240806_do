#include <iostream>
#include <cmath> 
using namespace std;

void calculation(int a, int b) {
    if (a != 0) {
        cout << a * a << endl;    
    } else {
        cout << "sin(b): " << sin(b) << ", cos(b): " << cos(b) << ", tan(b): " << tan(b) << endl;
    }
}

int main() {
    int number1, number2;
    cin >> number1 >> number2;
    calculation(number1, number2);
    return 0;
}