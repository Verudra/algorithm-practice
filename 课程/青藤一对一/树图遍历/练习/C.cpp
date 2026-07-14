#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt,to;
}edg[N*2];
int tot,head[N],dep[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u,int fa){
    dep[u] = dep[fa] + 1;
    for(int e = head[u];e;e = edg[e].nxt){
        if(edg[e].to == fa) continue;
        dfs(edg[e].to,u);
    }
    return ;
}
int main(){
    int n,q;
    cin >> n >> q;
    for(int i = 1;i < n;i ++){
        int u,v; cin >> u >> v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    for(int i = 1;i <= q;i ++){
        int t; cin >> t;
        cout << dep[t] << '\n';
    }
    return 0;
}