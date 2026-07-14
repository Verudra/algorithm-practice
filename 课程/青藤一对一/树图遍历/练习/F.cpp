#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt, to;
}edg[N*2];
int tot, head[N], d[N], dep[N];
int cnt = 0;
void add(int u,int v){
    d[u] ++;
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u,int f){
    dep[u] = dep[f] + 1;
    // if(d[u] == 1) cnt ++;
    bool flag = false;
    for(int e = head[u];e;e = edg[e].nxt){
        if(edg[e].to == f) continue;
        dfs(edg[e].to, u);
        flag = true;
    }
    if(!flag) cnt ++;
    return ;
}
int main(){
    int n; cin >> n;
    for(int i = 1;i < n;i ++){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    dfs(1,0);
    int maxdep = 0;
    for(int i = 1;i <= n;i ++) maxdep = max(maxdep, dep[i]);
    cout << cnt << ' ' << maxdep-1;
    return 0;
}