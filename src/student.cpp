#include <iostream>
#include <vector>
using namespace std;

string checkMagicSquare(vector<vector<int>>& arr) {
    // 여기에 코드를 작성하세요.
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> arr[i][j];
            
    cout << checkMagicSquare(arr) << endl;
    return 0;
}