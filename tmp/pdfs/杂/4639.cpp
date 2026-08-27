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
const int N = 305;
int dp[N][N];
void work(){
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    dp[0][0] = 1;
    For(i,1,n){
        For(j,0,n){
            if(s[i] == '(' || s[i] == '?'){
                if(j != 0) dp[i][j] += dp[i-1][j-1];
            }
            if(s[i] == ')' || s[i] == '?'){
                if(j != n) dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][0];
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