#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull gcd(ull x,ull y){
    return y == 0?x : gcd(y, x%y);
}
ull lcm(ull x,ull y){
    return 1ll*x*y/gcd(x,y);
}
int main(){
    ull n,m;
    cin >> n >> m;
    cout << gcd(n,m) << ' ' << lcm(n,m);
    return 0;
}