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
const int N = 25;
int dis[N][N];
int dp[1<<20][N];
void work(){
    int n; cin >> n;
    For(i,0,n-1) For(j,0,n-1) cin >> dis[i][j];
    memset(dp,0x3f,sizeof(dp));
    For(i,1,n-1) if(dis[0][i] != -1) dp[1<<i-1][i] = dis[0][i];
    For(mask,1,(1<<n-1)-1){
        For(i,1,n-1){
            if(!((1<<i-1)&mask)) continue;
            if(dp[mask][i] > INF/2) continue;
            For(j,1,n-1){
                if((1<<j-1)&mask) continue;
                if(dis[i][j] == -1) continue;
                dp[mask|(1<<j-1)][j] = min(dp[mask][i]+dis[i][j], dp[mask|(1<<j-1)][j]);
            }
        }
    }
    int ans = INF;
    For(i,1,n-1) if(dis[i][0]!=-1) ans = min(ans, dp[(1<<n-1)-1][i]+dis[i][0]);
    if(ans != INF) cout << ans;
    else cout << "-1";
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