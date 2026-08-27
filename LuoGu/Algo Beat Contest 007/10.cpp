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
const int mod = 911471543;
int ksm(int a,int p){
    int res = 1;
    while(p){
        if(p&1) res = res*a%mod;
        a = a*a%mod;
        p >>= 1;
    }
    return res;
}
int inv(int x){
    return ksm(x,mod-2);
}
void work(){
    int n; cin >> n;
    int jc = 1;
    For(i,1,n) jc = jc*i%mod;
    int ans = ksm(2,n-1)*inv(jc)%mod;
    int la = ans;
    int inv2 = inv(2);
    Rof(i,1,n-1){
        la = la*(i+1)%mod*inv2%mod;
        ans = (ans+la)%mod;
    }
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