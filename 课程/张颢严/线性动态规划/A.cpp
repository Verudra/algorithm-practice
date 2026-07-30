#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 10005;
int dp[N];
int main(){
    int n; cin >> n;
    vector<int>v;
    int ans = -INF;
    int t,s = 0;
    for(int i = 1;i <= n;i ++){
        cin >> t; v.push_back(t);
    }
    for(int i = 1;i <= n;i ++){
        dp[i] = max(dp[i-1]+v[i-1], v[i-1]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}