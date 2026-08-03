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
int n; 
int head[N],tot,rd[N],siz[N],dp[N],ans[N],wpa[N];
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
void dfs1(int u,int fa){
    siz[u] = 1;
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to;
        int w = edg[e].w;
        if(to == fa) continue;
        dfs1(to,u);
        wpa[to] = w;
        siz[u] += siz[to];
        dp[u] += dp[to]+siz[to]*w;
    }
    return ;
}
void dfs2(int u,int fa){
    if(fa == 0) ans[u] = dp[u];
    else ans[u] = ans[fa]-siz[u]*wpa[u]+(n-siz[u])*wpa[u];
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to, w = edg[e].w;
        if(to == fa) continue;
        dfs2(to,u);
    }
    return ;
}
void work(){
    cin >> n;
    For(i,1,n-1){
        int u,v,w; cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    dfs1(1,0);
    dfs2(1,0);
    For(i,1,n) cout << ans[i] << ' ';
    cout << '\n';
    int tans = INF, anspos = -1;
    For(i,1,n){
        if(tans > ans[i]){
            tans = ans[i]; anspos = i;
        }
    }
    cout << tans << ' ' << anspos;
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