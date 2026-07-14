#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int tot, head[N];
struct Edge{
    int nxt, to;
}edg[N*2];
struct node{
    int pos,dep;
};
node max(node a,node b){
    return a.dep > b.dep ? a : b;
}
node dfs(int u,int fa,int dep){
    bool lv = false;
    node res = {0,0};
    for(int e = head[u];e;e = edg[e].nxt){
        if(edg[e].to == fa) continue;
        res = max(dfs(edg[e].to, u, dep+1),res);
        lv = true; 
    }
    if(!lv) return {u, dep};
    return res;
}
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
int main(){
    int n; cin >> n;
    for(int i = 1;i < n;i ++){
        int u,v; cin >> u >> v;
        add(u,v); add(v,u);
    }
    cout << dfs(dfs(1,0,0).pos,0,0).dep;
    return 0;
}
