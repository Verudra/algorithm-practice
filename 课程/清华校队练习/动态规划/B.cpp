#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int N = 1000005;
ll dp[N];
int main(){
    int n; cin >> n;
    dp[0] = 1, dp[1] = 1;
    for(int i = 2;i <= n;i ++) dp[i] = (dp[i-1]+dp[i-2])%MOD;
    cout << dp[n];
    return 0;
}