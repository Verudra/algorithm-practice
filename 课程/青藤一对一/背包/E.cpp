#include<bits/stdc++.h>
using namespace std;
const int M = 1005;
const int N = 105;
int W[N], C[N];
int dp[M];
int main(){
    int m,n; cin >> m >> n;
    for(int i = 1;i <= n;i ++){
        cin >> W[i] >> C[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = W[i];j <= m;j ++){
            dp[j] = max(dp[j], dp[j-W[i]]+C[i]);
        }
    }
    cout << dp[m];
    return 0;
}