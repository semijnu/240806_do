#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

vector<string> CombinationSumsToBinary(vector<int> nums) {
    sort(nums.begin(), nums.end());
    
    vector<int> sums;
    int sum;
    for (int i = 0; i < pow(2, nums.size()); ++i) {
        sum = 0;
        for (int j = 0; j < nums.size(); ++j)
            if ((i & (1 << j)) != 0)
                sum += nums[j];
        sums.push_back(sum);
    }
    
    sort(sums.begin(), sums.end());
    
    vector<string> binaries;
    for(auto& sum : sums)
        binaries.push_back(bitset<32>(sum).to_string());
    
    return binaries;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> nums(N);
    
    for(int i = 0; i < N; i++)
        cin >> nums[i];
    
    vector<string> result = CombinationSumsToBinary(nums);
    
    for (const string& binary : result)
        cout << binary << endl;

    return 0;
}