#include <iostream>
#include <bitset>
using namespace std;

string binaryFraction(int num) {
    string binary = bitset<32>(num).to_string();
    int oneCount = 0, zeroCount = 0;

    for (int i = binary.find("1"); i < binary.length(); i++) {
        if (binary[i] == '1') oneCount++;
        else zeroCount++;
    }
    
    if(oneCount > zeroCount) return "True";
    else if(oneCount < zeroCount) return "False";
    else return "Equal";
}

int main() {
    int num;
    cin >> num; 
    cout << binaryFraction(num) << endl;  
    return 0;
}