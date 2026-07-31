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
const int N = 1e5+10;
struct Segment_Tree{
    #define mid (l+r>>1)
    struct node1{
        int val,pos;
    };
    struct node{
        node1 v;
        int l,r; 
    };
    node tre[60*N];
    int tot = 1;
    void init(){
        tre[1].l = tre[1].r = tre[1].v.pos = tre[1].v.val = 0;
        tot = 1;
    }
    int add(){
        tot ++;
        tre[tot].l = tre[tot].r = tre[tot].v.pos = tre[tot].v.val = 0;
        return tot;
    }
    void update(int u){
        int maxn = 0, maxpos = 0;
        if(tre[u].l){
            if(tre[tre[u].l].v.val > maxn) maxn = tre[tre[u].l].v.val, maxpos = tre[tre[u].l].v.pos;
        }
        if(tre[u].r){
            if(tre[tre[u].r].v.val > maxn) maxn = tre[tre[u].r].v.val, maxpos = tre[tre[u].r].v.pos;
        }
        tre[u].v.pos = maxpos;
        tre[u].v.val = maxn;
        return ;
    }
    void change(int u,int l,int r,int pos,int val){
        if(l == r){
            tre[u].v.val = max(tre[u].v.val, val);
            tre[u].v.pos = l;
            return ;
        }
        if(pos <= mid){
            if(!tre[u].l) tre[u].l = add();
            change(tre[u].l,l,mid,pos,val);
        }
        else{
            if(!tre[u].r) tre[u].r = add();
            change(tre[u].r,mid+1,r,pos,val);
        }
        update(u);
    }
    node1 query(int u,int l,int r,int cl,int cr){
        if(l >= cl && r <= cr){
            return tre[u].v;
        }
        node1 t = {0,0};
        if(cl <= mid && tre[u].l) t = query(tre[u].l,l,mid,cl,cr);
        if(cr > mid && tre[u].r){
            auto res = query(tre[u].r,mid+1,r,cl,cr);
            if(res.val > t.val) t = res;
        }
        return t;
    }
}tt;
void work(){
    tt.init();
    int n; cin >> n; vi v(n+1);
    For(i,1,n) cin >> v[i];
    int ans = 0;
    For(i,1,n){
        auto res = tt.query(1,1,1e18,1,v[i]);
        ans = max(ans,res.val+1);
        if(res.pos+v[i] > 1e18) continue;
        tt.change(1,1,1e18,res.pos+v[i],res.val+1);
    }
    cout << ans << '\n';
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