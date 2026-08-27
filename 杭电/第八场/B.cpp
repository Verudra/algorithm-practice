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
// typedef long long ll;
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 500010;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
struct Segment_Tree{
    int n,tre[N<<2],tag[N<<2];
    void update(int u){
        tre[u] = tre[ls]+tre[rs];
    }
    void pushdown(int u,int l,int r){
        if(!tag[u]) return ;
        tre[ls] += (mid-l+1)*tag[u];
        tre[rs] += (r-mid)*tag[u];
        tag[ls] += tag[u];
        tag[rs] += tag[u];
        tag[u] = 0;
    }
    void build(int u,int l,int r,const vector<int>& v){
        tag[u] = 0;
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
            tre[u] += (r-l+1)*val;
            tag[u] += val;
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
        return res;
    }
}T1,T2;
#undef ls
#undef rs
#undef mid
Segment_Tree seg;

void work(){
    int n,m; cin >> n >> m;
    vi a(n),b(n);
    T1.build(vi(n,0));
    T2.build(vi(n,0));
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n){
        if(i > 0){
            a[i] += a[i-1];
            b[i] += b[i-1];
        }
    }
    For(i,1,m){
        int op; cin >> op;
        int l,r,x;
        if(op == 1){
            cin >> l >> r >> x;
            T1.add(l,r,x);
            T2.add(l,r,i*x);
        }
        else{
            cin >> l >> r;
            l --; r --;
            int ans = a[r]-(l==0?0:a[l-1]) + i*(b[r]-(l==0?0:b[l-1]));
            ans += T1.query(l+1,r+1)*i - T2.query(l+1,r+1);
            cout << ans << '\n';
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