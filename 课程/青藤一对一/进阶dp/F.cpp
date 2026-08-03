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
    int n; cin >> n; vi v(n+1);
    vi ps(n+1);
    memset(dp,0x3f,sizeof dp);
    For(i,1,n) cin >> v[i], ps[i] = ps[i-1]+v[i], dp[i][i] = 0;
    For(len,2,n){
        For(l,1,n-len+1){
            int r = l+len-1;
            For(k,l,r-1){
                dp[l][r] = min(dp[l][k]+dp[k+1][r]+ps[r]-ps[l-1], dp[l][r]);
            } 
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