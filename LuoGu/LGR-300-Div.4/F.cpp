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
#define se second
#define vpii vector<pair<int,int> >
#define pque priority_queue
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,m,p,q,t; cin >> n >> m >> p >> q >> t;
    unordered_map<int,pair<int,int>>mp;
    For(i,1,n){
        int c; cin >> c;
        For(j,1,c){
            int t; 
            cin >> t; 
            mp[t] = {c,j};
        }
    }
    int L; cin >> L;
    vvi dp(L+1,vi(61,INF));
    dp[0][0] = 0;
    vi s(L+1);
    For(i,1,L) cin >> s[i];
    For(i,1,L){
        auto [c,j] = mp[s[i]];
        rep(_,2) For(k,0,59){
            int la = (k+59)%60;
            dp[i-1][k] = min(dp[i-1][la]+t,dp[i-1][k]);
        }
        For(k,0,59){
            int pos = k%c+1;
            dp[i][k] = dp[i-1][k] + (pos==j?p:q+abs(j-pos));
        }
    }
    int ans = INF;
    For(i,0,59) ans = min(ans,dp[L][i]);
    cout << ans << '\n';
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