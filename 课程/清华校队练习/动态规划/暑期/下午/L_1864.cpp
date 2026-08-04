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
void work(){
    int n,l; cin >> n >> l;
    vi v(n+1), w(n+1);
    For(i,1,n) cin >> v[i] >> w[i];
    vi dp(l+1,INF);
    dp[0] = 0;
    For(i,1,n){
        Rof(j,0,l){
            int R = min(l,j+w[i]);
            dp[R] = min(dp[R], dp[j]+v[i]);
        } 
    }
    if(dp[l] == INF) cout << "no solution";
    else cout << dp[l];
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