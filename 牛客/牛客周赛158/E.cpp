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
const int mod = 1000000007;
const int N = 2e5+10;
struct Segment_Tree{
    int tre[N<<2], sa[N];
    #define ls (u<<1)
    #define rs (u<<1|1)
    #define mid (l+r>>1)
    void update(int u){
        tre[u] = tre[ls] + tre[rs];
    }
    void build(int u,int l,int r){
        if(l == r){
            tre[u] = sa[l];
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
    }
    void change(int u,int l,int r,int p,int v){
        if(l == r){
            tre[u] = v;
            return ;
        }
        if(p <= mid) change(ls,l,mid,p,v);
        else change(rs,mid+1,r,p,v);
        update(u);
    }
    int query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u];
        }
        int res = 0;
        if(cl <= mid) res += query(ls,l,mid,cl,cr);
        if(cr > mid) res += query(rs,mid+1,r,cl,cr);
        return res;
    }
}T;
void work(){
    int n,q; cin >> n >> q;
    vi v(n+1);
    For(i,1,n) cin >> v[i];
    auto fun = [&](int p){
        if(v[p]*2 < v[p+1]+v[p-1]) return 1;
        return 0;
    };
    For(i,2,n-1){
        T.sa[i] = fun(i);
    } 
    T.build(1,1,n);
    auto change = [&](int p){
        if(p <= 1 || p >= n) return 0;
        return fun(p);
    };
    For(i,1,q){
        int op; cin >> op;
        if(op == 1){
            int p,x; cin >> p >> x;
            v[p] = x;
            For(k,p-1,p+1) if(k > 1 && k < n) T.change(1,1,n,k,change(k));
        }
        else{
            int l,r; cin >> l >> r;
            cout << T.query(1,1,n,l+1,r-1) << '\n';
        }
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