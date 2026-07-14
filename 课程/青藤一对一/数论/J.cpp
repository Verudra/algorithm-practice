#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string DAYS[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
const ll MOD = 7;
ll ksm(ll a,ll p){
    ll res = 1;
    while(p){
        if(p&1) res = res*a%MOD;
        a = a*a%MOD;
        p >>= 1; 
    }
    return res;
}
int main(){
    ll a,p;
    cin >> a >> p;
    cout << DAYS[ksm(a,p)%7];
    return 0;
}