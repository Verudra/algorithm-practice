#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
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
    string s; cin >> s;
    int len = s.size();
    s = " " + s;
    int n; cin >> n;
    // vector<string> v(n+1);
    map<string,bool>mp;
    vi dp(len);
    string t;
    dp[0] = 1;
    For(i,1,n) cin >> t, mp[t] = true;
    For(i,1,len){
        For(j,1,i){
            if(mp[s.substr(i-j+1,j)]) dp[i] = max(dp[i],dp[i-j]);
        }
    }
    if(dp[len]) cout << "Yes";
    else cout << "No";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}