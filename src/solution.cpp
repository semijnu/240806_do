#include <iostream>
#include <iomanip>
using namespace std;

double calculate(int a, int b, string op) {
    if(op == "+") return a + b;
    else if(op == "-") return a - b;
    else if(op == "*") return a * b;
    else if(op == "/") {
        if(b == 0){
            cout << "오류: 0으로 나눌 수 없습니다." << endl;
            return 0;
        }
        else return (double)a / b;   
    }
    else return 0;
}

int main() {
    int num1, num2;
    string oper;
    cout << "Enter two numbers and an operator: ";
    cin >> num1 >> num2 >> oper;
    double res = calculate(num1, num2, oper);
    if(res != 0) cout << "The result is: " << setprecision(2) << fixed << res << endl;
    return 0;
}