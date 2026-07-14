#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x;
    cin >> x;
    if(!x) cout << "00";
    while(x){
        int t = x&0x7f;
        x >>= 7;
        if(x) t |= 0x80;
        printf("%02X ",t);
    }
    return 0;
}