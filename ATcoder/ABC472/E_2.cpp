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
#define len(s) ((int)s.size())
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
int dep[N], col[N], fa[N];
void init_graph(int n){
    tot = 0;
    for(int i = 1;i <= n;i ++){
        head[i] = rd[i] = dep[i] = col[i] = fa[i] = 0;
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
void dfs(int u,int& a,int& b){
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to;
        if(col[to] == col[u]){
            a = u; b = to;
            return ;
        }
        if(col[to] != 0) continue;
        col[to] = 3-col[u];
        dep[to] = dep[u] + 1;
        fa[to] = u;
        dfs(to,a,b);
    }
    return ;
}
void work(){
    int n,m; cin >> n >> m;
    init_graph(n);
    For(i,1,m){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    int a = 0,b = 0;
    dep[1] = 1; col[1] = 1;
    dfs(1,a,b);
    if(a == 0 && b == 0){
        cout << -1 << '\n';
        return ;
    }
    vi A,B;
    while(a != b){
        if(dep[a] >= dep[b]){
            A.push_back(a);
            a = fa[a];
        }
        else{
            B.push_back(b);
            b = fa[b];
        }
    }
    A.push_back(a);
    per(i,len(B)) A.push_back(B[i]);
    cout << len(A) << '\n';
    rep(i,len(A)) cout << A[i] << ' ';
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}