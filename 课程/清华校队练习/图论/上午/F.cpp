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
int head[N],tot,rd[N];
int x[N], y[N],mix,mxx,miy,mxy;
bool vis[N];
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
void dfs(int u){
    vis[u] = true;
    mxx = max(mxx,x[u]);
    mxy = max(mxy,y[u]);
    mix = min(mix,x[u]);
    miy = min(miy,y[u]);
    for(int e=head[u];e;e=edg[e].nxt){
        int to = edg[e].to;
        if(vis[to]) continue;
        dfs(to);
    }
}
void work(){
    int n,m; cin >> n >> m;
    For(i,1,n) cin >> x[i] >> y[i];
    For(i,1,m){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    int ans = INF;
    For(i,1,n){
        if(vis[i] == 0){
            mxx = mxy = -INF;
            mix = miy = INF;
            dfs(i);
            ans = min(ans,(mxx-mix)*2+(mxy-miy)*2);
        }
    }
    cout << ans;
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