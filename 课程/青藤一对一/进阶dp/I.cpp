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
const int mod = 1000000007;
const int N = 405;
int dp[N][N];
void work(){
    int n; cin >> n;
    vi c(n+1);
    For(i,1,n) cin >> c[i];
    For(len,1,n){
        For(l,1,n-len+1){
            int r = l+len-1;
            if(len == 1) dp[l][r] = 1;
            else dp[l][r] = 1+dp[l+1][r];
            For(k,l+1,r) if(c[l]==c[k]) dp[l][r] = min(dp[l][r],dp[l+1][k-1]+dp[k][r]);
        }
    }
    cout << dp[1][n];
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