#include <bits/stdc++.h>
using namespace std;
const int N = 370;
typedef long long ll;
ll sa[N];
int main(){
    ll a,b,m,N;
    cin >> sa[1] >> sa[2] >> m >> N;
    bool f = false;
    for(int i = 3;i <= N;i ++){
        if(!f) sa[i] = sa[i-1]+sa[i-2];
        if(sa[i-1]+sa[i-2] >= m) f = true;
    }
    ll ans = 0;
    for(int i = 1;i <= N;i ++) ans += sa[i];
    cout << ans;
    return 0;
}