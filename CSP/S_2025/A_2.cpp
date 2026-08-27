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
    int ans = 0;
    vi v1,v2,v3;
    rep(i,n){
        int a,b,c; cin >> a >> b >> c;
        int mx = max({a,b,c});
        ans += mx;
        if(mx == a) v1.push_back(mx-max(b,c));
        else if(mx == b) v2.push_back(mx-max(a,c));
        else v3.push_back(c-max(a,b));
    }
    auto fun = [=](vi v){
        sort(v.begin(),v.end());
        int res = 0;
        rep(i,v.size()-n/2) res += v[i];
        return res;
    };
    if(v1.size() > n/2) ans -= fun(v1);
    if(v2.size() > n/2) ans -= fun(v2);
    if(v3.size() > n/2) ans -= fun(v3);
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