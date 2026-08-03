#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
typedef long long ll;
const ll INF = 0x7f7f7f7f;
ll dp[N],sa[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    ll ans = -INF;
    for(int i = 1;i <= n;i ++){
        dp[i] = max(sa[i],dp[i-1]+sa[i]); ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}