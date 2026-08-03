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
const int N = 105;
const int M = 15;
int mp[N],dp[N][70][70];
void work(){
    int n,m; cin >> n >> m;
    For(i,1,n){
        rep(j,m){
            char c; cin >> c;
            if(c == 'H') mp[i] |= (1<<j);
        }
    }
    vi stat,cnt;
    rep(i,1<<m) if(!(i&(i<<1))&&!(i&(i<<2))) stat.push_back(i),cnt.push_back(__builtin_popcountll(i));
    // cout << "!!!" << stat.size() << '\n';
    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0; int S = stat.size();
    For(i,1,n){
        rep(j,S){
            if(stat[j]&mp[i]) continue;
            rep(k,S){
                if(stat[j]&stat[k]) continue;
                rep(l,S){
                    if(stat[j]&stat[l] || stat[k]&stat[l]) continue;
                    if(dp[i-1][k][l] == -1) continue;
                    dp[i][j][k] = max(dp[i-1][k][l]+cnt[j], dp[i][j][k]);
                }
            }
        }
    }
    int ans = 0;
    rep(i,S){
        rep(j,S){
            ans = max(ans,dp[n][i][j]);
        }
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