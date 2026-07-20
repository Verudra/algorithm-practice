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
int n,m;
int tre[N<<2];
int sa[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid (l+r>>1)
void build(int u,int l,int r){
    if(l == r){
        tre[u] = sa[l];
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    tre[u] = max(tre[ls],tre[rs]);
}
void add(int u,int l,int r,int pos,int val){
    if(l == r){
        tre[u] = val;
        return ;
    }
    if(pos <= mid) add(ls,l,mid,pos,val);
    else add(rs,mid+1,r,pos,val);
    tre[u] = max(tre[ls],tre[rs]);
}
int query(int u,int l,int r,int cl,int cr){
    if(l >= cl && r <= cr) return tre[u];
    int res = -INF;
    if(cl <= mid) res = max(res,query(ls,l,mid,cl,cr));
    if(cr > mid) res = max(res,query(rs,mid+1,r,cl,cr));
    return res;
}
void work(){
    int n,m;
    cin >> n >> m;
    For(i,1,n) cin >> sa[i];
    build(1,1,n);
    For(i,1,m){
        int op,a,b; cin >> op >> a >> b;
        if(op == 1) add(1,1,n,a,b);
        else cout << query(1,1,n,a,b) << '\n';
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