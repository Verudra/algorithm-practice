#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int sa[N], dp[N], dp1[N];
int main(){
    int n; cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> sa[i];
    }
    for(int i = 1;i <= n;i ++){
        dp[i] = 1;
        for(int j = 1;j <= i-1;j ++){
            if(sa[i] < sa[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    for(int i = n;i >= 1;i --){
        dp1[i] = 1;
        for(int j = n;j > i;j --){
            if(sa[j] > sa[i]) dp1[i] = max(dp1[i], dp1[j]+1);
        }
    }
    int maxn = 0;
    for(int i = 1;i <= n;i ++){
        maxn = max({maxn, dp[i], dp1[i]});
    }
    cout << maxn;
    return 0;
}