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
const int N = 200010;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
struct Segment_Tree{
    struct node{
        int sum,ma;
    };
    int n;
    node tre[N<<2];
    node merge(node a,node b){
        return {a.sum+b.sum, max(a.ma,b.ma)};
    }
    void update(int u){
        tre[u] = merge(tre[ls],tre[rs]);
    }
    void build(int u,int l,int r,const vector<int>& v){
        if(l == r){
            tre[u].ma = v[l-1];
            tre[u].sum = v[l-1];
            return ;
        }
        build(ls,l,mid,v);
        build(rs,mid+1,r,v);
        update(u);
        return ;
    }
    void build(const vector<int>& v){
        n = v.size();
        if(n) build(1,1,n,v);
        return ;
    }
    void change(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(tre[u].ma == 1) return ;
        if(l == r){
            tre[u].ma = tre[u].sum = int(sqrt(tre[u].ma));
            return ;
        }
        if(cl <= mid) change(cl,cr,ls,l,mid);
        if(cr > mid) change(cl,cr,rs,mid+1,r);
        update(u);
        return ;
    }
    int query(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr) return tre[u].sum;
        int res = 0;
        if(cl <= mid) res += query(cl,cr,ls,l,mid);
        if(cr > mid) res += query(cl,cr,rs,mid+1,r);
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree seg;

void work(){
    int n; cin >> n;
    vi v(n);
    rep(i,n) cin >> v[i];
    seg.build(v);
    int m; cin >> m;
    while(m --){
        int op,l,r; cin >> op >> l >> r;
        if(l > r) swap(l,r);
        if(op == 1) cout << seg.query(l,r) << '\n';
        else seg.change(l,r);
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