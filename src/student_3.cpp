#include <iostream>
#include <vector>
using namespace std;

vector<int> sortNumbers(int n, vector<int> nums) {
    // 여기에 코드를 작성하세요.
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    vector<int> sorted_nums = sortNumbers(n, nums);
    for(int i=0; i<n; i++){
        cout << sorted_nums[i] << " ";
    }
    cout << endl;
    return 0;
}