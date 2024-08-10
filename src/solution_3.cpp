#include <iostream>
#include <vector>
using namespace std;

vector<int> sortNumbers(int n, vector<int> nums) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    return nums;
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