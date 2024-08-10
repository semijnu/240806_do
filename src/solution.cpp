#include<iostream>
#include<vector>
#include<cstring> 
using namespace std;

int getLCSLength(vector<int> arr1, vector<int> arr2) {
    int m = arr1.size(), n = arr2.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp)); 
   
    for (int i=0; i<=m; i++) { 
        for (int j=0; j<=n; j++) { 
            if (i == 0 || j == 0) 
                dp[i][j] = 0; 
            else if (arr1[i-1] == arr2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1; 
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        } 
    } 
    return dp[m][n];
}

int main() {
    int size;
    cin >> size;
    vector<int> arr1(size);
    vector<int> arr2(size);
    for(int i = 0; i < size; i++) {
        cin >> arr1[i];
    }
    for(int i = 0; i < size; i++) {
        cin >> arr2[i];
    }
    cout << getLCSLength(arr1, arr2) << endl;
    return 0;
}