#include<bits/stdc++.h>
#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1;i >= 0; i--)
#define For(i, l, r) for(int i = (l); i <= (r); i++)
#define Rof(i, l, r) for(int i = (r); i >= (l); i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define fi first
#define len(s) ((int)s.size())
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int N = 2e5+10;
int ifac[N], fac[N];
int ksm(int a,int p){
    int res = 1;
    while(p){
        if(p&1) res = (res*a)%mod;
        a = a*a%mod;
        p >>= 1;
    }
    return res;
}
int inv(int x){
    return ksm(x,mod-2);
}
int C(int n,int k){
    return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}
void work(){
    int n,k; cin >> n >> k;
    vi a(n);
    int S = 0, Q = 0;
    rep(i,n) cin >> a[i], S = (S+a[i])%mod, Q = (Q+a[i]*a[i]%mod)%mod;
    fac[0] = 1;
    For(i,1,n) fac[i] = (fac[i-1]*i)%mod;
    ifac[n] = inv(fac[n]);
    Rof(i,0,n-1) ifac[i] = ifac[i+1]*(i+1)%mod;
    int ans = Q*C(n-1,k-1)%mod+(k==1?0:(S*S%mod-Q+mod)%mod*C(n-2,k-2)%mod);
    ans %= mod;
    cout << ans;
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