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
const int M = 2e5+10;
const int N = 1e5+10;
struct Edge{
    int nxt,to;
}edg[M];
int head[N], tot, dp[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
int dfs(int u){
    if(dp[u]) return dp[u];
    dp[u] = 1;
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to;
        dp[u] = max(dp[u], dfs(to)+1);
    }
    return dp[u];
}
void work(){
    int n,m; cin >> n >> m;
    For(i,1,m){
        int u,v; cin >> u >> v;
        add(v,u);
    }
    For(i,1,n) cout << dfs(i) << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}