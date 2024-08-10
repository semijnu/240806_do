#include <iostream>
#include <vector>
using namespace std;

int countAnagramPairs(vector<int>);
void sortVector(vector<int>&);
bool isAnagram(int, int);

int main() {
    int n;
    vector<int> nums;
    
    cin >> n;  // 입력할 숫자 개수
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << countAnagramPairs(nums) << '\n';  // 입력과 출력을 간단히 합니다.
    return 0;
}