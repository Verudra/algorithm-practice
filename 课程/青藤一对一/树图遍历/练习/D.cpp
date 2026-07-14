#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt,to;
}edg[N*2];
int tot, head[N], fa[N], sz[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
}
void dfs(int u){
    sz[u] ++;
    for(int e = head[u];e;e = edg[e].nxt){
        dfs(edg[e].to); sz[u] += sz[edg[e].to];
    }
    return ;
}
int main(){
    int n; cin >> n;
    for(int i = 1;i < n;i ++){
        cin >> fa[i+1];
        add(fa[i+1],i+1);
    }
    dfs(1);
    for(int i = 1;i <= n;i ++) cout << sz[i] << ' ';
    return 0;
}