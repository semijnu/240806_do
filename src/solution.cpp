#include <iostream>
using namespace std;

void multiplyMatrices(int a[][10], int b[][10], int m1, int n1, int m2, int n2) {
    int result[10][10] = {0};
    if(n1 != m2) {
        cout << "Matrix multiplication is not possible.\n";
        return;
    }
    
    for(int i=0;i<m1;i++) {
        for(int j=0;j<n2;j++) {
            for(int k=0;k<n1;k++) 
                result[i][j] += a[i][k] * b[k][j];
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[10][10], b[10][10];
    int m1, n1, m2, n2;
    cout << "Enter the dimensions of the first matrix: ";
    cin >> m1 >> n1;
    cout << "Enter elements of the first matrix:\n";
    for(int i=0;i<m1;i++)
        for(int j=0;j<n1;j++)
            cin >> a[i][j];
    cout << "Enter the dimensions of the second matrix: ";
    cin >> m2 >> n2;
    cout << "Enter elements of the second matrix:\n";
    for(int i=0;i<m2;i++)
        for(int j=0;j<n2;j++)
            cin >> b[i][j];
    multiplyMatrices(a, b, m1, n1, m2, n2);

    return 0;
}