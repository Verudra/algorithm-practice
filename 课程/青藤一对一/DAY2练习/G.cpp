#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Edge{
    int nxt,to;
}edg[N*2];
int head[N],tot,rd[N];
int dp[N];
void add(int u,int v){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
    rd[v] ++;
}
int main(){
    int n,m; cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        int u,v; cin >> u >> v;
        add(v,u);
    }
    queue<int>q;
    for(int i = 1;i <= n;i ++){
        if(rd[i] == 0){
            q.push(i);
            dp[i] = 100;
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int t = q.front(); q.pop();
        cnt ++;
        for(int e = head[t];e;e = edg[e].nxt){
            int to = edg[e].to;
            rd[to] --;
            if(rd[to] == 0) q.push(to);
            dp[to] = max(dp[to],dp[t]+1);
        }
    }
    if(cnt != n){
        cout << "Impossible";
        return 0;
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) ans += dp[i];
    cout << ans;
    return 0;
}