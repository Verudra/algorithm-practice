#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
const ll mod = 1e9+7;
ll dp[N];
int main(){
    int n, w;
    cin >> n >> w;
    vector<int>v;
    for(int i = 1;i <= n;i ++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    dp[0] = 1;
    for(int i = 1;i <= w;i ++){
        for(auto j : v){
            if(i-j < 0) break;
            dp[i] += dp[i-j];
            dp[i] %= mod;
        }
    }
    cout << dp[w];
    return 0;
}