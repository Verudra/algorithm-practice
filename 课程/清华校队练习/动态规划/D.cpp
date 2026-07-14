#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int mp[N][N];
int dp[N][N];
int main(){
    int n; cin >> n;
    memset(dp,-0x7f,sizeof(dp));
    dp[0][1] = 0;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= i;j ++) cin >> mp[i][j];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= i;j ++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+mp[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) ans = max(ans,dp[n][i]);
    cout << ans;
    return 0;
}