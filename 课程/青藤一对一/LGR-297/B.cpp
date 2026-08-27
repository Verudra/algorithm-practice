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
const int N = 5e5+10;
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
int len = 0;
void dfs(int u,int fa,vector<bool>& vis){
    vis[u] = true;
    len ++;
    for(int e = head[u];e;e = edg[e].nxt){
        auto [_,to,w] = edg[e];
        if(to == fa || vis[to]) continue;
        dfs(to,u,vis);
    }
    return ;
}
void work(){
    int n; cin >> n;
    init_graph(n+1);
    For(i,1,n){
        int p; cin >> p;
        if(p == i) continue;
        add(p,i); add(i,p);
    }
    queue<int>q;
    vector<bool>vis(n+1);
    int ans = 1;
    for(int i = 1;i <= n;i ++){ ans = max(ans,rd[i]+1); if(rd[i] == 1) q.push(i), vis[i] = true;}
    while(!q.empty()){
        int t = q.front(); q.pop();    
        for(int e = head[t];e;e = edg[e].nxt){
            auto [_,to,w] = edg[e];
            if(vis[to]) continue;
            if(rd[to] == 2) q.push(to), vis[to] = true;
            rd[to] --;
        }
    }
    For(i,1,n){
        if(!vis[i]){
            len = 0;
            dfs(i,0,vis);
            if(len <= 5) ans = max(ans, len);
            else{
                if(len%3 == 0) ans = max(ans,3ll);
                else ans = max(ans,4ll);
            }
        }
    }
    cout << ans << '\n';
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