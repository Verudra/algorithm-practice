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
bool vis[N];
void init_graph(int n){
    tot = 0;
    for(int i = 1;i <= n;i ++){
        head[i] = vis[i] = rd[i] = 0;
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
int cnt = 0;
int n,m; 
void dfs(int u){
    vis[u] = true;
    cnt ++;
    for(int e = head[u];e;e = edg[e].nxt){
        if(vis[edg[e].to]) continue;
        dfs(edg[e].to);
    }
    return ;
}
void work(){
    init_graph(n);
    For(i,1,m){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    cnt = 0;
    dfs(1);
    if(cnt == n) cout << "YES\n";
    else cout << "NO\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        work();
    }
    return 0;
}