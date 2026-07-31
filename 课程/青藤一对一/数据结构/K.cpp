#include<iostream>
#include<vector>
#include<stack>
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
#define vpii vector<pair<int,int> >
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
    int tre[N<<2],sa[N];
    void update(int u){
        tre[u] = max(tre[ls],tre[rs]);
    }
    void build(int u,int l,int r){
        if(l == r){
            tre[u] = sa[l];
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
        return ;
    }
    void add(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u] += val;
            sa[pos] += val;
            return ;
        }
        if(pos <= mid) add(ls,l,mid,pos,val);
        else add(rs,mid+1,r,pos,val);
        update(u);
        return ;
    }
    void change(int u,int l,int r,int pos,int val){
        add(u,l,r,pos,val-sa[pos]);
        return ;
    }
    int query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u];
        }
        int res = -INF;
        if(cl <= mid) res = max(res,query(ls,l,mid,cl,cr));
        if(cr > mid) res = max(res,query(rs,mid+1,r,cl,cr));
        return res;
    }
    int first(int u,int l,int r,int cl,int val){
        if(r < cl || tre[u] < val) return -1;
        if(l == r) return l;
        int res = first(ls,l,mid,cl,val);
        if(res == -1) res = first(rs,mid+1,r,cl,val);
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree_Max segmax;

void work(){
    int n,m; cin >> n >> m;
    vi v(n); For(i,1,n) cin >> segmax.sa[i];
    segmax.build(1,1,n);
    while(m --){
        int l,x; cin >> l >> x;
        int res = segmax.first(1,1,n,l,x);
        if(res == -1) cout << "-1\n";
        else{
            cout << res << '\n';
            segmax.add(1,1,n,res,-x);
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}