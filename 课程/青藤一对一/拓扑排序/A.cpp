#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt,to;
}edg[N*2];
int tot,head[N],rd[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
    rd[v] ++;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int u,v; cin >> u >> v;
        add(u,v);
    }
    queue<int>q;
    for(int i = 1;i <= n;i ++){
        if(!rd[i]) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int now = q.front(); q.pop();
        cnt ++;
        for(int e = head[now];e;e = edg[e].nxt){
            if(--rd[edg[e].to] == 0) q.push(edg[e].to);
        }
    }
    if(n == cnt) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}