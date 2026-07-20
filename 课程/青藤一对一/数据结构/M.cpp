#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
#include<cstring>
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int N = 2e5+10;
int sa[N];
int tre[N<<2];
int tag[N<<2];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid (l+r>>1)
void pushdown(int u,int l,int r){
    tre[ls] += tag[u]*(mid-l+1);
    tre[rs] += tag[u]*(r-mid);
    tag[ls] += tag[u]; tag[rs] += tag[u];
    tag[u] = 0;
    return ;
}
void update(int u){
    tre[u] = tre[ls] + tre[rs];
}
void build(int u,int l,int r){
    if(l == r){
        tre[u] = sa[l];
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    update(u);
}
void add(int u,int l,int r,int cl,int cr,int v){
    int len = r-l+1;
    if(l >= cl && r <= cr){
        tag[u] += v;
        tre[u] += len*v;
        return ;
    }
    pushdown(u,l,r);
    if(cl <= mid) add(ls,l,mid,cl,cr,v);
    if(cr > mid) add(rs,mid+1,r,cl,cr,v);
    update(u);
}
int query(int u,int l,int r,int cl,int cr){
    if(l >= cl && r <= cr){
        return tre[u];
    }
    pushdown(u,l,r);
    int res = 0;
    if(cl <= mid) res += query(ls,l,mid,cl,cr);
    if(cr > mid) res += query(rs,mid+1,r,cl,cr);
    return res;
}
void work(){
    int n,m; cin >> n >> m;
    For(i,1,n) cin >> sa[i];
    build(1,1,n);
    For(i,1,m){
        int op; cin >> op;
        if(op == 1){
            int l,r,v; cin >> l >> r >> v;
            add(1,1,n,l,r,v);
        }
        else{
            int l,r; cin >> l >> r;
            cout << query(1,1,n,l,r) << '\n';
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