#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
void work(){
    int n;cin >> n;
    vi v(n+1);
    For(i,1,n) cin >> v[i];
    vi dp1(n+2), dp2(n+2);
    dp1[1] = v[1];
    For(i,2,n-1) dp1[i] = max(dp1[i-1],dp1[i-2]+v[i]);
    For(i,2,n) dp2[i] = max(dp2[i-1], dp2[i-2]+v[i]);
    cout << max(dp1[n-1], dp2[n]);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}