#include<bits/stdc++.h>
#define int ll
#define double long double
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define len(s) ((int)s.size())
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,q; cin >> n >> q;
    vi x(n*2+1), y(n*2+1);
    For(i,1,n) cin >> x[i] >> y[i], x[i+n] = x[i], y[i+n] = y[i];
    vi sx(n*2+1), sy(n*2+1),s(n*2+1);
    auto cross = [&](int a,int b){
        return x[a]*y[b]-x[b]*y[a];
    };
    For(i,1,n*2-1){
        sx[i] = sx[i-1]+(x[i]+x[i+1])*cross(i,i+1);
        sy[i] = sy[i-1]+(y[i]+y[i+1])*cross(i,i+1);
        s[i] = s[i-1]+cross(i,i+1);
    }
    cout << fixed << setprecision(15);
    while(q --){
        int u,v; cin >> u >> v;
        if(v < u) v += n;
        double tsx = sx[v-1]-sx[u-1], tsy = sy[v-1]-sy[u-1];
        double ts = s[v-1]-s[u-1];
        tsx += cross(v,u)*(x[v]+x[u]); tsy += cross(v,u)*(y[v]+y[u]);
        ts += cross(v,u);
        cout << tsx/(3.0*ts) << ' ' << tsy/(3.0*ts) << '\n';
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