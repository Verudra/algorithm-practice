#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int fun(string& s1,string& s2){
    ull base = 131, p = 1;
    ull hl = 0,hr = 0;
    int res = -1;
    for(int i = 0;i < min(s1.size(),s2.size());i ++){
        hl = hl*base + (ull)s1[i];
        hr = hr + (ull)s2[s2.length()-i-1]*p;
        p *= base;
        if(hl == hr) res = i;
    }
    return res+1;
}
int main(){
    string s1,s2;
    cin >> s1 >> s2;
    cout << max(fun(s1,s2), fun(s2,s1));
    return 0;
}