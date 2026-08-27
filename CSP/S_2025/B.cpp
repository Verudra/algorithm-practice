#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
struct Edge{
    int u,v,w,f;  
};
const int N = 1e5+10;
int fa[N];
void init(int n){
    For(i,1,n) fa[i] = i;
    return ;
}
int gfa(int x){
    if(x == fa[x]) return x;
    return fa[x] = gfa(fa[x]);
}
void uni(int x,int y){
    int idx = gfa(x), idy = gfa(y);
    if(idx != idy) fa[idx] = fa[idy];
    return ;
}
void work(){
    int n,m,k; cin >> n >> m >> k;
    init(n);
    vector<Edge> edg(m),ne; rep(i,m){
        auto& e = edg[i];
        cin >> e.u >> e.v >> e.w;
    }
    auto cmp = [](const Edge& a, const Edge& b){
        return a.w < b.w;
    };
    sort(edg.begin(),edg.end(),cmp);
    int cnt = 0;
    rep(i,m){
        auto [u,v,w,f] = edg[i];
        if(gfa(u) != gfa(v)){
            uni(u,v);
            cnt ++;
            ne.push_back({u,v,w,f});
        }
        if(cnt == n-1) break;
    }
    vi c(k+1); 
    For(i,1,k){
        cin >> c[i];
        For(j,1,n){
            int w; cin >> w;
            ne.push_back({i+n,j,w,i});
        }
    }
    sort(ne.begin(),ne.end(),cmp);
    int ans = INF;
    For(_,0,(1<<k)-1){
        init(n+k);
        int sumc = 0;
        rep(i,k) if((1<<i)&_) sumc += c[i+1];
        int cnt = 0;
        rep(i,ne.size()){
            auto [u,v,w,f] = ne[i];
            if(!f || ((1<<f-1)&_)){
                if(gfa(u) != gfa(v)){
                    uni(u,v);
                    sumc += w;
                    cnt ++;
                }
            }
        }
        ans = min(ans,sumc);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    //cin >> T;
    while(T --) work();
    return 0;
}