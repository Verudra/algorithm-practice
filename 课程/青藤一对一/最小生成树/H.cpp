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
const int N = 2005;
int fa[N],siz[N];
int getfa(int u){
    return u == fa[u]?u:fa[u] = getfa(fa[u]);
}
void init(int n){
    for(int i = 1;i <= n;i ++){
        fa[i] = i;
        siz[i] = 1;
    }
    return ;
}
void uni(int a,int b){
    int faa = getfa(a),fab = getfa(b);
    if(faa == fab) return ;
    if(siz[faa] > siz[fab]) swap(faa,fab);
    fa[faa] = fab;
    siz[fab] += siz[faa];
    return ;
}
struct E{
    int u,v,w;
};
struct node{
    int x,y;
};  
void work(){
    int n; cin >> n;
    init(n+1);
    vi c(n+1), k(n+1); vector<node> v;
    For(i,1,n){
        node t; cin >> t.x >> t.y;
        v.push_back(t);
    }
    For(i,1,n) cin >> c[i];
    For(i,1,n) cin >> k[i];
    auto dis = [=](int ida,int idb){
        node a = v[ida-1], b = v[idb-1];
        int dx = abs(a.x-b.x), dy = abs(a.y-b.y);
        return (dx+dy)*(k[ida]+k[idb]);
    };
    vector<E>es;
    For(i,1,n) es.push_back({n+1,i,c[i]});
    For(i,1,n){
        For(j,1,n){
            es.push_back({i,j,dis(i,j)});
        }
    }
    sort(es.begin(),es.end(),[](E a,E b){
        return a.w < b.w;
    });
    vi ans1;
    int ans = 0;
    struct node2{
        int u,v;
    };
    vector<node2> ans2;
    for(auto [u,v,w] : es){
        if(getfa(u) != getfa(v)){
            ans += w; uni(u,v);
            if(u == n+1) ans1.push_back(v);
            else ans2.push_back({u,v});
        }
    }
    cout << ans << '\n';
    cout << ans1.size() << '\n';
    for(auto i : ans1) cout << i << ' ';
    if(!ans1.empty()) cout << '\n';
    cout << ans2.size() << '\n';
    for(auto [u,v] : ans2){
        cout << u << ' ' << v << '\n';
    }
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