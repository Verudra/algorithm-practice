#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>v(n+1);
    for(int i = 1;i <= n;i ++) scanf("%d",&v[i]);
    v[0] = 2e9;
    stack<int>stk;
    vector<long long> dp(n+1);
    stk.push(0);
    for(int i = 1;i <= n;i ++){
        while(!stk.empty() && v[stk.top()] <= v[i]) stk.pop();
        long long tmp = 1ll*v[i]*(i-stk.top());
        dp[i] = dp[stk.top()] + tmp;
        stk.push(i);
        printf("%lld%c",dp[i]+1,i==n?'\n':' ');
    }
    return 0;
}