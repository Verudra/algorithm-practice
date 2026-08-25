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
const int N = 1e6+10;
struct Edge{
    int nxt,to,w;
}edg[N<<1];
int head[N],tot,rd[N],siz[N];
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
vi rts;
void dfs(int u,int fa){
    siz[u] ++;
    for(int e = head[u];e;e = edg[e].nxt){
        auto [_,to,w] = edg[e];
        if(to == fa) continue;
        dfs(to,u);
        siz[u] += siz[to];
    }
    if(fa == 1) rts.push_back(siz[u]);
}
void work(){
    int n; cin >> n;
    For(i,2,n){
        int u = i, v; cin >> v;
        add(u,v); add(v,u);
    }
    dfs(1,0);
    int ans = n*(n-1);
    for(auto s : rts){
        ans += s*(s-1);
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