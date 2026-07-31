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
const int N = 1e6;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
struct Segment_Tree{
    int n,tre[N<<2],tag[N<<2];
    bool vis[N<<2];
    void update(int u){
        tre[u] = max(tre[ls],tre[rs]);
    }
    void pushdown(int u){
        if(vis[u]){
            tre[ls] = tre[rs] = tag[u];
            tag[ls] = tag[rs] = tag[u];
            vis[ls] = vis[rs] = true;
            tag[u] = 0;
            vis[u] = false;
        }
        else if(tag[u]){
            tre[ls] += tag[u];
            tre[rs] += tag[u];
            tag[ls] += tag[u];
            tag[rs] += tag[u];
            tag[u] = 0;
        }
    }
    void build(int u,int l,int r,const vector<int>& v){
        tag[u] = 0;
        vis[u] = false;
        if(l == r){
            tre[u] = v[l-1];
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
    void add(int cl,int cr,int val,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr){
            tre[u] += val;
            tag[u] += val;
            return ;
        }
        pushdown(u);
        if(cl <= mid) add(cl,cr,val,ls,l,mid);
        if(cr > mid) add(cl,cr,val,rs,mid+1,r);
        update(u);
        return ;
    }
    void change(int cl,int cr,int val,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr){
            tre[u] = val;
            tag[u] = val;
            vis[u] = true;
            return ;
        }
        pushdown(u);
        if(cl <= mid) change(cl,cr,val,ls,l,mid);
        if(cr > mid) change(cl,cr,val,rs,mid+1,r);
        update(u);
        return ;
    }
    int query(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr) return tre[u];
        pushdown(u);
        int res = -INF;
        if(cl <= mid) res = max(query(cl,cr,ls,l,mid),res);
        if(cr > mid) res = max(query(cl,cr,rs,mid+1,r),res);
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree seg;

void work(){
    int n,q; cin >> n >> q;
    vi v(n);
    rep(i,n) cin >> v[i];
    seg.build(v);
    while(q --){
        int op; cin >> op;
        if(op == 1){
            int l,r,x; cin >> l >> r >> x;
            seg.change(l,r,x);
        }
        else if(op == 2){
            int l,r,x; cin >> l >> r >> x;
            seg.add(l,r,x);
        }
        else{
            int l,r; cin >> l >> r;
            cout << seg.query(l,r) << '\n';
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