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
    int n; cin >> n;
    vvi v(n+1,vi(n+1,0));
    For(i,1,n) For(j,1,n) cin >> v[i][j];
    For(i,1,n) For(j,1,n) v[i][j] = v[i-1][j]+v[i][j-1]-v[i-1][j-1]+v[i][j];
    int ans = INF, ansk = -1;
    auto calc = [&](int x,int y,int k){
        int rx = min(x+k-1,n), ry = min(y+k-1,n);
        return v[rx][ry]-v[x-1][ry]-v[rx][y-1]+v[x-1][y-1];
    };
    For(k,1,n){
        int res = 0;
        for(int i = 1;i <= n;i += k){
            for(int j = 1;j <= n;j += k){
                if(calc(i,j,k) != 0) res ++;
            }
        }
        int tans = (k*k+1)*res;
        if(tans < ans) ans=tans, ansk=k;
    }
    cout << ansk << ' ' << ans;
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