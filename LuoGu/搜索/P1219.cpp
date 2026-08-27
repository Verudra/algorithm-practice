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
const int N = 14;
int ans[N],n,cnt;
bool visx[N], visy[N], visl[N*2], visr[N*2];
void dfs(int u){
    if(u == n+1){
        cnt ++;
        if(cnt > 3) return ;
        For(i,1,n) cout << ans[i] << ' ';
        cout << '\n';
        return ;
    }
    For(i,1,n){
        if(!visy[i] && !visl[u-i+n] && !visr[i+u]){
            visy[i] = visl[u-i+n] = visr[i+u] = true;
            ans[u] = i;
            dfs(u+1);
            visy[i] = visl[u-i+n] = visr[i+u] = false;
        }
    }
    return ;
}
void work(){
    cin >> n;
    dfs(1);
    cout << cnt;
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