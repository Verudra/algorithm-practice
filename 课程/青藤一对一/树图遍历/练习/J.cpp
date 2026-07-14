#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int fa[N],tot,head[N],dep[N];
struct Edge{
    int nxt, to;
}edg[N*2];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u){
    dep[u] = dep[fa[u]]+1;
    for(int e = head[u];e;e = edg[e].nxt){
        dfs(edg[e].to);
    }
}
int main(){
    int n,q; cin >> n >> q;
    for(int i = 1;i < n;i ++){
        cin >> fa[i+1];
        add(fa[i+1],i+1);
    }
    dfs(1);
    while(q --){
        int u,v; cin >> u >> v;
        if(dep[u] < dep[v]) swap(u,v);
        while(dep[u] != dep[v]) u = fa[u];
        while(u != v) u = fa[u], v = fa[v];
        cout << u << '\n';
    }
    return 0;
}