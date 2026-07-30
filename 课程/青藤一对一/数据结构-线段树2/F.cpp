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
struct Segment_Tree_Max{
    struct node{
        int mpres,msufs,ma,sum;
        bool operator== (node b)const{
            return (mpres==b.mpres&&msufs==b.msufs&&ma==b.ma&&sum==b.sum);
        }
    };
    int n,sa[N];
    node tre[N<<2];
    node merge(node a,node b){
        return {max(a.mpres,a.sum+b.mpres),max(b.msufs, a.msufs+b.sum), max({a.ma, b.ma, a.msufs+b.mpres}), a.sum+b.sum};
    }
    void update(int u){
        tre[u] = merge(tre[ls],tre[rs]);
    }
    void build(int u,int l,int r){
        if(l == r){
            tre[u].ma=tre[u].mpres=tre[u].msufs=tre[u].sum = sa[l];
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
        return ;
    }
    void build(const vector<int>& v){
        n = v.size();
        for(int i = 1;i <= n;i ++){
            sa[i] = v[i-1];
        }
        if(n) build(1,1,n);
        return ;
    }
    void add(int pos,int val,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l == r){
            tre[u].ma = tre[u].mpres = tre[u].msufs = (tre[u].sum += val);
            sa[pos] += val;
            return ;
        }
        if(pos <= mid) add(pos,val,ls,l,mid);
        else add(pos,val,rs,mid+1,r);
        update(u);
        return ;
    }
    void change(int pos,int val){
        add(pos,val-sa[pos]);
        return ;
    }
    node query(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr) return tre[u];
        node BG = {-INF,-INF,-INF,0};
        node res = BG;
        if(cl <= mid) res = query(cl,cr,ls,l,mid);
        if(cr > mid){
            if(res == BG) res = query(cl,cr,rs,mid+1,r);
            else res = merge(res,query(cl,cr,rs,mid+1,r));
        }
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree_Max seg;

void work(){
    int n,m; cin >> n >> m;
    vi v(n);
    rep(i,n) cin >> v[i];
    seg.build(v);
    while(m --){
        int op; cin >> op;
        int x,v,l,r;
        if(op == 1){
            cin >> x >> v;
            seg.change(x,v);
        }
        else{
            cin >> l >> r;
            cout << seg.query(l,r).ma << '\n';
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