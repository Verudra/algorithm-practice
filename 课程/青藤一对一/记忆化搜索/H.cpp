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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 21;
int sa[N];
int dp[1<<N];
int n; 
int dfs(int u){
    if(u == (1<<n)-1) return 1;
    if(dp[u] != -1) return dp[u];
    dp[u] = 0;
    int cnt = __builtin_popcount(u);
    int t = sa[cnt+1]&(~u);
    while(t){
        int lt = t&-t;
        dp[u] += dfs(u|lt);
        t -= lt;
        dp[u]%=mod;
    }
    return dp[u];
}
void work(){
    cin >> n;
    For(i,1,n){
        For(j,1,n){
            int t; cin >> t;
            if(t == 1) sa[i] |= (1<<j-1);
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}