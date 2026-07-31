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
const int K = 18;
short lg2[N];
void init_lg2(int n){
    lg2[0] = lg2[1] = 0;
    for(int i = 2;i <= n;i ++){
        lg2[i] = lg2[i/2]+1;
    }
    return ;
}
int n,m; 
struct ST_min{
    int st[N][K];
    int query(int l,int r){
        int cm = lg2[r-l+1];
        return min(st[l][cm],st[r-(1LL<<cm)+1][cm]);
    }
    void build(const vector<int>& v){
        int n = v.size();
        init_lg2(n);
        for(int i = 0;i < n;i ++){
            st[i+1][0] = v[i];
        }
        for(int k = 1;k < K && (1LL<<k) <= n;k ++){
            for(int i = 1;i+(1LL<<k)-1 <= n;i ++){
                st[i][k] = min(st[i][k-1],st[i+(1LL<<(k-1))][k-1]);
            }
        }
        return ;
    }
};
ST_min stmin;

void work(){
    int n,m; cin >> n >> m;
    vi v(n);
    rep(i,n) cin >> v[i];
    stmin.build(v);
    while(m --){
        int l,r; cin >> l >> r;
        if(l <= r) cout << stmin.query(l,r) << '\n';
        else cout << min(stmin.query(l,n),stmin.query(1,r)) << '\n';
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