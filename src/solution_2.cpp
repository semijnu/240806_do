#include <iostream>
#include <string>
#include <vector>
using namespace std;

int levenshtein_distance(const string &s1, const string &s2) {
    int m=s1.size();
    int n=s2.size();

    vector<vector<int>> d(m+1, vector<int>(n+1));

    for(int i=0; i<=m; i++) {
        d[i][0] = i;
    }
    for(int j=0; j<=n; j++) {
        d[0][j] = j;
    }

    for(int j=1; j<=n; j++) {
        for(int i=1; i<=m; i++) {
            if(s1[i-1] == s2[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                d[i][j] = min(min(d[i-1][j] + 1, d[i][j-1] + 1), d[i-1][j-1] + 1);
            }
        }
    }
    return d[m][n];
}

int main() {
    string str1;
    string str2;

    cin >> str1 >> str2;

    cout << levenshtein_distance(str1, str2);
    return 0;
}