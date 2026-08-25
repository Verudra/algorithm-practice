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
struct Tree_sequence{
    int tre[N],n;
    void build(int n1){
        n = n1;
        For(i,1,n1) tre[i] = 0;
        return ;
    }
    int lowbit(int x){
        return x&-x;
    }
    void change(int pos,int val){
        while(pos <= n){
            tre[pos] = max(tre[pos],val);
            pos += lowbit(pos);
        }
        return ;
    }
    int query(int pos){
        int res = 0;
        while(pos){
            res = max(tre[pos],res);
            pos -= lowbit(pos);
        }
        return res;
    }
}T;
struct node{
    int l,r,op,id;
}sa[N];
struct node2{
    int id,val;
}ans[N];
bool cmp2(node2 a,node2 b){
    return a.id < b.id;
}
bool cmp1(node a,node b){
    if(a.l != b.l) return a.l > b.l;
    return a.op < b.op;
}
int lsh[N<<1];
void work(){
    int n,q; cin >> n >> q;
    int cnt = 0,cntans = 0;
    For(i,1,n){
        cin >> sa[i].l >> sa[i].r;
        sa[i].id = i; sa[i].op = 1;
        lsh[++cnt] = sa[i].l;
        lsh[++cnt] = sa[i].r;
    }
    For(i,1,q){
        int j = i+n;
        cin >> sa[j].l >> sa[j].r;
        sa[j].id = i; sa[j].op = 2;
        lsh[++cnt] = sa[j].l;
        lsh[++cnt] = sa[j].r;
    }
    sort(lsh+1,lsh+1+cnt);
    cnt = unique(lsh+1,lsh+1+cnt)-lsh-1;
    int R = cnt;
    T.build(R);
    sort(sa+1,sa+1+n+q,cmp1);
    for(int i = 1;i <= n+q;i ++){
        auto [l,r,op,id] = sa[i];
        if(op == 1){
            T.change(lower_bound(lsh+1,lsh+1+cnt,r)-lsh,r-l+1);
        }else{
            ans[++cntans] = {id,T.query(lower_bound(lsh+1,lsh+1+cnt,r)-lsh)};
        }
    }
    sort(ans+1,ans+1+cntans,cmp2);
    For(i,1,cntans) cout << ans[i].val << '\n';
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