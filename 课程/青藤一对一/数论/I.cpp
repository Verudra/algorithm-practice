#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ksm(ll a,ll p){
    ll res = 1;
    while(p){
        if(p&1)res*=a;
        p>>=1;
        a*=a;
    }
    return res;
}
int main(){
    ll a,p;cin >> a >> p;
    cout << ksm(a,p);
    return 0;
}