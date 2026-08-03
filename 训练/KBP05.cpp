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
int mod = 1000000007;
const int N = 200010;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int norm(int x){
    return (x%mod+mod)%mod;
}
struct Segment_Tree{
    int n,tre[N<<2],tag[N<<2],tagmul[N<<2];
    void update(int u){
        tre[u] = (tre[ls]+tre[rs])%mod;
    }
    void apply(int u,int l,int r,int add,int mul){
        tre[u] = (tre[u]*mul%mod + add*(r-l+1)%mod)%mod;
        tag[u] = (tag[u]*mul%mod + add)%mod;
        tagmul[u] = tagmul[u]*mul%mod;
        return ;
    }
    void pushdown(int u,int l,int r){
        apply(ls,l,mid,tag[u],tagmul[u]);
        apply(rs,mid+1,r,tag[u],tagmul[u]);
        tag[u] = 0; tagmul[u] = 1;
        return ;
    }
    void build(int u,int l,int r,const vector<int>& v){
        tag[u] = 0; tagmul[u] = 1;
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
    void mult(int cl,int cr,int val,int u=1,int l=1,int r=0){
        if(!r) r = n;
        if(l >= cl && r <= cr){
            apply(u,l,r,0,val);
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) mult(cl,cr,val,ls,l,mid);
        if(cr > mid) mult(cl,cr,val,rs,mid+1,r);
        update(u);
    }
    void add(int cl,int cr,int val,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr){
            apply(u,l,r,val,1);
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) add(cl,cr,val,ls,l,mid);
        if(cr > mid) add(cl,cr,val,rs,mid+1,r);
        update(u);
        return ;
    }
    int query(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr) return tre[u];
        pushdown(u,l,r);
        int res = 0;
        if(cl <= mid) res += query(cl,cr,ls,l,mid);
        if(cr > mid) res += query(cl,cr,rs,mid+1,r);
        return res%mod;
    }
}T;
#undef ls
#undef rs
#undef mid
Segment_Tree seg;

void work(){
    int n,q,p; cin >> n >> q >> mod;
    vi v(n);rep(i,n) {cin >> v[i];v[i]=norm(v[i]);}
    T.build(v);
    while(q --){
        int op; cin >> op;
        int l,r,k;
        if(op == 1){
            cin >> l >> r >> k;
            k = norm(k);
            T.mult(l,r,k);
        }
        else if(op == 2){
            cin >> l >> r >> k;
            k = norm(k);
            T.add(l,r,k);
        }
        else{
            cin >> l >> r;
            cout << T.query(l,r) << '\n';
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