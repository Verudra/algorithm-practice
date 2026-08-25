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
const int N = 8e5+10;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid (l+r>>1)
struct Segment_Tree{
    int tre[N<<2];
    void build(int u,int l,int r){
        tre[u] = 0;
        if(l == r) return ;
        build(ls,l,mid);
        build(rs,mid+1,r);
    }
    void update(int u){
        tre[u] = max(tre[ls],tre[rs]);
    }
    void change(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u] = max(val,tre[u]);
            return ;
        }
        if(pos <= mid) change(ls,l,mid,pos,val);
        if(pos > mid) change(rs,mid+1,r,pos,val);
        update(u);
    }
    int query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u];
        }
        int res = 0;
        if(cl <= mid) res = max(res,query(ls,l,mid,cl,cr));
        if(cr > mid) res = max(res,query(rs,mid+1,r,cl,cr));
        return res;
    }
}T;
int getid(const vector<int>& v,int val){
    return lower_bound(v.begin(),v.end(),val)-v.begin()+1;
}
vector<int> lsh(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}
struct node{
    int l,r,op,id;
};
struct node2{
    int id,val;
};
bool cmp2(node2 a,node2 b){
    return a.id < b.id;
}
bool cmp1(node a,node b){
    if(a.l != b.l) return a.l > b.l;
    return a.op < b.op;
}
void work(){
    int n,q; cin >> n >> q;
    vector<node>vec; vi lv;
    For(i,1,n){
        node t; cin >> t.l >> t.r;
        t.id = i; t.op = 1;
        vec.push_back(t);
        lv.push_back(t.l); lv.push_back(t.r);
    }
    For(i,1,q){
        node t; cin >> t.l >> t.r;
        t.id = i+n; t.op = 2;
        vec.push_back(t);
        lv.push_back(t.l); lv.push_back(t.r);
    }
    lv = lsh(lv);
    int R = lv.size();
    T.build(1,1,R);
    sort(vec.begin(),vec.end(),cmp1);
    vector<node2>ans;
    for(auto [l,r,op,id] : vec){
        if(op == 1){
            // cout << "!";
            T.change(1,1,R,getid(lv,r),r-l+1);
        }else{
            // cout << "!";
            ans.push_back({id,T.query(1,1,R,1,getid(lv,r))});
        }
    }
    sort(ans.begin(),ans.end(),cmp2);
    for(auto [id,val]:ans) cout << val << '\n';
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
