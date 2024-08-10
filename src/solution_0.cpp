#include <iostream>
#include <vector>
using namespace std;

pair<int, int> maxProductPair(vector<int>& arr) {
    int posa = 0, posb = 0;
    int nega = 0, negb = 0;
    
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] > posa) {
            posb = posa;
            posa = arr[i];
        } else if(arr[i] > posb) {
            posb = arr[i];
        }

        if(arr[i] < 0 && abs(arr[i]) > abs(nega)) {
            negb = nega;
            nega = arr[i];
        } else if(arr[i] < 0 && abs(arr[i]) > abs(negb)) {
            negb = arr[i];
        }
    }
    
    return posa*posb > nega*negb ? make_pair(posa, posb) : make_pair(nega, negb);
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