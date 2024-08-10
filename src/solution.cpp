#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers;

    for (int i = 0; i < 10; ++i) {
        int num;
        cin >> num;
        numbers.push_back(num);
    } 

    for (int i = 0; i < 10; ++i) {
         cout << numbers[i] << " ";
    }

    auto minmax = minmax_element(numbers.begin(), numbers.end());
    cout << "\nMinimum Element: " << *minmax.first;
    cout << "\nMaximum Element: " << *minmax.second;

    return 0;
}