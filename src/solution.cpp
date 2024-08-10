#include <iostream>

using namespace std; 

#define SIZE 3 

void multiply(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) { 
    int res[SIZE][SIZE]; // To store result 

    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            res[i][j] = 0; 
            for (int k = 0; k < SIZE; k++) 
                res[i][j] += mat1[i][k] * mat2[k][j]; 
        } 
    }

    cout << "Result matrix is \n"; 
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) 
           cout << res[i][j] << " "; 
        cout << "\n"; 
    } 
}
 
int main() {
    int mat1[SIZE][SIZE], mat2[SIZE][SIZE];
    
    cout << "Enter elements of first matrix\n";
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            cin >> mat1[i][j];
        }
    }
    cout << "Enter elements of second matrix\n";
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            cin >> mat2[i][j];
        }
    }
  
    multiply(mat1, mat2); 
  
    return 0; 
}