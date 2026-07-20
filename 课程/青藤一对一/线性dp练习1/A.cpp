#include<iostream>
#include<vector>
#include<algorithm>
#define int ll
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,k;
    cin >> n >> k;
    vector<int>dp(n+1);
    dp[0] = 1;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= k;j ++){
            if(j <= i) dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    cout << dp[n];
    return ;
}
signed main(){
    int T=1;
    while(T --) work();
    return 0;
}