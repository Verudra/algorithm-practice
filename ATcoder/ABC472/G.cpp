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
struct Edge{
    int to,rev,cap;
};
vector<vector<Edge>> g;
vi cur,level;
void add_edge(int u,int v,int cap){
    g[u].push_back({v,len(g[v]),cap});
    g[v].push_back({u,len(g[u])-1,0});
}
bool bfs(int s,int t){
    fill(level.begin(),level.end(),-1);
    queue<int>q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(auto [to,rev,cap]:g[t]){
            if(cap > 0 && level[to] == -1){
                level[to] = level[t] + 1;
                q.push(to);
            }   
        }
    }
    return level[t] != -1;
}
int dfs(int u,int t,int f){
    if(u == t) return f;
    for(int &i=cur[u];i < len(g[u]);i ++){
        auto& [to,rev,cap] = g[u][i];
        if(cap > 0 && level[to] == level[u]+1){
            int res = dfs(to,t,min(f,cap));
            if(res > 0){
                cap -= res;
                g[to][rev].cap += res;
                return res;
            }
        }
    }
    return 0;
}
int mxf(int s,int t){
    int res = 0;
    while(bfs(s,t)){
        fill(cur.begin(),cur.end(),0);
        while(int f = dfs(s,t,1e9)) res += f;
    }
    return res;
}
void work(){
    int h,w; cin >> h >> w;
    vector<string> mp(h);
    rep(i,h) cin >> mp[i];
    int s = h*w, t = s+1;
    int n = t+1;
    int inf = h*w+1;
    int plus = 0;
    g.assign(n,{});
    level.resize(n);
    cur.resize(n);
    rep(i,h){
        rep(j,w){
            if(mp[i][j] == '#') continue;
            int u = i*w+j;
            if(mp[i][j] == '+'){
                add_edge(s,u,1);
                plus ++;
            }
            else{
                add_edge(u,t,1);
            }
            if(j+1 < w && mp[i][j+1] != '#'){
                int v = u+1;
                add_edge(u,v,inf);
                add_edge(v,u,inf);
            }
            if(i+1 < h && mp[i+1][j] != '#'){
                int v = u+w;
                add_edge(v,u,inf);
            }
        }
    }
    cout << plus-mxf(s,t) << '\n';
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