#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 2e4+10;
int dp[M],W[N],C[N];
int main(){
    int m,n; cin >> m >> n;
    for(int i = 1;i <= n;i ++){
        cin >> W[i] >> C[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = m;j >= W[i];j --){
            dp[j] = max(dp[j-W[i]]+C[i], dp[j]);
        }
    }
    cout << dp[m];
    return 0;
}