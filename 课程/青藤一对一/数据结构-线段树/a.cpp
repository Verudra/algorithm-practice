#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
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
unordered_map<int,bool>mp;
struct Segment_Tree{
    int n,tre[N<<2],tag[N<<2];
    void update(int u){
        tre[u] = tre[ls]==tre[rs]?tre[ls]:-1;
    }
    void pushdown(int u,int l,int r){
        if(!tag[u]) return ;
        tre[ls] = tre[rs] = tag[u];
        tag[ls] = tag[rs] = tag[u];
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
    void change(int cl,int cr,int val,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr){
            tre[u] = val;
            tag[u] = val;
            return ;
        }
        pushdown(u,l,r);
        if(cl <= mid) change(cl,cr,val,ls,l,mid);
        if(cr > mid) change(cl,cr,val,rs,mid+1,r);
        update(u);
        return ;
    }
    int query(int cl,int cr,int u=1,int l=1,int r=0){
        if(!r) r=n;
        if(l >= cl && r <= cr && tre[u] != -1){
            if(tre[u] == 0) return 0;
            if(mp[tre[u]] == false){
                mp[tre[u]] = true;
                return 1;
            }
            return 0;
        }
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
int getid(const vector<int>& v,int val){
    return lower_bound(v.begin(),v.end(),val)-v.begin()+1;
}
vector<int> lsh(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

void work(){
    int n, m; cin >> n >> m;
    vi v1;
    vpii v(m); 
    rep(i,m){
        cin >> v[i].first >> v[i].second; 
        v1.push_back(v[i].fi); v1.push_back(v[i].se+1);
    }
    vi vlsh = lsh(v1);
    seg.build(vector<int>(vlsh.size(),0));
    rep(i,m){
        int l = getid(vlsh,v[i].fi), r = getid(vlsh,v[i].se+1)-1;
        seg.change(l,r,i+1);
    }
    cout << seg.query(1,vlsh.size());
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