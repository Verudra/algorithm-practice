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
    int n; cin >> n;
    vi v(n+1); vvi dp0(n+1,vi(2,0)), dp1(n+1,vi(2,0));
    For(i,1,n) cin >> v[i];
    For(i,1,n){
        if(i == 1){
            dp1[1][1] = v[1];
            continue;
        }
        if(i == n){
            dp0[i][1] = dp0[i-1][0]+v[i];
            dp0[i][0] = max(dp0[i-1][1],dp0[i-1][0]);
            continue;
        }
        dp0[i][1] = dp0[i-1][0]+v[i];
        dp0[i][0] = max(dp0[i-1][1], dp0[i-1][0]);
        dp1[i][1] = dp1[i-1][0]+v[i];
        dp1[i][0] = max(dp1[i-1][1], dp1[i-1][0]);
    }
    cout << max({dp0[n][0],dp0[n][1],dp1[n-1][1],dp1[n-1][0]});
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