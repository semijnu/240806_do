#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primeRange(int n, vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<int> result;
    for(int num = nums[0]; num <= nums[n-1]; num++){
        bool prime = true;
        if(num < 2) prime = false;
        for(int i=2; i*i<=num; i++) {
            if(num % i == 0){
                prime = false;
                break;
            }
        }
        if(prime) result.push_back(num);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> result = primeRange(n, nums);
    for(int i : result){
        cout << i << endl; 
    }
    return 0;
}