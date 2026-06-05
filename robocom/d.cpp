#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 30005;
int val[N];
struct node{
    int val,id;
    bool operator< (const node& b)const{
        return val > b.val;
    }  
    node(int a,int b){
        id = a,val = b;
    }
    node(){}
};
struct Edge{
    int nxt,to;
    int w;
}edg[M<<2];
int head[N],tot;
void add(int u,int v,int w){
    tot ++;
    edg[tot].to = v;
    edg[tot].w = w;
    edg[tot].nxt = head[u];
    head[u] = tot;
}
const int inf = 0x7f7f7f7f;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int maxn = 0;
    for(int i = 1;i <= n;i ++){
        scanf("%d",&val[i]);
        maxn = max(maxn,val[i]);
    }
    for(int i = 1;i <= m;i ++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    int l = 0,r = maxn;
    int s,t;
    scanf("%d%d",&s,&t);
    int ans = inf;
    while(l < r){
        int mid = (l+r)>>1;
        priority_queue<node>pq;
        pq.push(node(s,0));
        vector<int>dp(n+1,inf);
        vector<bool>vis(n+1,false);
        dp[s] = 0;
        while(!pq.empty()){
            auto now = pq.top();
            pq.pop();
            if(vis[now.id]) continue;
            vis[now.id] = true;
            int id = now.id;
            for(int e = head[now.id];e;e = edg[e].nxt){
                int to = edg[e].to;
                int w = edg[e].w;
                if(vis[to]) continue;
                if(val[to] > mid) continue;
                if(dp[to] > now.val + w){
                    dp[to] = now.val+w;
                    pq.push(node(to,dp[to]));
                }
            }
        }
        if(dp[t] == inf) l = mid+1;
        else{
            r = mid;
            ans = dp[t];
        }
    }
    printf("%d %d",l,ans);
    return 0;
}