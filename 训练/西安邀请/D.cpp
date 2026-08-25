#include<iostream>
#include<vector>
#include<stack>
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
#define vpii vector<pair<int,int> >
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n,m; cin >> n >> m;
    vi v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    int ans = 0, nt = 0, ncnt = 1;
    rep(i,n){
        int t = nt + max(0ll,(v[i]-ans+ncnt-1)/ncnt);
        if(m-t > v[i]){
            ans += ncnt*(t-nt);
            ans -= v[i];
            ncnt ++;
            nt = t;
        }
        else break;
    }
    ans += (m-nt)*ncnt;
    cout << ans << '\n';
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
