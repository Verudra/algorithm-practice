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
const int N = 1e5;
const double eps = 1e-8;
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
int x[N],y[N],p[N];
void add(int u,int v,int w=0){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    edg[tot].w = w;
    head[u] = tot;
    rd[v] ++;
    return ;
}
double dis(int u,int v){
    return sqrt(pow(x[u]-x[v],2)+pow(y[u]-y[v],2));
}
bool vis[205];
int cnt = 0;
void dfs(int u){
    cnt ++;
    vis[u] = true;
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to;
        if(vis[to]) continue;
        dfs(to);
    }
}
void work(){
    int n; cin >> n;
    For(i,1,n) cin >> x[i] >> y[i] >> p[i];
    For(i,1,n){
        For(j,1,n){
            if(dis(i,j) <= p[i]+eps) add(i,j);
        }
    }
    int mx = 1;
    For(i,1,n){
        memset(vis,0,sizeof(vis));
        cnt = 0;
        dfs(i);
        mx = max(mx,cnt);
    }
    cout << mx;
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