#include <iostream>
#include <vector>
using namespace std;

vector<int> fibonacciGenerator(int a, int b) {
    vector<int> result;
    result.push_back(a);
    result.push_back(b);
    
    while(true){
        int temp = result[result.size() - 1] + result[result.size() - 2];
        if(temp <= 0)
            break;
        result.push_back(temp);
    }
    return result;
}

int main() {
    int number1, number2, n;
    while(true){
        cout << "Enter two numbers (0 0 to quit): ";
        cin >> number1 >> number2;
        if(number1 == 0 and number2 == 0)
            break;
        
        cout << "Enter an index n: ";
        cin >> n;
        
        vector<int> result = fibonacciGenerator(number1, number2);
        cout << "- The nth Fibonacci number is: " << result[n-1] << endl;
    }
    return 0;
}