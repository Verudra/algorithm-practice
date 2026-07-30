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
const int N = 400010;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
struct node{
    int _2,_1,_0,_21,_10,_20,_210;
    node operator| (node b)const{
        return {(_2|b._2),
                (_1|b._1),
                (_0|b._0),  
                (_21|b._21|(_2&b._1)),
                (_10|b._10|(_1&b._0)),  
                (_20|b._20|(_2&b._0)),
                (_210|b._210|(_2&b._10)|(_21&b._0))};
        }
    };
struct Segment_Tree_Max{
    node tre[N<<2];
    int sa[N];
    node merge(node a,node b){
        return a|b;
    }
    void update(int u){
        tre[u] = merge(tre[ls],tre[rs]);
    }
    void build(int u,int l,int r){
        if(l == r){
            tre[u]._0 = tre[u]._1 = tre[u]._2 = tre[u]._10 = tre[u]._20 = tre[u]._21 = tre[u]._210 = 0;
            if(sa[l] == 0) tre[u]._0 = 1;
            else if(sa[l] == 1) tre[u]._1 = 1;
            else if(sa[l] == 2) tre[u]._2 = 1;
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
        return ;
    }
    void change(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u]._0 = tre[u]._1 = tre[u]._2 = 0;
            if(val == 0) tre[u]._0 = 1;
            else if(val == 1) tre[u]._1 = 1;
            else if(val == 2) tre[u]._2 = 1; 
            return ; 
        }
        if(pos <= mid) change(ls,l,mid,pos,val);
        else change(rs,mid+1,r,pos,val);
        update(u);
        return ;
    }
    node query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u];
        }
        node res = {0,0,0,0,0,0};
        if(cl <= mid) res = merge(res,query(ls,l,mid,cl,cr));
        if(cr > mid) res = merge(res,query(rs,mid+1,r,cl,cr));
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree_Max seg;

void work(){
    int n,q; cin >> n >> q;
    For(i,1,n) cin >> seg.sa[i];
    seg.build(1,1,n);
    while(q --){
        int op; cin >> op;
        int p,x,l,r; 
        if(op == 1){
            cin >> p >> x;
            seg.change(1,1,n,p,x);
        }
        else{
            cin >> l >> r;
            node res = seg.query(1,1,n,l,r);
            if(res._210 == 1) cout << '2' << '\n';
            else if(res._10|res._21|res._20) cout << '1' << '\n';
            else cout << '0' << '\n';
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