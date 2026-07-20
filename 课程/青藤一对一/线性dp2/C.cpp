#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
    int n; cin >> n;
    vi v(n+1); vi dp(n+1);
    For(i,1,n) cin >> v[i];
    dp[1] = v[1];
    dp[2] = max(v[1],v[2]);
    For(i,3,n) dp[i] = max(dp[i-1], dp[i-2]+v[i]);
    cout << dp[n];
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}