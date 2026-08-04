#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
int mp[N][N];
int main(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            cin >> mp[i][j];
        }
    }
    for(int i = 1;i <= n;i ++) dp[i][1] = dp[i-1][1] + mp[i][1];
    for(int i = 1;i <= m;i ++) dp[1][i] = dp[1][i-1] + mp[1][i];
    for(int i = 2;i <= n;i ++){
        for(int j = 2;j <= m;j ++){
            dp[i][j] = min(dp[i-1][j]+mp[i][j],dp[i][j-1]+mp[i][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}