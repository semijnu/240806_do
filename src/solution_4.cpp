#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int countAnagramPairs(vector<int> nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
        for (int j = i+1; j < nums.size(); j++)
            if (isAnagram(nums[i], nums[j])) count++;
    return count;
}

bool isAnagram(int a, int b) {
    string strA = to_string(a), strB = to_string(b);
    sort(strA.begin(), strA.end());
    sort(strB.begin(), strB.end());
    return strA == strB;
}

int main() {
    int n;
    vector<int> nums;
    
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << countAnagramPairs(nums) << '\n'; 
    return 0;
}