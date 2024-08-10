#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortNumbers(vector<int> numbers) {
  sort(numbers.begin(), numbers.end());
  return numbers;
}

int main() {
  vector<int> numbers;
  int number;

  cout << "Enter numbers (finish input by entering an empty line): " << endl;
  
  while (cin >> number)
    numbers.push_back(number);

  numbers = sortNumbers(numbers);

  cout << "Sorted numbers are: ";
  
  for (int i = 0; i < numbers.size(); i++)
    cout << numbers[i] << " ";
    
  return 0;
}