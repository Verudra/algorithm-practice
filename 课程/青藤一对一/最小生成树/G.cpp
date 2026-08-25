#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#include <bits/stdc++.h>
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
const int N = 1005;
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

void work(){
    int n,m; cin >> n >> m;
    init(n);
    struct node{
        int x,y;
    };
    vector<node>v;
    For(i,1,n){
        node t; cin >> t.x >> t.y;
        v.push_back(t);
    }
    struct E{
        int u,v;
        double w;
    };
    auto dis = [&](int a,int b){
        int dx = v[a-1].x-v[b-1].x, dy = v[a-1].y-v[b-1].y;
        return sqrt(dx*dx+dy*dy);
    };
    vector<E>es;
    For(i,1,n){
        For(j,1,n){
            int u = i,v = j; double w = dis(i,j);
            es.push_back({u,v,w});
        }
    }
    For(i,1,m){
        int u,v; cin >> u >> v;
        es.push_back({u,v,0});
    }
    sort(es.begin(),es.end(),[](E a,E b){
        return a.w < b.w;
    });
    double ans = 0;
    for(auto [u,v,w] : es){
        if(getfa(u) != getfa(v)){
            ans += w;
            uni(u,v);
        }
    }
    cout << fixed << setprecision(2) << ans;
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