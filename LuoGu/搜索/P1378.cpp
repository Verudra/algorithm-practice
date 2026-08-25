#include<bits/stdc++.h>
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
const double PI = 3.1415926535;
const int mod = 1000000007;
const int N = 10;
struct node{
    double x,y;
}sa[N];
struct Rec{
    node Lp,Rp;
    double s(){
        return (Rp.x-Lp.x)*(Rp.y-Lp.y);
    }
}rec;
int n; 
bool vis[N];
double ans = INF;
vi v;
double minrp(Rec r, node p){
    return min({r.Rp.y-p.y,p.y-r.Lp.y,p.x-r.Lp.x,r.Rp.x-p.x});
}
double dis(node a,node b){
    auto [x1,y1] = a; auto [x2,y2] = b;
    double disx = abs(x1-x2), disy = abs(y1-y2); 
    return sqrt(disx*disx + disy*disy);
}
double cirs(double r){
    return PI*r*r;
}
double fun(vi& v){
    vector<double>R;
    double res = rec.s();
    rep(i,v.size()){
        auto p = sa[v[i]];
        auto [x,y] = p;
        double r = minrp(rec,p);
        rep(j,i){
            double tr = R[j];
            r = min(max(0.0,dis(p,sa[v[j]])-tr),r);
        }
        R.push_back(r);
        res -= cirs(r);
    }
    return res;
}
void dfs(int u){
    if(u == n+1){
        ans = min(ans,fun(v));
        return ;
    }
    For(i,1,n){
        if(!vis[i]){
            vis[i] = true;
            v.push_back(i);
            dfs(u+1);
            v.pop_back();
            vis[i] = false;
        }
    }
}
void work(){
    cin >> n;
    node a,b; cin >> a.x >> a.y >> b.x >> b.y;
    if(a.x > b.x) swap(a.x,b.x);
    if(a.y > b.y) swap(a.y,b.y);
    rec.Lp = a; rec.Rp = b;
    For(i,1,n) cin >> sa[i].x >> sa[i].y;
    dfs(1);
    cout << fixed << setprecision(0) << ans;
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