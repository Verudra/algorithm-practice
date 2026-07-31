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
struct BIT{
    int n,sa[N],tre[N];
    int lowbit(int x){
        return x&-x;
    }
    void init(int _n){
        n = _n;
        for(int i = 1;i <= n;i ++){
            sa[i] = tre[i] = 0;
        }
        return ;
    }
    void add(int pos,int val){
        if(pos <= 0 || pos > n) return ;
        sa[pos] += val;
        while(pos <= n){
            tre[pos] += val;
            pos += lowbit(pos);
        }
        return ;
    }
    void build(const vector<int>& v){
        n = v.size();
        for(int i = 1;i <= n;i ++){
            sa[i] = tre[i] = v[i-1];
        }
        for(int i = 1;i <= n;i ++){
            int j = i+lowbit(i);
            if(j <= n) tre[j] += tre[i];
        }
        return ;
    }
    int query(int pos){
        int res = 0;
        while(pos > 0){
            res += tre[pos];
            pos -= lowbit(pos);
        }
        return res;
    }
    int query(int l,int r){
        return query(r)-query(l-1);
    }
    void change(int pos,int val){
        if(pos <= 0 || pos > n) return ;
        add(pos,val-sa[pos]);
        return ;
    }
};
BIT bit;

void work(){
    int n,m; cin >> n >> m;
    vi v(n);
    rep(i,n) cin >> v[i];
    bit.build(v);
    while(m --){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) bit.change(a,b);
        else cout << bit.query(a,b) << '\n';
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