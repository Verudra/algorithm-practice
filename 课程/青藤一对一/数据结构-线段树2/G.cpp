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
    int n,tre[N<<2],tag[N<<2];
    void update(int u){
        tre[u] = tre[ls]+tre[rs];
    }
    void pushdown(int u,int l,int r){
        if(!tag[u]) return ;
        tre[ls] = (mid-l+1)-tre[ls];
        tre[rs] = (r-mid)-tre[rs];
        tag[ls] = !tag[ls];
        tag[rs] = !tag[rs];
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
    void add(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr){
            tre[u] = (r-l+1)-tre[u];
            tag[u] = !tag[u];
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) add(cl,cr,ls,l,mid);
        if(cr > mid) add(cl,cr,rs,mid+1,r);
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
};
#undef ls
#undef rs
#undef mid
Segment_Tree seg;

void work(){
    int n,m; cin >> n >> m;
    string s; cin >> s;
    vi v(n); rep(i,n) v[i] = s[i]=='1';
    seg.build(v);
    while(m --){
        int op; cin >> op;
        int l,r; cin >> l >> r;
        if(op == 1) seg.add(l,r);
        else cout << seg.query(l,r) << '\n';
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