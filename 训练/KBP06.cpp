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
const int mod = 998244353;
const int N = 2e5+10;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid (l+r>>1)
struct Segment_treee{
    struct node{
        int a,b;
    };
    node tre[N<<2];
    node sa[N];
    node merge(node a,node b){
        return {a.a*b.a%mod, (b.a*a.b%mod+b.b)%mod};
    }
    void update(int u){
        tre[u] = merge(tre[ls],tre[rs]);
    }
    void build(int u,int l,int r){
        if(l == r){
            tre[u].a = sa[l].a;
            tre[u].b = sa[l].b;
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
    }
    void change(int u,int l,int r,int pos,int va,int vb){
        if(l == r){
            tre[u].a = va;
            tre[u].b = vb;
            return ;
        }
        if(pos <= mid) change(ls,l,mid,pos,va,vb);
        if(pos > mid) change(rs,mid+1,r,pos,va,vb);
        update(u);
    }
    node query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u];
        }
        node res = {1,0};
        if(cl <= mid) res = merge(res,query(ls,l,mid,cl,cr));
        if(cr > mid) res = merge(res,query(rs,mid+1,r,cl,cr));
        return res;
    }
}T;
void work(){
    int n,q; cin >> n >> q;
    For(i,1,n){
        cin >> T.sa[i].a >> T.sa[i].b;
    }  
    T.build(1,1,n);
    while(q --){
        int op; cin >> op;
        int p,a,b,l,r,x;
        if(op == 1){
            cin >> p >> a >> b;
            T.change(1,1,n,p,a,b);
        }
        else{
            cin >> l >> r >> x;
            auto res = T.query(1,1,n,l,r);
            cout << (res.a*x%mod+res.b)%mod << '\n';
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