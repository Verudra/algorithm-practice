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
    int n,k; cin >> n >> k;
    vi v(n);
    rep(i,n) cin >> v[i];
    int l = 0,r = -1;
    unordered_map<int,int>mp;
    int cnt = 0, ans = INF;
    while(r < n-1){
        r ++;
        cnt += mp[v[r]];
        mp[v[r]] ++;
        while(l <= r && cnt-mp[v[l]]+1 >= k){
            mp[v[l]] --;
            cnt -= mp[v[l]];
            l ++;
        }
        if(cnt >= k) ans = min(ans, r-l+1);
    }
    cout << (ans == INF?-1:ans);
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