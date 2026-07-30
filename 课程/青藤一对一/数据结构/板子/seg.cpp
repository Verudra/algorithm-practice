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
struct Segment_Tree{
    int sa[N],tre[N<<2],tag[N<<2];
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
    void build(int u,int l,int r){
        tag[u] = 0;
        if(l == r){
            tre[u] = sa[l];
            return ;
        }
        build(ls,l,mid);
        build(rs,mid+1,r);
        update(u);
    }
    void add(int u,int l,int r,int cl,int cr,int val){
        if(l >= cl && r <= cr){
            tre[u] += (r-l+1)*val;
            tag[u] += val;
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) add(ls,l,mid,cl,cr,val);
        if(cr > mid) add(rs,mid+1,r,cl,cr,val);
        update(u);
    }
    int query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr) return tre[u];
        pushdown(u,l,r);
        int res = 0;
        if(cl <= mid) res += query(ls,l,mid,cl,cr);
        if(cr > mid) res += query(rs,mid+1,r,cl,cr);
        return res;
    }
};
#undef ls
#undef rs
#undef mid
Segment_Tree seg;


void work(){
    
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}