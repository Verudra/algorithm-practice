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
    vvi dp(s.size()+1,vi(s.size()+2));
    dp[0][0] = 1;
    For(i,1,s.size()){
        char c = s[i-1];
        For(j,0,s.size()){
            if((c == '(' || c == '?') && j > 0) dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
            if((c == ')' || c == '?') && j < s.size()) dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;
        }
    }
    cout << dp[s.size()][0];
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1; 
    while(T --) work();
    return 0;
}