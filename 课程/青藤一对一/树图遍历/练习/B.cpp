#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt,to;
}edg[N*2];
int tot,head[N],fa[N],dep[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u){
    dep[u] = dep[fa[u]] + 1;
    for(int e = head[u];e;e = edg[e].nxt){
        dfs(edg[e].to);
    }
}
int main(){
    int n; cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> fa[i+1];
        add(fa[i+1],i+1);
    }
    dfs(1);
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        ans = max(ans, dep[i]);
    }
    cout << ans;
    return 0;
}