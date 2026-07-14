#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt, to;
}edg[N*2];
int fa[N],head[N],tot;
int tim=1, in[N],out[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u){
    in[u] = tim ++;
    for(int e = head[u];e;e = edg[e].nxt){
        dfs(edg[e].to);
    }
    out[u] = tim-1;
    return ;
}
int main(){
    int n,q; cin >> n >> q;
    for(int i = 1;i < n;i ++){
        cin >> fa[i+1]; add(fa[i+1],i+1);
    }
    dfs(1);
    while(q --){
        int u,v; cin >> u >> v;
        if(in[v] >= in[u] && in[v] <= out[u]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}