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
    struct node{
        int val,cnt;
    }tre[N<<2];  
    node max(const node& a,const node& b){
        if(a.val == b.val) return {a.val, a.cnt+b.cnt};
        if(a.val > b.val) return a;
        return b;
    }
    int sa[N];
    void update(int u){
        tre[u] = max(tre[ls],tre[rs]);
    }
    void build(int u,int l,int r){
        if(l == r){
            tre[u].val = sa[l];
            tre[u].cnt = 1;
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
        return ;
    }
    void add(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u].val += val;
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
    node query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u];
        }
        node res = {-INF,0};
        if(cl <= mid) res = max(res,query(ls,l,mid,cl,cr));
        if(cr > mid) res = max(res,query(rs,mid+1,r,cl,cr));
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree_Max segmax;

void work(){
    int n,m; cin >> n >> m;
    For(i,1,n) cin >> segmax.sa[i];
    segmax.build(1,1,n);
    while(m --){
        int op,a,b; cin >> op >> a >> b;
        if(op == 1) segmax.change(1,1,n,a,b);
        else{
            auto res = segmax.query(1,1,n,a,b);
            cout << res.val << ' ' << res.cnt << '\n';
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