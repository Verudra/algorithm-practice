#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll ksm(ll a,ll p,ll m){
    ll res = 1;
    while(p){
        if(p&1) res = res*a%m;
        a = a*a%m;
        p >>= 1;
    }
    return res;
}
int main(){
    ll a,b,p; cin >> a >> b >> p;
    cout << ksm(a%p,b,p);
    return 0;
}