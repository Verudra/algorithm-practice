#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp[N];
int sa[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++)  cin >> sa[i];
    for(int i = 1;i <= n;i ++){
        dp[i] = 1;
        for(int j = 1;j <= i-1;j ++){
            dp[i] = max(dp[i],sa[j]<sa[i]?dp[j]+1:dp[i]);
        }
    }
    int ans = 0; for(int i = 1;i <= n;i ++) ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}