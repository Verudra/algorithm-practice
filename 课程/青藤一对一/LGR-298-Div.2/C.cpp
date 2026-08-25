#include<bits/stdc++.h>
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
const int N = 1e6+10;
struct Edge{
    int nxt,to,w;
}edg[N<<1];
int head[N],tot,rd[N];
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
int sz[N],mxsz[N];
void dfs(int u,int fa){
    sz[u] ++;
    for(int e = head[u];e;e = edg[e].nxt){
        auto [_,to,w] = edg[e];
        if(to == fa) continue;
        dfs(to,u);
        sz[u] += sz[to];
        mxsz[u] = max(mxsz[u],sz[to]);
    }
    return ;
}
void work(){
    int n,q,r;
    cin >> n >> q >> r;
    For(i,1,n-1){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    dfs(r,-1);
    vi f(n+1);
    For(i,0,n-1){
        f[i] = n-sz[i]+mxsz[i];
    }
    For(i,1,n-1) f[i] = max(f[i],f[i-1]);
    f[n] = n;
    while(q --){
        int x; cin >> x;
        cout << lower_bound(f.begin(),f.end(),x)-f.begin() << '\n';
    }
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