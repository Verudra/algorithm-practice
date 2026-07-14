#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 100;
ll ksm(ll a,ll p){
    ll res = 1;
    while(p){
        if(p&1) res=res*a%MOD;
        a = a*a%MOD;
        p >>= 1;
    }
    return res;
}
int main(){
    ll n; cin >> n;
    cout << ksm(1992,n);
    return 0;
}