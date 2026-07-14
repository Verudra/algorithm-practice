#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t; cin >> t;
    if(t==1){ cout << "NO"; return 0;}
    for(ll i = 2;i*i <= t;i ++) if(t%i == 0){cout << "NO"; return 0;}
    cout << "YES";
    return 0;
}