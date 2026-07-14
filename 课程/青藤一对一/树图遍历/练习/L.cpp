#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int fa[N][30];
struct Edge{
    int nxt,to;
}edg[N];
int tot,head[N],dep[N];
void dfs(int u){
    dep[u] = dep[fa[u][0]]+1;
    for(int e = head[u];e;e = edg[e].nxt){
        dfs(edg[e].to);
    }
}
int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    int cz = dep[u]-dep[v];
    for(int k = 25;k >= 0;k --){
        if((1<<k)&cz) u = fa[u][k];
    }
    if(u == v) return u;
    for(int k = 25;k >= 0;k --){
        if(fa[u][k] != fa[v][k]){
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
int dis(int u,int v){
    int l = lca(u,v);
    return dep[u]-dep[l] + dep[v]-dep[l];
}
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
int main(){
    int n,q; cin >> n >> q;
    for(int i = 2;i <= n;i ++){
        cin >> fa[i][0];
        add(fa[i][0],i);
    }
    dfs(1);
    for(int i = 1;i <= 25;i ++){
        for(int j = 2;j <= n;j ++){
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
    while(q --){
        int u,v; cin >> u >> v;
        cout << dis(u,v) << '\n';
    }
    return 0;
}