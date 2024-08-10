#include <iostream>
#include <string>
using namespace std;

string findLongestPalindrome(string s) {
    if(s.size()==0) return ""; 
    int n=s.size(), left=0, len=1;
    int dp[n][n]={0}; 
    for(int j=0; j<n; j++){
        dp[j][j] = 1;
        for(int i=0; i<j; i++){ 
            dp[i][j] = (s[i]==s[j] && (j-i<2 || dp[i+1][j-1]));
            if(dp[i][j] && len<j-i+1){
                left = i;
                len=j-i+1;
            }
        }
    }
    return s.substr(left, len);
}

int main() {
    string s;
    cin >> s;
    cout << findLongestPalindrome(s) << endl; 
    return 0;
}