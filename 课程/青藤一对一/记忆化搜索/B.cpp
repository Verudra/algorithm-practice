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
const int N = 5005;
int sa[N], k, n, dp[N], f;
int dfs(int u){
    if(u > n) return 0;
    if(dp[u] != -1) return dp[u];
    dp[u] = INF;
    int mx = 0;
    For(i,u,u+k-1){
        mx = max(mx, sa[i]);
        dp[u] = min(dp[u], mx*(i-u+1)+f+dfs(i+1));
    }
    return dp[u];
}
void work(){
    cin >> n >> k >> f;
    memset(dp,-1,sizeof dp);
    For(i,1,n) cin >> sa[i];
    cout << dfs(1);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}