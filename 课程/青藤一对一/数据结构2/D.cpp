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
    void addk(int l,int r,int k){
        add(l,k); add(r+1,-k);
    }
    void addb(int l,int r,int b){
        add(l,b); add(r+1,-b);
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
BIT bitk, bitb;

void work(){
    int n,m; cin >> n >> m;
    bitk.init(n); bitb.init(n);
    vi v(n+1);
    For(i,1,n) cin >> v[i];
    while(m --){
        int op; cin >> op;
        if(op == 2){
            int x; cin >> x;
            cout << v[x] + bitk.query(x)*x + bitb.query(x) << '\n';
        }
        else{
            int l,r,a,d; cin >> l >> r >> a >> d;
            bitk.addk(l,r,d);
            bitb.addb(l,r,a-l*d);
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