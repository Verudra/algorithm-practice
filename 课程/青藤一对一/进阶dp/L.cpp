#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 2e5+10;
struct Edge{
    int nxt,to,w;
}edg[N<<1];
int head[N],tot,rd[N],dp0[N],dp1[N],wfa[N];
void init_graph(int n){
    tot = 0;
    for(int i = 1;i <= n;i ++){
        head[i] = rd[i] = 0;
    }
    return ;
}
void add(int u,int v,int w=0){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    edg[tot].w = w;
    head[u] = tot;
    rd[v] ++;
    return ;
}
void dfs(int u,int fa){
    if(fa != 0) dp1[u] = wfa[u];
    int mx = -INF;
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to, w = edg[e].w;
        if(to == fa) continue;
        wfa[to] = w;
        dfs(to, u);
        dp0[u] += dp0[to];
        dp1[u] += dp0[to];
        mx = max(mx, dp1[to]-dp0[to]);
    }
    if(mx > 0) dp0[u] += mx;
    return ;
}
void work(){
    int n; cin >> n;
    For(i,1,n-1){
        int u,v,w; cin >> u >> v >> w;
        add(u,v,w); add(v,u,w);
    }
    dfs(1,0);
    cout << dp0[1] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}