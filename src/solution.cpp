정답 코드: 
#include <iostream>
using namespace std;
int longest_sequence(int arr[], int n, int k){
    int result = 0;
    int count = 0;
    bool found = false;
    for(int i=0; i<n; i++){
        if(arr[i]==k){
            if(!found)
                found = true;
            count++;
        }else{
            if(found){
                result = max(result, count);
                found = false;
                count = 0;
            }
        }
    }
    return max(result, count);
};

int main(){
    int arr[100];
    int n;
    int k;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter the element to find: ";
    cin >> k;
    cout << "Length of longest sequence: " << longest_sequence(arr, n, k) << endl;

    return 0;
}