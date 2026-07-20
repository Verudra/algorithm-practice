#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
map<int,bool>mp;
int nxt[] = {1,2,3};
int n,b;
int dp[5005][4];
int dfs(int u,int k){
    if(mp[u] || u > n) return 0;
    if(u == n) return 1;
    if(dp[u][k] != -1) return dp[u][k];
    dp[u][k] = 0;
    For(i,0,2){
        if(k == i) continue;
        dp[u][k] = (dp[u][k]+dfs(u+nxt[i],i))%mod;
    }
    return dp[u][k];
}
void work(){
    cin >> n >> b;
    memset(dp,-1,sizeof(dp));
    For(i,1,b){
        int t; cin >> t;
        mp[t] = true;
    }
    cout << dfs(0,3);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}