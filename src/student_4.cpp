#include <iostream>
#include <vector>

using namespace std;

vector<string> CombinationSumsToBinary(vector<int> nums) {
    // 여기에 코드를 작성하세요.
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