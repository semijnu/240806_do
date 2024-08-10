#include<iostream>
#include<string>
using namespace std;

int max_ones_between_zeros(string s){
    int maxCount = 0;
    int count = 0;

    for(int i = 0; i < s.size(); i++){
        if (s[i] == '0') {
            count = 0;
        } else if (s[i] == '1') {
            count++;
            maxCount = max(maxCount, count);
        }
    }
    
    return maxCount;
}

int main(){
    string s;
    cout << "이진 수를 입력하십시오: ";
    cin >> s;
    cout << "0 사이의 최대 1의 개수: " << max_ones_between_zeros(s) << endl;
    return 0;
}