#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> findMaximums(int n, vector<int>& arr, int k) {
    vector<int> result;
    deque<int> Q(k);
    int i;
    for (i = 0; i < k; ++i) {
        while (!Q.empty() && arr[i] >= arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    for (; i < n; ++i) {
        result.push_back(arr[Q.front()]);
        while (!Q.empty() && Q.front() <= i - k) {
            Q.pop_front();
        }
        while (!Q.empty() && arr[i] >= arr[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    result.push_back(arr[Q.front()]);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    vector<int> maxVals = findMaximums(n, arr, k);
    for (int val : maxVals) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}