#include <iostream>
#include <vector>
using namespace std;

vector<int> findMaxIndex(vector<int> arr) {
    vector<int> result;
    int maxVal = arr[0];
    int maxIdx = 0;
    for (int i=1; i<arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIdx = i;
        }
    }
    result.push_back(maxIdx);
    if (maxIdx == arr.size()-1) result.push_back(-1); 
    else result.push_back(maxIdx+1); 
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i=0; i<N; ++i) {
        cin >> arr[i];
    }
    vector<int> result = findMaxIndex(arr);
    for(auto& idx : result) {
        cout << idx << ' ';
    }
    return 0;
}