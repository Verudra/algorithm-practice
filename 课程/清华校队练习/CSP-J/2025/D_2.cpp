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
const int mod = 998244353;
void work(){
    int n; cin >> n;
    vi v(n), dp(5002);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    int ans = 0; dp[0] = 1;
    For(i,0,n-1){
        For(j,v[i]+1,5001) (ans += dp[j])%=mod;
        Rof(j,0,5001) (dp[min(5001ll,j+v[i])] += dp[j])%=mod;
    }
    cout << ans%mod;
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