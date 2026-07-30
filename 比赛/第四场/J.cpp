#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<cstring>
#include<cmath>
#include<unordered_map>
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
    vi v(n+1), la(n+1), mp(n+1), ps(n+1), pmx(n+1);
    For(i,1,n) cin >> v[i];
    vi dp(n+1);
    int cnt = 0;
    For(i,1,n){
        if(mp[v[i]] % 4 == 0) cnt ++;
        if((mp[v[i]]+1)%4 == 0){
            pmx[i] = la[v[i]];
            la[v[i]] = i;
            cnt --;
            pmx[i] = max(pmx[i], pmx[i-1]);
            if(cnt == 0){
                int L = pmx[i], R = i-1;
                if(L != 0) dp[i] = ps[R]-ps[L-1];
                else if(L == 0){
                    dp[i] = ps[R];
                    dp[i] ++;
                }
            }
        }
        mp[v[i]] ++;
        ps[i] = (ps[i-1]+dp[i]+mod)%mod;
        dp[i] = (dp[i]+mod)%mod;
        pmx[i] = max(pmx[i], pmx[i-1]);
    }
    // cout << "v:"; For(i,1,n) cout << v[i] << ' ';
    // cout << '\n';
    // cout << "la:"; For(i,1,n) cout << la[i] << ' ';
    // cout << '\n';
    // cout << "ps:"; For(i,1,n) cout << ps[i] << ' ';
    // cout << '\n';
    // cout << "pmx:"; For(i,1,n) cout << pmx[i] << ' ';
    // cout << '\n'; 
    // cout << "dp:"; For(i,1,n) cout << dp[i] << ' ';
    // cout << '\n';
    cout << dp[n] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    cin >> T;
    while(T --) work();
    return 0;
}