#include <bits/stdc++.h>
using namespace std;
const int N = 1000+10;
struct Edge{
    int nxt,to;
}edg[1000005];
bool vis[N][N];
bool mp[N];
int head[N],tot,rd[N],dp[N];
int sa[N];
void add(int v,int u){
    edg[++tot].nxt = head[u];
    edg[tot].to = v;
    head[u] = tot;
    rd[v] ++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i = 1;i <= m;i ++){
        memset(mp,0,sizeof(mp));
        int s; cin >> s;
        // for(int j = 1;j <= s;j ++){
        //     int t; cin >> t; mp[t] = true;
        //     q.push(t);
        //     if(j == 1) L = t;
        //     if(j == s) R = t;
        // }
        for(int j = 1;j <= s;j ++){
            cin >> sa[j];
            mp[sa[j]] = true;
        }
        int L = sa[1], R = sa[s];
        for(int j = L;j <= R;j ++){
            if(!mp[j]){
                for(int k = 1;k <= s;k ++){
                    int t = sa[k];
                    if(!vis[t][j]){
                        add(t,j);
                        vis[t][j] = true;
                    }
                }
            }
        }
        // for(int k = 1;k <= s;k ++){
        //     int t = sa[k];
        //     for(int j = L;j <= R;j ++){
        //         if(!mp[j]){
        //             if(vis[t][j] == false)
        //             {add(t,j);vis[t][j] = true;}
        //         }
        //     }
        // }
        
    }
    queue<int>q;
    for(int i = 1;i <= n;i ++){
        if(rd[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int e = head[t];e;e = edg[e].nxt){
            int to = edg[e].to;
            dp[to] = max(dp[to],dp[t]+1);
            rd[to] --;
            if(rd[to] == 0) q.push(to);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) ans = max(ans,dp[i]);
    cout << ans+1;
    return 0;
}