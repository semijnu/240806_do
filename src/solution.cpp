#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotateMatrix90Clockwise(vector<vector<int>> matrix) {
    vector<vector<int>> rotatedMatrix(matrix[0].size(), vector<int>(matrix.size()));

    for(int i=0;i<matrix.size();i++)
        for(int j=0;j<matrix[0].size();j++)
            rotatedMatrix[j][matrix.size()-i-1] = matrix[i][j];
    return rotatedMatrix;
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
            cout << rotatedMatrix[i][j] << ' ';
        }
        cout << endl;
    }
  
    return 0;
}