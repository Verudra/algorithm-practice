#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
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
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,k; cin >> n >> k;
    vi v(n+1),dp(k+1,-INF);
    dp[0] = 0;
    For(i,1,n) cin >> v[i];
    For(i,1,n){
        int mx = dp[0];
        Rof(j,1,k){
            mx = max(mx,dp[j]);
            dp[j] = dp[j-1]+v[i];
        }
        dp[0] = mx;
    }
    int ans = 0;
    For(i,0,k) ans = max(ans,dp[i]);
    cout << ans;
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}