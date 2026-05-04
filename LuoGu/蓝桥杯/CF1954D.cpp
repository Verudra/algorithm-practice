#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    int tots = 0;
    for(int i = 0;i < n;i ++) scanf("%d",&v[i]),tots += v[i];
    sort(v.begin(),v.end());
    vector<int>dp(tots+1);
    dp[0] = 1;
    int nows = 0;
    long long ans = 0;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j <= nows;j ++){
            if(dp[j] == 0) continue;
            ans = (ans + 1ll*max((j+v[i]+1)/2,v[i])*dp[j])%MOD;
        }
        for(int j = nows;j >= 0;j --){
            dp[j+v[i]] += dp[j];
            dp[j+v[i]] %= MOD;
        }
        nows += v[i];
    }
    printf("%lld",ans);
    return 0;
}