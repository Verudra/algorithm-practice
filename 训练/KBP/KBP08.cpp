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
int getid(const vector<int>& v,int val){
    return lower_bound(v.begin(),v.end(),val)-v.begin()+1;
}
vector<int> lsh(vector<int> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}
const int N = 2e5+10;
int rt[N];
#define mid (l+r>>1)
struct Segment_Tree{
    struct node{
        int ls,rs,val;
    };
    node tre[N*20]; int tot;
    void update(int u){
        tre[u].val = tre[tre[u].ls].val + tre[tre[u].rs].val;
        return ;
    }
    void change(int lstu,int& u,int l,int r,int pos,int val){
        if(!u) u = ++tot;
        if(l == r){
            tre[u].val += val;
            return ;
        }
        if(pos <= mid){
            tre[u].rs = tre[lstu].rs;
            tre[u].ls = ++tot;
            tre[tre[u].ls] = tre[tre[lstu].ls];
            change(tre[lstu].ls,tre[u].ls,l,mid,pos,val);
        }
        else{
            tre[u].ls = tre[lstu].ls;
            tre[u].rs = ++tot;
            tre[tre[u].rs] = tre[tre[lstu].rs];
            change(tre[lstu].rs,tre[u].rs,mid+1,r,pos,val);
        }
        update(u);
    }
    int query(int u1,int u2,int l,int r,int k){
        if(l == r) return l;
        int tmp = tre[tre[u2].ls].val-tre[tre[u1].ls].val;
        if(tmp >= k) return query(tre[u1].ls,tre[u2].ls,l,mid,k);
        else return query(tre[u1].rs,tre[u2].rs,mid+1,r,k-tmp);
    }
}T;
void work(){
    int n,q; cin >> n >> q;
    vi v(n); rep(i,n) cin >> v[i];
    vi lv = lsh(v);
    For(i,1,n) T.change(rt[i-1],rt[i],1,lv.size(),getid(lv,v[i-1]),1);
    For(i,1,q){
        int l,r,k; cin >> l >> r >> k;
        cout << lv[T.query(rt[l-1],rt[r],1,lv.size(),k)-1] << '\n';
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