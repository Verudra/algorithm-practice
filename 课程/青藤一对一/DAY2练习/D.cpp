#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt,to;
}edg[N*2];
int head[N],tot;
int fa[N][30];
int dep[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u){
    dep[u] = dep[fa[u][0]]+1;
    for(int e = head[u];e;e = edg[e].nxt){
        int to = edg[e].to;
        dfs(to);
    }
    return ;
}
int LCA(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    for(int k = 0;k <= 25;k ++){
        if((1<<k)&(dep[u]-dep[v])) u = fa[u][k];
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
    int lca = LCA(u,v);
    return dep[u]-dep[lca]+dep[v]-dep[lca];
}
int main(){
    int n,q; cin >> n >> q;
    for(int i = 2;i <= n;i ++){
        cin >> fa[i][0];
        add(fa[i][0],i);
    }
    dfs(1);
    for(int k = 1;k <= 25;k ++){
        for(int i = 1;i <= n;i ++){
            fa[i][k] = fa[fa[i][k-1]][k-1];
        }
    }
    while(q --){
        int u,v; cin >> u >> v;
        cout << dis(u,v) << '\n';
    }
    return 0;
}