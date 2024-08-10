#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotateMatrix90Clockwise(vector<vector<int>> matrix) 
{
    // 여기에 코드를 작성하세요.
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }
  
    vector<vector<int>> rotatedMatrix = rotateMatrix90Clockwise(matrix);
  
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << rotatedMatrix[i][j];
        }
        cout << endl;
    }
  
    return 0;
}