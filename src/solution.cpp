#include<iostream>
#define MOD 1000000007
using namespace std;

long long get_sum(int n) {
    long long sum = 0;
    long long two = 1;
    for(int i=1; i<=n; i++){
        two = (two*2) % MOD;
        if(two % 9 != 0) sum = (sum + two) % MOD;
    }
    return sum;
}

int main(){
   int n;
   cin>>n;
   cout<<get_sum(n)<<endl;
   return 0;
}