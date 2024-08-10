#include <iostream>
#include <vector>
using namespace std;

pair<int, int> maxProductPair(vector<int>& arr) {
    // 여기에 코드를 작성하세요.
}

int main() {
    int n;
    vector<int> arr;

    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    pair<int, int> result = maxProductPair(arr);
    cout << result.first << " " << result.second << endl;

    return 0;
}