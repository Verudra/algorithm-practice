#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int N = 200005, M = 400005;
const int INF = 0x7f7f7f7f;
struct Edge{
    int nxt;
    int to;
    int w[2];
}edg[M][2];
int head[N][2],tot,ex[N];
void add(int u,int v,int c,int d,int opt){
    edg[++tot][opt].nxt = head[u][opt];
    edg[tot][opt].to = v;
    edg[tot][opt].w[0] = c;
    edg[tot][opt].w[1] = d;
    head[u][opt] = tot;
    return ;
}
struct node{
    int pos,dis;
    bool operator<(const node& b)const{
        return dis > b.dis;
    }
};
int dp[N][2];
bool vis[N][2];
void dijstra(int pos,int opt){
    priority_queue<node>pq;
    pq.push({pos,0});
    dp[pos][opt] = 0;
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(vis[now.pos][opt]) continue;
        vis[now.pos][opt] = true;
        for(int e = head[now.pos][opt];e;e = edg[e][opt].nxt){
            int to = edg[e][opt].to;
            if(dp[now.pos][opt] + edg[e][opt].w[opt] < dp[to][opt]){
                dp[to][opt] = dp[now.pos][opt] + edg[e][opt].w[opt];
                pq.push({to,dp[to][opt]});
            }
        }
    }
}
struct Segment_Tree{
    int tre[N<<2];
    #define ls (u<<1)
    #define rs (u<<1|1)
    #define mid ((l+r)>>1)
    void build(int u,int l,int r,vector<int>&vec){
        if(l == r){
            tre[u] = vec[l];
            return ;
        }
        build(ls,l,mid,vec);
        build(rs,mid+1,r,vec);
        update(u);
    }
    void update(int u){
        tre[u] = min(tre[ls], tre[rs]);
    }
    void change(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u] = val;
            return;
        }
        if(pos <= mid) change(ls,l,mid,pos,val);
        else change(rs,mid+1,r,pos,val);
        update(u);
    }
    int query(int u,int l,int r,int lt,int rt){
        if(lt >= l && rt <= r){
            return tre[u];
        }
        int ans = -INF;
        if(lt <= mid) ans = min(ans, query(ls,l,mid,lt,rt));
        else ans = min(ans,query(rs,mid+1,r,lt,rt));
        return ans;
    }
}T;
int getw(int pos){
    return (int)(dp[pos][0]+ceil((1.0*dp[pos][1])/ex[pos]));
}
signed main(){
    memset(dp,0x7f,sizeof dp);
    int n,m,q;
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i = 1;i <= m;i ++){
        int u,v,c,d;
        scanf("%lld%lld%lld%lld",&u,&v,&c,&d);
        add(v,u,c,d,1);
        add(u,v,c,d,0);
    }
    for(int i = 1;i <= n;i ++){
        scanf("%lld",&ex[i]);
    }
    dijstra(1,0);
    dijstra(n,1);
    vector<int>vec(n+1);
    for(int i = 1;i <= n;i ++){
        vec[i] = (int)(dp[i][0]+ceil((1.0*dp[i][1])/ex[i]));
    }
    // for(int i = 1;i <= n;i ++) printf("i:%lld dp0:%lld dp1:%lld\n",i,dp[i][0],dp[i][1]);
    T.build(1,1,n,vec);
    while(q --){
        int x,a;
        scanf("%lld%lld",&x,&a);
        ex[x] = a;
        T.change(1,1,n,x,getw(x));
        printf("%lld\n",T.query(1,1,n,1,n));
    }
    return 0;
}