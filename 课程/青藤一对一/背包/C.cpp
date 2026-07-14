#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 1e4+10;
ll dp[N];
int main(){
    int n,w; cin >> n >> w;
    vector<int>v;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    dp[0] = 1;
    for(auto i : v){
        for(int j = i;j <= w;j ++){
            dp[j] = (dp[j-i]+dp[j])%mod;
        }
    }
    cout << dp[w];
    return 0;
}