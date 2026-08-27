#include <bits/stdc++.h>
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
const int N = 400010;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
struct Segment_Tree{
    struct node{
        int lv,rv,cnt,trev,tval;
    };
    int n;
    node tre[N<<2];
    int rev(int x){
        return x==0?1:0;
    }
    int dif(int x,int y){
        return x == y?0:1;
    }
    node merge(node a,node b){
        if(a.cnt == -1) return b;
        if(b.cnt == -1) return a;
        return {a.lv,b.rv,a.cnt+b.cnt+dif(a.rv,b.lv),0,-1};
    }
    node emp(){
        return {-1,-1,-1,-1,-1};
    }
    void update(int u){
        tre[u] = merge(tre[ls],tre[rs]);
    }
    void cz(int u,int tval,int trev){
        if(tval != -1){
            tre[u].cnt = 0;
            tre[u].lv = tre[u].rv = tval;
            tre[u].tval = tval; tre[u].trev = 0;
        }
        if(trev){
            tre[u].lv = rev(tre[u].lv);
            tre[u].rv = rev(tre[u].rv);
            (tre[u].trev += 1) %= 2;
        }
    }
    void pushdown(int u,int l,int r){
        auto &trev = tre[u].trev, &tval = tre[u].tval;
        cz(ls,tval,trev);
        cz(rs,tval,trev);
        trev = 0; tval = -1;
    }
    void build(int u,int l,int r,const vector<int>& v){
        tre[u] = emp();
        if(l == r){
            tre[u].lv = tre[u].rv = v[l-1];
            tre[u].cnt = 0; tre[u].trev = 0;
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
    void change(int cl,int cr,int v,int u=1,int l=1,int r=0){
        if(!r) r = n;
        if(l >= cl && r <= cr){
            tre[u].tval = v;
            tre[u].lv = tre[u].rv = v;
            tre[u].trev = 0;
            tre[u].cnt = 0;
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) change(cl,cr,v,ls,l,mid);
        if(cr > mid) change(cl,cr,v,rs,mid+1,r);
        update(u);
    }
    void reverse(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r = n;
        if(l >= cl && r <= cr){
            tre[u].lv = rev(tre[u].lv);
            tre[u].rv = rev(tre[u].rv);
            (tre[u].trev +=1 )%=2;
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) reverse(cl,cr,ls,l,mid);
        if(cr > mid) reverse(cl,cr,rs,mid+1,r);
        update(u);
    }
    node query(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr) return tre[u];
        pushdown(u,l,r);
        node res = emp();
        if(cl <= mid) res = merge(res,query(cl,cr,ls,l,mid));
        if(cr > mid) res = merge(res,query(cl,cr,rs,mid+1,r));
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree seg;

void work(){
    int n,m; cin >> n >> m;
    vi sa(n);
    rep(i,n) cin >> sa[i];
    seg.build(sa);
    while(m--){
        int op,l,r,x; cin >> op;
        if(op == 1){
            cin >> l >> r >> x;
            if(l > r) swap(l,r);
            seg.change(l,r,x);
        }
        else if(op == 2){
            cin >> l >> r;
            if(l > r) swap(l,r);
            seg.reverse(l,r);
        }
        else{
            cin >> l >> r;
            if(l > r) swap(l,r);
            cout << seg.query(l,r).cnt << '\n';
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}